#include "EventManager.h"
#include "scripts.h"

#include <iostream>
#include <filesystem>
#include <fstream>

int main() {
    auto project_root = get_project_root();

    if (!std::filesystem::exists(project_root / "data" / "events.txt")) {
        std::ofstream file(project_root / "data" / "events.txt");
        file.close();
    }

    copy_file_from_data(project_root);
    copy_from_build(project_root);
    remove_from_build(project_root);
}
