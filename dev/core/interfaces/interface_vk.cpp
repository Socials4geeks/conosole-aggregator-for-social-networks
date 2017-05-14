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

    FriendEntry f1;
    f1.username = "Friend";
    f1.isOnline = true;
    f1.lastEnter = "10.2.19";

    FriendEntry f2;
    f2.username = "Blah-blah";
    f2.isOnline = false;
    f2.lastEnter = "21.5.20";
    std::vector<FriendEntry> vf;
    vf.push_back(f1);
    vf.push_back(f2);
    vf.push_back(f1);
    vf.push_back(f2);
    vf.push_back(f1);
    vf.push_back(f2);
    ivk.PrintFriends(vf);


}
