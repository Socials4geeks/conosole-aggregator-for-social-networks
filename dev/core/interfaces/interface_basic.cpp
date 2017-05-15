#include "interface_basic.h"

InterfaceBasic::InterfaceBasic(){

};

InterfaceBasic::~InterfaceBasic(){

};

void printLoginNecessity() {
    std::cout << termcolor::on_red << "Access violation:"
              << termcolor::reset << " Please, login. Print 'help' for help." << std::endl;
}

int InterfaceBasic::PrintMessages( std::vector<Message> data ){
    printLoginNecessity();
    return 1;
};

int InterfaceBasic::PrintWall( std::vector<WallEntry> data ){
    printLoginNecessity();
    return 1;
};

int InterfaceBasic::PrintFriends( std::vector<FriendEntry> data ){
    printLoginNecessity();
    return 1;
};


