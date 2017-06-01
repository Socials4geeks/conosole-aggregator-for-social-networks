#include "implementer.h"

Implementer::Implementer() {
    //TODO: Push to vector all our SN interfaces
}

Implementer::~Implementer() {

}

Response Implementer::ExecuteRequest( Request request ) {  //TODO: Split on basic functional and API
    Response newResponse;
    newResponse.IdOfRemoteAccount = request.IdOfRemoteAccount;
    newResponse.Type = ERROR;
    if ( request.Params["SOCIAL_NETWORK_NAME"] == L"") {
        if( false ) { //TODO: if request.action in allowed actions of basic functions
            basicFunctional.Hello();
        }
    }else {
        if (apiInterfaces.find( request.Params[ "SOCIAL_NETWORK_NAME" ] ) != apiInterfaces.end() ) {
            APIInterface* curApiInterface = apiInterfaces[ request.Params["SOCIAL_NETWORK_NAME"] ];
            authInfo loginPassword = std::make_pair( request.Params[ "REMOTE_LOGIN" ], request.Params[ "REMOTE_PASSWORD" ] );
            switch ( request.Action ){
                case (SHOW_MESSAGES):{
                    curApiInterface->ShowMessages( loginPassword, newResponse ); //TODO: Analyse return code
                    break;
                };
                  
                case (SHOW_FRIENDS):{
                    curApiInterface->GetFriends( loginPassword, newResponse ); //TODO: Analyse return code
                    break;
                };

                case (SHOW_WALL):{
                    curApiInterface->GetWall( loginPassword, newResponse ); //TODO: Analyse return code
                    break;
                };

                case (SEND_MESSAGE):{
                    curApiInterface->SendMessage( loginPassword, request.Params[ "TOPIC" ], request.Params[ "TEXT" ], request.Params[ "RECIPIENT" ], newResponse ); //TODO: Analyse return code
                    break;
                };

                case (ADD_WALL):{
                    curApiInterface->AddWall( loginPassword, request.Params[ "TEXT" ], newResponse ); //TODO: Analyse return code
                    break;
                };


                case (ADD_FRIEND):{
                    curApiInterface->AddFriend( loginPassword, request.Params[ "FRIEND" ], newResponse ); //TODO: Analyse return code
                    break;
                };

                case (REMOVE_FRIEND):{
                    curApiInterface->RemoveFriend( loginPassword, request.Params[ "FRIEND" ], newResponse ); //TODO: Analyse return code
                    break;
                };
            }
        }
    }           
}

