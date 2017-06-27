#include <string>
#include <sstream>
#include <iostream>
#include <map>

#include "termcolor.h"
#include "interfaces.h"
#include "types.h"

Interface::Interface() {
    //TODO
}

Interface::~Interface() {
    //TODO
}

Request Interface::Input() {
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
        request.IdOfRemoteAccount = (std::string) account;
        request.Action = string_to_action(command);
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

Status Interface::PrintHello() {
    std::cout << "Hi" << std::endl;
    return OK;
}

std::vector<std::string> Interface::split_to_tokens(std::string command) {
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

TypeOfAction Interface::string_to_action(std::string str) {
    if (str == "new_local_account")
        return NEW_LOCAL_ACCOUNT;
    else if (str == "login_local_account")
        return LOGIN_LOCAL_ACCOUNT;
    else if (str == "show_messages")
        return SHOW_MESSAGES;
    else if (str == "show_friends")
        return SHOW_FRIENDS;
    else if (str == "add_wall")
        return ADD_WALL;
    else if (str == "add_friend")
        return ADD_FRIEND;
    else if (str == "remove_friend")
        return REMOVE_FRIEND;
    else
        return UNKNOWN;
}

params Interface::split_to_kwargs(std::vector<std::string>& args) {
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

