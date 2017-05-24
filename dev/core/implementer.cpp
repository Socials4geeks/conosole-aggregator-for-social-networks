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

    if ( request.params["socialnetworkname"] == "") {
        if( False ) { //TODO: if request.action in allowed actions of basic functions
            basicFunctional( request );
        }
    }else {
        if (apiInterface.find( request.params[ "socialnetwork" ] ) != apiInterface.end() ) {
            APIInterface curApiInterface = apiInterface[ request.params["socialnetwork"] ];
            authInfo loginPassword = std::make_pair( request.params[ "RemoteLogin" ], request.params[ "RemotePassword" ] );
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
                    
                    curApiInterface.SendMessage( loginPassword, request.params[ "topic" ], request.params[ "text" ], request.params[ "recipient" ], newResponse ) //TODO: Analyse return code
                    break;
                };

                case (ADD_WALL):{
                    
                    curApiInterface.AddWall( loginPassword, request.params[ "text" ], newResponse ) //TODO: Analyse return code
                    break;
                };


                case (ADD_FRIEND):{
                    
                    curApiInterface.AddFriend( loginPassword, request.params[ "friend" ], newResponse ) //TODO: Analyse return code
                    break;
                };

                case (REMOVE_FRIEND):{
                    
                    curApiInterface.RemoveFriend( loginPassword, request.params[ "friend" ], newResponse ) //TODO: Analyse return code
                    break;
                };


            }
        }
    
    }           
}


