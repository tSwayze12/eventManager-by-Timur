#include "scripts.h"
#include <filesystem>
#include <fstream>

void copy_file_from_data(const std::filesystem::path& project_root) {
    std::filesystem::path copy_from_path = project_root / "data" / "events.txt";
    std::filesystem::path copy_into_path = project_root / "build" / "events.txt";
    if (!std::filesystem::exists(copy_from_path)) {
        throw std::logic_error("No such events.txt in directory data/");
    }
    std::filesystem::copy_file(copy_from_path, copy_into_path);
}

std::filesystem::path get_project_root() {
    std::filesystem::path project_root = __FILE__;
    return project_root.parent_path().parent_path();
}

void remove_from_build(const std::filesystem::path& project_root) {
    std::filesystem::remove(project_root / "build" / "events.txt");
}