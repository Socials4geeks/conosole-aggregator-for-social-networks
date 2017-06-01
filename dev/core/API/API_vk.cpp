#include <algorithm>
#include <ctime>
#include <string>
#include <vector>

#include <boost/format.hpp>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <cpprest/uri.h>
#include <cpprest/uribuilder.h>

#include "core/API/API_vk.h"
#include "constats.h"
#include "types.h"

using namespace boost;

/// Casablanca namespaces
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

int API_vk::Authorize( AuthInfo loginPassword ) {
    ProfileInfo user = getProfileInfo();

    if( IsAuthorised == status::OK ) {
        return user.uid;
    }

    std::wstiring auth_uri = wformat(httpFormatString) % "https" % "oauth.vk.com/authorize";
    UrlParams auth_params = {
        {"client_id", VK_APP_ID},
        {"display", "page"},
        {"scope", "friends"},
        {"response_type", "token"},
        {"state", STATE},
        {"v", VERSION},
    };

    std::for_each( auth_params.begin(), auth_params.end(), [&auth_uri]( std::pair<std::wstring, std::wstring> param ) {
        result += wformat(httpGetParams) % param.first % param.second;
    });

// TODO: посылать POST запрос с данными авторизации
    TemporaryBrowserAuthorisation exception( cur_access_token );
    exception.authorisation_uri = auth_uri;
    throw exception;
// ENDTODO

    cur_uid = user.uid;
    TokenInfo cur_token = tokens[cur_uid];

    time_t now;
    time( now );
    cur_token.first = cur_token.first + now;
    tokens[cur_uid] = cur_token;

    return user.id;
}

Status API_vk::IsAuthorized( int uid ) {
    return if( tokens[uid].second == cur_access_token ) ? status::OK : status::ERROR;  // TODO: check, if access_token is leaked
}

ProfileInfo API_vk::getProfileInfo() {
    std::wstring request_uri = buildApiUrl( std::wstring("account.getProfileInfo"), {}, true );

    ProfileInfo user;

    http_client client( request_uri );
    http_request request( methods::GET );
    client.request( request ).then([]( http_response response ) {
        if(response.status_code() == status_codes::OK) {
            return response.extract_json();
        } else {
            throw UnknownError();
        }
    }).then([&user](json::value val) {
        json::value resp = val[L"response"];
            user.uid = cur_uid;
            user.first_name = val[L"first_name"].as_string();
            user.last_name = val[L"last_name"].as_string();
            user.screen_name = val[L"screen_name"].as_string();
            user.sex = val[L"sex"].as_integer();
            user.home_town = val[L"home_town"].as_string();
            user.country = val[L"country"].as_string();
            user.city = val[L"city"].as_string();
            user.status = val[L"status"].as_string();
            user.phone = val[L"phone"].as_string();
    }, task_continuation_context::use_current());

    return user;
};

Status API_vk::SendMessage( authInfo loginPassword, std::wstring topic, std::wstring text, std::wstring recipient ) {
    std::wstring request_uri = buildApiUrl( std::wstring("messages.send"), {}, true );

    http_client client( request_uri );
    http_request request( methods::GET );
    return client.request( request ).then([]( http_response response ) {
        if(response.status_code() == status_codes::OK) {
            return Status::OK;
        } else {
            return Status::ERROR;
        }
    });
}

std::vector<Message> API_vk::GetLastMessages( int uid ) {
    uri_builder request_uri = buildApiUrl( L"messages.get", {}, true );

    std::vector<Message> messages;

    http_client client( request_uri.to_uri() );
    http_request request( methods::GET );
    client.request( request ).then([]( http_response response ) {
        if(response.status_code() == status_codes::OK) {
            return response.extract_json();
        } else {
            return json::value();
        }
    }).then([&messages]( json::value value ) {
        if( val.is_null() ) {
            return;
        }

        json::array resp = value[L"response"].as_array();
        std::for_each( resp.begin() + 1, resp.end(), [&messages]( json::value val ) {
            Message msg;
            msg.mid = val[L"mid"].as_integer();
            msg.date = val[L"date"].as_integer();
            msg.out = val[L"out"].as_bool();
            msg.uid = val[L"uid"].as_integer();
            msg.read_state = val[L"read_state"].as_bool();
            msg.title = val[L"title"].as_string();
            msg.body = val[L"body"].as_string();

            messages.push_back(msg);
        });
    }, task_continuation_context::use_current());

    return messages;
}

uri_builder API_vk::buildApiUrl( std::wstring method, UrlParams uri_params, bool is_private ) {
    uri_builder result( wformat( httpFormatString ) % (is_private ? L"https" : L"http") + L"api.vk.com/method");
    result.append_path(method);

    std::for_each( uri_params.begin(), uri_params.end(), [&result]( std::pair<std::wstirng, std::wstring> param ) {
        result.append_query( param.first, param.second );
    });

    if( is_private ) {
        result.append_query( L"access_token", VK_APP_ID );
    }
    result.append_query( L"v", VERSION );

    return result;
}
