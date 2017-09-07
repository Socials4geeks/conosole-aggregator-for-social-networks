#include "interface_basic.h"
#include "types.h"

InterfaceBasic::InterfaceBasic(){

};

InterfaceBasic::~InterfaceBasic(){

};


Status InterfaceBasic::PrintMessages( Response data ) {
    PrintURL( data );
    return OK;
};


Status InterfaceBasic::PrintWall( Response data ) {
    PrintURL( data );
    return OK;
};


Status InterfaceBasic::PrintFriends( Response data ) {
    PrintURL( data );
    return OK;
};


Status InterfaceBasic::PrintURL( Response data ) {
    std::cout << termcolor::green << "To authenticate, plase go to link: "
              << termcolor::reset << data.Params[0]["url"] << std::endl;
    return OK;
}


Status InterfaceBasic::PrintError( Response data ) {
    if (data.Type == ERROR) {
        std::cout << termcolor::on_red << "Error:"
                  << termcolor::reset << " " << data.Params[0]["reason"] << std::endl;
    }
    if (data.Type == ACCEPT) {
        std::cout << termcolor::green << "Access."
          << termcolor::reset << std::endl;

    }
    return OK;
};


