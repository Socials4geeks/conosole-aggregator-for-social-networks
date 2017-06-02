#include "core/interfaces/interface_basic.h"

InterfaceBasic::InterfaceBasic(){

};

InterfaceBasic::~InterfaceBasic(){

};

void printLoginNecessity() {
    std::cout << termcolor::on_red << "Access violation:"
              << termcolor::reset << " Please, login. Print 'help' for help." << std::endl;
}

virtual Status InterfaceBasic::PrintMessages( Response data ) {
    printLoginNecessity();
    return 1;
};

virtual Status InterfaceBasic::PrintWall( Response data ) {
    printLoginNecessity();
    return 1;
};

virtual Status InterfaceBasic::PrintFriends( Response data ) {
    printLoginNecessity();
    return 1;
};

virtual Status InterfaceBasic::PrintURL( Response data ) {
    std::cout << termcolor::green "To authenticate, plase go to link: "
              << termcolor::reset << data.Params[0]["url"] << std::endl;
}
