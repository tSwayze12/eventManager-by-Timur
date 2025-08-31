#include "EventManager.h"
#include "scripts.h"
#include "menu_managing.h"
#include "console_cleaner.h"

#include <filesystem>
#include <fstream>
#include <iostream>


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
    auto event_manager = EventManager("events.txt");
    auto today = std::chrono::floor<std::chrono::days>
    (std::chrono::system_clock::now());
    while (true) {
        clean_console_crossplatform();
        menu_managing::get_menu();
        // ReSharper disable once CppDefaultCaseNotHandledInSwitchStatement
        switch (menu_managing::get_integer()) {
            default:
                browser.copy_from_build();
                browser.remove_from_build();
                std::exit(0);
            case 1:
                auto events = event_manager.getUpcomingEvents(today);
                for (const Event& event : events) {
                    std::cout << event.getDate() << " " << event.getDescription() << std::endl;
                }
                char _;
                std::cout << "Press enter if you want to move to the main menu: ";
                std::cin.get();
                break;
        }
    }
}
