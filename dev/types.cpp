#include "types.h"

Request::Request() {
    Action = UNKNOWN;
}

Response::Response() {
    Type = ERROR;
}

TemporaryBrowserAuthorization::TemporaryBrowserAuthorization( TokenInfo& access_token ) : access_token(access_token) {};
