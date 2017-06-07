#include "interface_basic.h"

InterfaceBasic::InterfaceBasic(){

};

InterfaceBasic::~InterfaceBasic(){

};

void printLoginNecessity() {
    std::cout << termcolor::on_red << "Access violation:"
              << termcolor::reset << " Please, login. Print 'help' for help." << std::endl;
}

Status InterfaceBasic::PrintMessages( Response data ) {
    printLoginNecessity();
    return OK;
};

Status InterfaceBasic::PrintWall( Response data ) {
    printLoginNecessity();
    return OK;
};

Status InterfaceBasic::PrintFriends( Response data ) {
    printLoginNecessity();
    return OK;
};

Status InterfaceBasic::PrintURL( Response data ) {
    std::wcout << termcolor::green << L"To authenticate, plase go to link: "
              << termcolor::reset << data.Params[0]["url"] << std::endl;
    return OK;
}
