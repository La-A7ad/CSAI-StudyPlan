cmake_minimum_required(VERSION 3.28)
project(CSAI_SP)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json 3.10.5 REQUIRED)

add_executable(CSAI_SP main.cpp)
target_link_libraries(CSAI_SP PRIVATE nlohmann_json::nlohmann_json)
