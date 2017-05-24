#include "core/implementer.h"

Implementer::Implementer() {
    //TODO Push to vector all our SN interfaces
}

Implementer::~Implementer() {

}

Response Implementer::ExecuteRequest( Request request ) {  //Split on basic functional and API
    Response newResponse;
    newResponse.IdOfRemoteAccount = request.IdOfRemoteAccount;
    newResponse.Type = ERROR;

    if ( request.params["socialnetworkname"] == "") {
        if( False ) { //if request.action in allowed actions of basic functions
            basicFunctional( request );
        }
    }else {
        if (apiInterface.find( request.params[ "socialnetwork" ] ) != apiInterface.end() ) {
            APIInterface curApiInterface = apiInterface[ request.params["socialnetwork"] ];
            authInfo loginPassword = std::make_pair( request.params[ "RemoteLogin" ], request.params[ "RemotePassword" ] );
            switch ( request.action ){
                case (SHOW_MESSAGES):{
                    curApiInterface.ShowMessages( loginPassword, newResponse ) //Analyse return code
                    break;
                };
                  
                case (SHOW_FRIENDS):{
                    curApiInterface.ShowFriends( loginPassword, newResponse ) //Analyse return code
                    break;
                };

                case (SHOW_WALL):{
                    
                    curApiInterface.ShowMessages( loginPassword, newResponse ) //Analyse return code
                    break;
                };

                case (SEND_MESSAGE):{
                    
                    curApiInterface.ShowMessages( loginPassword, request.params[ "topic" ], request.params[ "text" ], request.params[ "recipient" ], newResponse ) //Analyse return code
                    break;
                };

                case (ADD_WALL):{
                    
                    curApiInterface.ShowMessages( loginPassword, request.params[ "text" ], newResponse ) //Analyse return code
                    break;
                };


                case (ADD_FRIEND):{
                    
                    curApiInterface.ShowMessages( loginPassword, request.params[ "friend" ], newResponse ) //Analyse return code
                    break;
                };

                case (REMOVE_FRIEND):{
                    
                    curApiInterface.ShowMessages( loginPassword, request.params[ "friend" ], newResponse ) //Analyse return code
                    break;
                };


            }
        }
    
    }           
}


