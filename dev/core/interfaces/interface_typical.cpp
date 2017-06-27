#include <stdexcept>

#include "interface_typical.h"
#include "types.h"
#include "interfaces.h"

InterfaceTypical::InterfaceTypical() {}

InterfaceTypical::~InterfaceTypical() {

}

Status InterfaceTypical::PrintMessages( Response data ) {
    if (data.Type == ERROR) {
        std::string reason = data.Params[0].at("reason");
        std::cout << termcolor::red << reason << termcolor::reset << std::endl;

    }
    for (int i = 0 ; i < data.Params.size(); i++) {
        std::cout << termcolor::reset << "[" << data.Params[i]["datetime"] << "] "
                   << termcolor::colorizeStringByHash(data.Params[i]["username"]) << termcolor::reset << ": ";
        if (data.Params[i]["title"] != "") {
            std::cout << termcolor::bold << data.Params[i]["title"] << termcolor::reset << std::endl;
        }
        std::cout << data.Params[i]["body"] << std::endl;
    }
    return OK;
};

Status InterfaceTypical::PrintWall( Response data ) {
    std::cout << termcolor::on_red << "Access violation:"
              << termcolor::reset << " Unavailable in current version." << std::endl;
    return OK;
};

Status InterfaceTypical::PrintFriends( Response data ) {
    std::sort(data.Params.begin(), data.Params.end(), 
              [](params a, params b) -> bool { 
                  return ((a["is_online"] == "true") > (b["is_online"] == "true"));
              });

    for (int i = 0; i < data.Params.size(); i++) {
        if (data.Params[i]["is_online"] == "true") {
            std::cout << termcolor::green << data.Params[i]["username"] << termcolor::reset << ": online" << std::endl;
        } else {
            std::cout << termcolor::red << data.Params[i]["username"] << termcolor::reset
                      << ": " << data.Params[i]["last_enter"] << std::endl;
        }
    }

    return OK;
};

template<typename Out>
void InterfaceTypical::split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> InterfaceTypical::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

Status InterfaceTypical::PrintError( Response data ) {
    std::cout << termcolor::on_red << "Error:"
              << termcolor::reset << " " << data.Params[0]["reason"] << std::endl;
    return OK;
};
