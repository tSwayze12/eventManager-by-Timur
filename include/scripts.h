#pragma once

#include <filesystem>

void copy_file_from_data(const std::filesystem::path& project_root);

std::filesystem::path get_project_root();

void remove_from_build(const std::filesystem::path& project_root);
