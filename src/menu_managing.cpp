#include "menu_managing.h"

#include <iostream>
#include <ios>
#include <limits>

void menu_managing::get_menu() {
    std::cout
    << "============================"
    << std::endl
    << "Choose your action"
    <<std::endl
    << "1 - Get upcoming events"
    << std::endl
    << "2 - Add an event"
    << std::endl
    << "q - Close the application" //Formally ascii 81 but I don't know q looks better
    << std::endl
    <<"============================"
    << std::endl
    << "Your choice:";
}

unsigned menu_managing::get_integer() {
    unsigned vexing_int;
    std::cin >> vexing_int;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (vexing_int == 0 || (vexing_int > 2 && vexing_int != 81)) {
        throw std::runtime_error("Choice does not satisfy the format");
    }
    return vexing_int;
}

std::string menu_managing::get_string() {
    std::string vexing_line;
    std::getline(std::cin, vexing_line);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //I will check the format in ParseDate
    return vexing_line;
}

void menu_managing::get_cancel_option() {
    std::cout
    << std::endl
    << "0 - Cancel and return to the main menu";
    unsigned choice = get_integer();
    if (choice ==0 ) {
    get_menu();
    }
}

