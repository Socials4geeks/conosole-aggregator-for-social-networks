#include "interface_vk.h"

InterfaceVK::InterfaceVK(){

};

InterfaceVK::~InterfaceVK(){

};

int InterfaceVK::PrintMessages( std::vector<Message> data ){
    for (int i = 0 ; i < data.size(); i++) {
        std::cout << termcolor::reset << "[" << data[i].datetime << "] "
                  << termcolor::colorizeStringByHash(data[i].username) << termcolor::reset << ": ";
        if (data[i].title != "") {
            std::cout << termcolor::bold << data[i].title << termcolor::reset << std::endl;
        }
        std::cout << data[i].body << std::endl;
    }
    return 0;
};

int InterfaceVK::PrintWall( std::vector<WallEntry> data ){
    std::cout << termcolor::on_red << "Ошибка:"
              << termcolor::reset << " Недоступно в данной версии." << std::endl;
    return 0;
};

int InterfaceVK::PrintFriends( std::vector<FriendEntry> data ){
    //TODO
    return 0;
};

int main() {
    Message m;
    m.username = "Имя пользователя";
    m.datetime = "16:30";
    m.title = "";
    m.body = "Hello, world";
    InterfaceVK ivk;
    std::vector<Message> v;
    v.push_back(m);
    v.push_back(m);
    v.push_back(m);
    v.push_back(m);
    ivk.PrintMessages(v);
}
