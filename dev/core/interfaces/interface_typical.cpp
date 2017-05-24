#include "core/interfaces/interface_typical.h"
#include "types.h"
#include "core/interfaces/interfaces.h"
#include <stdexcept>


InterfaceTypical::InterfaceTypical() {

}


InterfaceTypical::~InterfaceTypical() {

}

int InterfaceTypical::PrintWall( params data ) {

}

int InterfaceTypical::PrintFriends( params data ) {

}

int InterfaceTypical::PrintMessages( params data ) {
    if (data.Type == typeOfResponse.ERROR) {
        std::string reason = data[0].at("reason");
        std::cout << termcolor::red << reason << termcolor::reset << " Type 'help' for help" << std::endl;

    }
    for (int i = 0 ; i < data.size(); i++) {
        std::cout << termcolor::reset << "[" << data[i].at("datetime") << "] "
                  << termcolor::colorizeStringByHash(data[i].at("username")) << termcolor::reset << ": ";
        if (data[i].at("title") != "") {
            std::cout << termcolor::bold << data[i].at("title") << termcolor::reset << std::endl;
        }
        std::cout << data[i].at("body") << std::endl;
    }
    return 0;
};

int InterfaceTypical::PrintWall( params data ){
    std::cout << termcolor::on_red << "Access violation:"
              << termcolor::reset << " Unavailable in current version." << std::endl;
    return 0;
};


int InterfaceTypical::PrintFriends( params data ){
    std::sort(data.begin(), data.end(), 
              [](const FriendEntry & a, const FriendEntry & b) -> bool { 
                  return (a.isOnline > b.isOnline);
              });

//     for (int i = 0; i < data.size(); i++) {
//         if (data[i].isOnline) {
//             std::cout << termcolor::green << data[i].username << termcolor::reset << ": online" << std::endl;
//         } else {
//             std::cout << termcolor::red << data[i].username << termcolor::reset << ": " << data[i].lastEnter << std::endl;
//         }
//     }

//     return 0;
// };


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


std::vector<std::string> split_to_tokens(std::string command){
    std::vector<std::string> qargs;
    int len = command.length();
    bool qot = false, sqot = false;
    int arglen;
    for (int i = 0; i < len; i++) {
        int start = i;
        if(command[i] == '\"')
            qot = true;
        else if (command[i] == '\'')
            sqot = true;
        else if (command[i] == ' ')
            ;
        if (qot) {
            i++;
            start++;
            while (i < len && command[i] != '\"')
                i++;
            if (i < len)
                qot = false;
            arglen = i - start;
            i++;
        } else if (sqot) {
            i++;
            while (i < len && command[i] != '\'')
                i++;
            if (i < len)
                sqot = false;
            arglen = i - start;
            i++;
        } else {
            while (i < len && command[i] != ' ')
                i++;
            arglen = i - start;
        }
        qargs.push_back(command.substr(start, arglen));
    }
    if (qot || sqot)
        throw std::invalid_argument( "Invalid syntax, quotes must be closed." );
    return qargs;
}


params split_to_kwargs(std::vector<std::string>& args) {
    std::map<std::string, std::string> kwargs;
    for (int i = 0; i < args.size(); i++) {
        if (args[i][0] == '-') {
            if (i + 1 < args.size() || args[i + 1][0] != '-') {
                kwargs[args[i]] = args[i + 1];
            } else {
                kwargs[args[i]] = '\0';
            }
        }
    }
    return kwargs;
}


Request InterfaceTypical::Input() {
    std::string line;
    std::string account, command;
    Request request;
    while (true) {
        std::getline(std::cin, line);

        std::istringstream in(line);
        in >> account;
        in >> command;
        if (account == "" || command == "") {
            std::cout << termcolor::red << "Syntax error." << termcolor::reset << " Type 'help' for help" << std::endl;
            continue;
        }
        request.IdOfRemoteAccount = account;
        request.Action = command;
        if (in.peek() == EOF) {
            break;
        } else {
            std::string args_str;
            std::getline(in, args_str);
            auto args_vec = split_to_tokens(args_str);
            std::map<std::string, std::string> kwargs = split_to_kwargs(args_vec);
            request.Params = kwargs;
            break;
        }
    }
    return request;
}