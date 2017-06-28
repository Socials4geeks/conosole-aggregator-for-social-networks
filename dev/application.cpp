#include "application.h"
#include "interfaces.h"
#include "interface_basic.h"
#include "interface_vk.h"

Application::Application(){
    ui.push_back( new InterfaceBasic() );
    curUi = ui[0]; //TODO: Replace to anything better
    Interface::PrintHello();
    Request request = curUi->Input();
    executeRequest( request );
}

Application::~Application(){
    for( auto i : ui ) {
        delete i;
    }
}

void Application::executeRequest( Request request ) {
    output( core.ExecuteRequest( request ) );
}

void Application::output( Response response ) {
    if( response.Params[ 0 ][ "SOCIAL_NETWORK_NAME" ] == "vk") {
       //TODO:
       if( curUi->name_of_social_network != "vk" ) {
           bool found = false;
           for ( size_t i = 0; i < ui.size() && !found; ++i ) {
               if( ui[ i ]->name_of_social_network == "vk" ) {
                   curUi = ui[ i ];
                   found = true;
               };
           };
           if( !found ) {
               ui.push_back( new InterfaceVK() );
               curUi = ui[ ui.size() - 1 ];
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
    } else if( response.Params[ 0 ][ "SOCIAL_NETWORK_NAME" ] == "local" ) {
        curUi = ui[0];
        curUi->PrintError( response ); //TODO: PrintAccept
    } else {
        curUi = ui[0];
        curUi->PrintError( response );
    }
        
    Request request = curUi->Input();
    executeRequest( request );
}
