#include <stdexcept>

#include "interface_typical.h"
#include "types.h"
#include "interfaces.h"

InterfaceTypical::InterfaceTypical() {}

InterfaceTypical::~InterfaceTypical() {

}

Status InterfaceTypical::PrintMessages( Response data ) {
    if (data.Type == ERROR) {
        std::wstring reason = data.Params[0].at("reason");
        std::wcout << termcolor::red << reason << termcolor::reset << std::endl;

    }
    for (int i = 0 ; i < data.Params.size(); i++) {
        std::wcout << termcolor::reset << L"[" << data.Params[i]["datetime"] << L"] "
                   << termcolor::colorizewstringByHash(data.Params[i]["username"]) << termcolor::reset << L": ";
        if (data.Params[i]["title"] != "") {
            std::wcout << termcolor::bold << data.Params[i]["title"] << termcolor::reset << std::endl;
        }
        std::wcout << data.Params[i]["body"] << std::endl;
    }
    return OK;
};

Status InterfaceTypical::PrintWall( Response data ) {
    std::wcout << termcolor::on_red << L"Access violation:"
              << termcolor::reset << L" Unavailable in current version." << std::endl;
    return OK;
};

Status InterfaceTypical::PrintFriends( Response data ) {
    std::sort(data.Params.begin(), data.Params.end(), 
              [](params & a, params & b) -> bool { 
                  return (a["is_online"] > b["is_online"]);
              });

    for (int i = 0; i < data.Params.size(); i++) {
        if (data[i].Params["is_online"]) {
            std::wcout << termcolor::green << data[i].Params["username"] << termcolor::reset << L": online" << std::endl;
        } else {
            std::wcout << termcolor::red << data[i].Params["username"] << termcolor::reset
                      << L": " << data[i].Params["last_enter"] << std::endl;
        }
    }

    return OK;
};

template<typename Out>
void InterfaceTypical::split(const std::wstring &s, char delim, Out result) {
    std::wstringstream ss;
    ss.str(s);
    std::wstring item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::wstring> InterfaceTypical::split(const std::wstring &s, char delim) {
    std::vector<std::wstring> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

std::vector<std::wstring> InterfaceTypical::split_to_tokens(std::wstring command) {
    std::vector<std::wstring> qargs;
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

params InterfaceTypical::split_to_kwargs(std::vector<std::wstring>& args) {
    std::map<std::string, std::wstring> kwargs;
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

TypeOfAction wstring_to_action(std::wstring wstr) {
    if (wstr == L"new_local_account")
        return NEW_LOCAL_ACCOUNT;
    else if (wstr == L"login_local_account")
        return LOGIN_LOCAL_ACCOUNT;
    else if (wstr == L"show_messages")
        return SHOW_MESSAGES;
    else if (wstr == L"show_friends")
        return SHOW_FRIENDS;
    else if (wstr == L"add_wall")
        return ADD_WALL;
    else if (wstr == L"add_friend")
        return ADD_FRIEND;
    else if (wstr == L"remove_friend")
        return REMOVE_FRIEND;
    else
        return UNKNOWN;
}

Request InterfaceTypical::Input() {
    std::wstring line;
    std::wstring account, command;
    Request request;
    while (true) {
        std::getline(std::cin, line);

        std::istringstream in(line);
        in >> account;
        in >> command;
        if (account == L"" || command == L"") {
            std::wcout << termcolor::red << L"Syntax error." << termcolor::reset << L" Type 'help' for help" << std::endl;
            continue;
        }
        request.IdOfRemoteAccount = (std::string) account;
        request.Action = wstring_to_action(command);
        if (in.peek() == EOF) {
            break;
        } else {
            std::wstring args_str;
            std::getline(in, args_str);
            auto args_vec = split_to_tokens(args_str);
            std::map<std::string, std::wstring> kwargs = split_to_kwargs(args_vec);
            request.Params = kwargs;
            break;
        }
    }
    return request;
}
