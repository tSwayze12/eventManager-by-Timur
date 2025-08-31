#include "console_cleaner.h"
#include <cstdlib>

void clean_console_crossplatform() {
        #ifdef _WIN32
                std::system("cls");
        #else
                std::system("clear");
        #endif
}


