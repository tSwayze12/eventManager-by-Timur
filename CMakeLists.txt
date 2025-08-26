cmake_minimum_required(VERSION 3.16)
project(EventManagerApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(event_manager
    src/main.cpp
    src/Event.cpp
    src/EventManager.cpp
)

enable_testing()
add_subdirectory(tests)
