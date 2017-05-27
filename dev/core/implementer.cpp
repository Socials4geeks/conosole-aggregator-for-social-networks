#include "core/implementer.h"

Implementer::Implementer() {
    //TODO: Push to vector all our SN interfaces
}

Implementer::~Implementer() {

}

Response Implementer::ExecuteRequest( Request request ) {  //TODO: Split on basic functional and API
    Response newResponse;
    newResponse.IdOfRemoteAccount = request.IdOfRemoteAccount;
    newResponse.Type = ERROR;
    if ( request.params["SOCIAL_NETWORK_NAME"] == "") {
        if( False ) { //TODO: if request.action in allowed actions of basic functions
            basicFunctional( request );
        }
    }else {
        if (apiInterface.find( request.params[ "SOCIAL_NETWORK_NAME" ] ) != apiInterface.end() ) {
            APIInterface curApiInterface = apiInterface[ request.params["SOCIAL_NETWORK_NAME"] ];
            authInfo loginPassword = std::make_pair( request.params[ "REMOTE_LOGIN" ], request.params[ "REMOTE_LOGIN" ] );
            switch ( request.action ){
                case (SHOW_MESSAGES):{
                    curApiInterface.ShowMessages( loginPassword, newResponse ) //TODO: Analyse return code
                    break;
                };
                  
                case (SHOW_FRIENDS):{
                    curApiInterface.ShowFriends( loginPassword, newResponse ) //TODO: Analyse return code
                    break;
                };

                case (SHOW_WALL):{
                    curApiInterface.ShowWall( loginPassword, newResponse ) //TODO: Analyse return code
                    break;
                };

                case (SEND_MESSAGE):{
                    curApiInterface.SendMessage( loginPassword, request.params[ "TOPIC" ], request.params[ "TEXT" ], request.params[ "RECIPIENT" ], newResponse ) //TODO: Analyse return code
                    break;
                };

                case (ADD_WALL):{
                    curApiInterface.AddWall( loginPassword, request.params[ "TEXT" ], newResponse ) //TODO: Analyse return code
                    break;
                };


                case (ADD_FRIEND):{
                    
                    curApiInterface.AddFriend( loginPassword, request.params[ "FRIEND" ], newResponse ) //TODO: Analyse return code
                    break;
                };

                case (REMOVE_FRIEND):{
                    
                    curApiInterface.RemoveFriend( loginPassword, request.params[ "FRIEND" ], newResponse ) //TODO: Analyse return code
                    break;
                };
            }
        }
    }           
}

