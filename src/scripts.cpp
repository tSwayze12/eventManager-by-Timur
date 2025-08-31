#include "scripts.h"
#include <filesystem>
#include <fstream>

void Browse_data::copy_file_from_data() const {
    std::filesystem::path copy_from_path = project_root / "data" / "events.txt";
    std::filesystem::path copy_into_path = project_root / "build" / "events.txt";
    if (!std::filesystem::exists(copy_from_path)) {
        throw std::logic_error("No such events.txt in directory data/");
    }
    std::filesystem::copy_file(copy_from_path, copy_into_path);
}

void Browse_data::remove_from_build() const {
    std::filesystem::remove(project_root / "build" / "events.txt");
}

void Browse_data::copy_from_build() const {
    std::filesystem::remove(project_root / "data" / "events.txt");
    std::filesystem::copy_file(
        project_root / "build" / "events.txt",
        project_root / "data" / "events.txt"
    );
}