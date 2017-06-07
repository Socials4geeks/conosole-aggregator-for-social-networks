#include "interface_vk.h"
#include "types.h"
#include "interfaces.h"
#include "termcolor.h"

InterfaceVK::InterfaceVK() {
    name_of_social_network = "vk";
}

InterfaceVK::~InterfaceVK() {

};

Status InterfaceVK::PrintError( Response data ) {
    std::wcout << termcolor::on_red << L"Error:"
              << termcolor::reset << L" " << data.Params[0]["reason"] << std::endl;
    return OK;
};
