cmake_minimum_required(VERSION 3.15)
project(salt_bot VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(dpp REQUIRED)
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_FILES}) 
target_link_libraries(${PROJECT_NAME} dpp::dpp)


