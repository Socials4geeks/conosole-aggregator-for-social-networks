#include "application.h"
#include "interface_basic.h"
#include "interface_vk.h"

Application::Application(){
    ui.push_back(InterfaceBasic());
    curUi = &ui[0]; //TODO: Replace to anything better
    curUi->Hello();
    Request request = curUi->Input();
    ExecuteRequest( request );
}

Application::~Application(){
    //TODO Implement this method
}

void Application::executeRequest( Request request ) {
    output( core.ExecuteRequest( request ) );

void Application::output( Response response ) {
    switch( response.Params[ 0 ][ "SOCIAL_NETWORK_NAME" ]  ) {
        case "vk":
            //TODO:
            if( curUi->name_of_social_network != "vk" ) {
                for ( size_t i = 0; i < ui.size() && !found; ++i ) {
                    bool found = false;
                    if( ui[ i ].name_of_social_network == "vk" ) {
                        curUi = &ui[ i ];
                        found = true;
                    };
                };
                if( !found ) {
                    ui.push_back( InterfaceVK() );
                    curUi = &ui[ ui.size() - 1 ];
                };
            };
            switch( response.Type ) {
                case MESSAGES:
                    curUi->PrintMessages( response );
                    break;
                case WALL:   
                    curUi->PrintWall( response );
                    break;
                case FRIENDS:
                    curUi->PrintMessages( response );
                    break;
                default:
                    curUi->PrintError( response );
                    break;
            } 
            break;
         default:
             curUi = &ui[0];
             curUi->PrintError( response );
             break;
    }
        
    Request request = curUi->Input();
    executeRequest( request );



