#include "menu_manager.h"

#include <iostream>
#include <ios>
#include <limits>

void Menu_manager::get_menu() {
    std::cout << "============================"
    << std::endl
    << "=====Choose your action====="
    <<std::endl
    << "==1 - Get upcoming events.=="
    << std::endl
    << "======2 - Add an event======"
    << std::endl
    << "=q - Close the application.=" //Formally ascii 81 but I don't know q looks better
    << std::endl
    << "================Your choice:";
}

unsigned Menu_manager::get_integer() {
    unsigned vexing_int;
    std::cin >> vexing_int;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (vexing_int == 0 || (vexing_int > 2 && vexing_int != 81)) {
        throw std::runtime_error("Choice does not satisfy the format");
    }
    return vexing_int;
}

std::string Menu_manager::get_string() {
    std::string vexing_line;
    std::getline(std::cin, vexing_line);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //I will check the format in ParseDate
    return vexing_line;
}


