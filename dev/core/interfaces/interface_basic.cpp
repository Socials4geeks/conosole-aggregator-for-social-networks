#include "interface_basic.h"

InterfaceBasic::InterfaceBasic(){

};

InterfaceBasic::~InterfaceBasic(){

};

void printLoginNecessity() {
    std::cout << termcolor::on_red << "Ошибка доступа:"
              << termcolor::reset << " Пожалуйста, авторизуйтесь." << std::endl;
}

int InterfaceBasic::PrintMessages( std::vector<Message> data ){
    printLoginNecessity();
    return 1;
};

int InterfaceBasic::PrintWall( std::vector<Message> data ){
    printLoginNecessity();
    return 1;
};

int InterfaceBasic::PrintFriends( std::vector<Message> data ){
    printLoginNecessity();
    return 1;
};


