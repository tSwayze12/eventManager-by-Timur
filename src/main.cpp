#include "EventManager.h"
#include "scripts.h"
#include "menu_managing.h"
#include "console_cleaner.h"

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

    clean_console_crossplatform();
    menu_managing::get_menu();
//    std::cout << "Executable stuff here\n";

    browser.copy_from_build();
    browser.remove_from_build();
}
