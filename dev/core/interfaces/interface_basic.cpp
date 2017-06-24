#include "interface_basic.h"

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
    std::cout << termcolor::on_red << "Error:"
              << termcolor::reset << " " << data.Params[0]["reason"] << std::endl;
    return OK;
};

