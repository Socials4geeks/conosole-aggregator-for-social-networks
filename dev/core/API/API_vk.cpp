#include <algorithm>
#include <ctime>
#include <string>
#include <vector>

/*
#include <boost/format.hpp>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <cpprest/uri.h>
#include <cpprest/uri_builder.h>

#include "API_vk.h"
#include "constants.h"
#include "types.h"

using namespace boost;

/// Casablanca namespaces
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

int API_vk::Authorize( authInfo loginPassword ) {
    ProfileInfo user = getProfileInfo();

    if( IsAuthorized( user.uid ) == OK ) {
        return user.uid;
    }

    std::string auth_uri = str( format(httpFormatString) % "https" % "oauth.vk.com/authorize" );
    UrlParams auth_params = {
        {"client_id", VK_APP_ID},
        {"display", "page"},
        {"scope", "friends"},
        {"response_type", "token"},
        {"state", STATE},
        {"v", VERSION},
    };

    std::string result;
    std::for_each( auth_params.begin(), auth_params.end(), [&auth_uri, &result]( std::pair<std::string, std::string> param ) {
        result += str( format(httpGetParams) % param.first % param.second );
    });

// TODO: посылать POST запрос с данными авторизации
    TemporaryBrowserAuthorization exception( tokens[cur_uid] );
    exception.authorization_url = auth_uri;
    throw exception;
// ENDTODO

    cur_uid = user.uid;
    TokenInfo cur_token = tokens[cur_uid];

    time_t now;
    time( &now );
    cur_token.first = cur_token.first + now;
    tokens[cur_uid] = cur_token;

    return user.uid;
}

Status API_vk::IsAuthorized( int uid ) {
    return ( uid == cur_uid ) ? OK : UNKNOWN_ERROR;  // TODO: check, if access_token is leaked
}

ProfileInfo API_vk::getProfileInfo() {
    uri_builder request_uri = buildApiUrl( std::string("account.getProfileInfo"), {}, true );

    ProfileInfo user;

    http_client client( request_uri.to_uri() );
    http_request request( methods::GET );
    client.request( request ).then([]( http_response response ) {
        if(response.status_code() == OK) {
            return response.extract_json();
        } else {
            throw UnknownError();
        }
    }).then([&user, this](json::value val) {
        json::value resp = val["response"];
            user.uid = cur_uid;
            user.first_name = val["first_name"].as_string();
            user.last_name = val["last_name"].as_string();
            user.screen_name = val["screen_name"].as_string();
            user.sex = static_cast<Sex>( val["sex"].as_integer() );
            user.home_town = val["home_town"].as_string();
            user.country = val["country"].as_string();
            user.city = val["city"].as_string();
            user.status = val["status"].as_string();
            user.phone = val["phone"].as_string();
    }, pplx::task_continuation_context::use_default());

    return user;
};

Status API_vk::SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient ) {
    uri_builder request_uri = buildApiUrl( std::string("messages.send"), {}, true );

    http_client client( request_uri.to_uri() );
    http_request request( methods::GET );
    client.request( request ).then([]( http_response response ) {
        if(response.status_code() == OK) {
            return OK;
        } else {
            return UNKNOWN_ERROR;
        }
    });
}

std::vector<Message> API_vk::GetLastMessages( int uid ) {
    uri_builder request_uri = buildApiUrl( "messages.get", {}, true );

    std::vector<Message> messages;

    http_client client( request_uri.to_uri() );
    http_request request( methods::GET );
    client.request( request ).then([]( http_response response ) {
        if(response.status_code() == OK) {
            return response.extract_json();
        } else {
            return pplx::task<json::value>();
        }
    }).then([&messages]( json::value val ) {
        if( val.is_null() ) {
            return;
        }

        json::array resp = val["response"].as_array();
        std::for_each( resp.begin() + 1, resp.end(), [&messages]( json::value val ) {
            Message msg;
            msg.mid = val["mid"].as_integer();
            msg.date = val["date"].as_integer();
            msg.out = val["out"].as_bool();
            msg.uid = val["uid"].as_integer();
            msg.read_state = val["read_state"].as_bool();
            msg.title = val["title"].as_string();
            msg.body = val["body"].as_string();

            messages.push_back(msg);
        });
    }, pplx::task_continuation_context::use_default());

    return messages;
}

uri_builder API_vk::buildApiUrl( std::string method, UrlParams uri_params, bool is_private ) {
    uri_builder result( str( format( httpFormatString ) % (is_private ? "https" : "http") ) + "api.vk.com/method");
    result.append_path(method);

    std::for_each( uri_params.begin(), uri_params.end(), [&result]( std::pair<std::string, std::string> param ) {
        result.append_query( param.first, param.second );
    });

    if( is_private ) {
        result.append_query( "access_token", VK_APP_ID );
    }
    result.append_query( "v", VERSION );

    return result;
}*/
