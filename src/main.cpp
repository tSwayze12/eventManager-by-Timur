#include "EventManager.h"
#include "scripts.h"
#include "console_menu.h"

#include <iostream>
#include <filesystem>
#include <fstream>

int main() {
    std::filesystem::path project_root = __FILE__;
    project_root = project_root.parent_path().parent_path();

    Browse_data browser(project_root);
    if (!std::filesystem::exists(project_root / "data" / "events.txt")) {
        std::ofstream file(project_root / "data" / "events.txt");
        file.close();
    }

    browser.copy_file_from_data();

//    std::cout << "Executable stuff here\n";
    browser.copy_from_build();
    browser.remove_from_build();
}
