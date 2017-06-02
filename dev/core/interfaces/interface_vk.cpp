#include "core/interfaces/interface_vk.h"
#include "types.h"
#include "core/interfaces/interfaces.h"
#include "core/interfaces/termcolor.h"

InterfaceVK::InterfaceVK() {
    name_of_social_network = "vk";
}

InterfaceVK::~InterfaceVK() {

};

Status InterfaceVK::PrintError( Response data ) {
    std::cout << termcolor::on_red << "Error:"
              << termcolor::reset << " " << data.Params[0]["reason"] << std::endl;
    return OK;
};
