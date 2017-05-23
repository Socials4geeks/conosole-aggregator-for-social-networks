#include "core/interfaces/interface_typical.h"
#include "core/request.h"
#include "core/interfaces/interfaces.h"

InterfaceTypical::InterfaceTypical() {

};


InterfaceTypical::~InterfaceTypical() {

};


int InterfaceTypical::PrintMessages( std::vector<std::map<std::string, std::string>> data ) {
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

int InterfaceTypical::PrintWall( std::vector<std::map<std::string, std::string>> data ){
    std::cout << termcolor::on_red << "Access violation:"
              << termcolor::reset << " Unavailable in current version." << std::endl;
    return 0;
};


int InterfaceTypical::PrintFriends( std::vector<std::map<std::string, std::string>> data ){
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


template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


Request InterfaceTypical::Input() {
    std::string input;
    std::string account, command;
    while(true) {
        std::getline(std::cin, input);

        std::istringstream in(input);
        in >> account;
        in >> command;
        // Request request;
        // request.account = account;
        // request.command = command;
        if (account == "" || command == "") {
            std::cout << termcolor::red << "Syntax error." << termcolor::reset << " Type 'help' for help" << std::endl;
            continue;
        }

        std::cout << account << std::endl;
        std::cout << command;
    }

    // std::string current_word;
    // in >> current_word;
    // while (in>>current_word)
        // std::cout << current_word;

    // if (current_word == "set_default_messenger") {
    //     if (current_word == "Typical") {
    //         default_messenger = "Typical";
    //         std::cout << termcolor::green << "Default messenger setted to Typical" << termcolor::reset << std::endl;
    //     }
    //     else if (current_word == "telegram") {
    //         default_messenger = "telegram";
    //         std::cout << termcolor::green << "Default messenger setted to telegram" << termcolor::reset << std::endl;
    //     }
    //     else
    // }
    // if (current_word == "Typical" || current_word == "telegram") {

    //     in >> current_word;
    // } else {
    //     // std::cout << termcolor::red << "Syntax error." << termcolor::reset << " Type 'help' for help" << std::endl;
    // }

    return Request();
}