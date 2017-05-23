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
    std::string current_word;
    in >> current_word;

    // if (current_word == "set_default_messenger") {
    //     if (current_word == "vk") {
    //         default_messenger = "vk";
    //         std::cout << termcolor::green << "Default messenger setted to vk" << termcolor::reset << std::endl;
    //     }
    //     else if (current_word == "telegram") {
    //         default_messenger = "telegram";
    //         std::cout << termcolor::green << "Default messenger setted to telegram" << termcolor::reset << std::endl;
    //     }
    //     else
    // }
    if (current_word == "vk" || current_word == "telegram") {
        std::map<std::string, std::string> request;
        request.insert(std::pair<std::string, std::string>("get", current_word));
        // Request r;
        // if (current_word == "vk")
        //     r.network_type = VK;
        // if (current_word == "telegram")
        //     r.network_type = TELEGRAM;

        in >> current_word;
    } else {
        std::cout << termcolor::red << "Syntax error." << termcolor::reset << " Type 'help' for help" << std::endl;
    }
}
