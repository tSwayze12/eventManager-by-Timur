#pragma once

#include <filesystem>
class Browse_data {
private:
    std::filesystem::path project_root;
public:
    Browse_data(const std::filesystem::path& pr) : project_root(pr) {}

    void copy_file_from_data() const ;

    void remove_from_build() const;

    void copy_from_build() const;
};