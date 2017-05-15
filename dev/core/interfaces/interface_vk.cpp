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
    std::cout << termcolor::on_red << "Access violation:"
              << termcolor::reset << " Unavailable in current version." << std::endl;
    return 0;
};

int InterfaceVK::PrintFriends( std::vector<FriendEntry> data ){
    std::sort(data.begin(), data.end(), 
              [](const FriendEntry & a, const FriendEntry & b) -> bool { 
                  return (a.isOnline > b.isOnline);
              });

    for (int i = 0; i < data.size(); i++) {
        if (data[i].isOnline) {
            std::cout << termcolor::green << data[i].username << termcolor::reset << ": online" << std::endl;
        } else {
            std::cout << termcolor::red << data[i].username << termcolor::reset << ": " << data[i].lastEnter << std::endl;
        }
    }

    return 0;
};

std::map<std::string, std::string> InterfaceVK::Input() {
    std::string input;
    std::cin >> input;
    std::istringstream in(input);
    std::string currentWord;
    in >> currentWord;

    if (currentWord == "set_default_messenger")
}
