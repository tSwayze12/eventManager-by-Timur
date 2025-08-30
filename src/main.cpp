#include "EventManager.h"
#include "scripts.h"

#include <iostream>

int main() {
    auto project_root = get_project_root();
    copy_file_from_data(project_root);
    std::cout << "Hello world" << std::endl;
    remove_from_build(project_root);
}
