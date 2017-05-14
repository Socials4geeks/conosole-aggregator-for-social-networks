#include "interface_vk.h"

InterfaceVK::InterfaceVK(){

};

InterfaceVK::~InterfaceVK(){

};

int InterfaceVK::PrintMessages( std::vector<Message> data ){
    for (int i = 0 ; i < data.size(); i++) {
        
    }
    return 0;
};

int InterfaceVK::PrintWall( std::vector<Message> data ){
    std::cout << termcolor::on_red << "Ошибка:"
              << termcolor::reset << " Недоступно в данной версии." << endl;
    return 0;
};

int InterfaceVK::PrintFriends( std::map<std::string, std::string> data ){
    //TODO
    return 0;
};


