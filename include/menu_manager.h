#pragma once
#include <string>

struct Menu_manager {
    Menu_manager () = default;

    static void get_menu();

    static unsigned get_integer();

    static std::string get_string();
};
