cmake_minimum_required(VERSION 2.8)
project(commoncpp)

file(GLOB_RECURSE source src/main/*.cpp)
file(GLOB_RECURSE tests src/test/*.cpp)

include_directories(src/include)
add_library(commoncpp SHARED ${source})

add_executable (Test ${tests})

target_link_libraries(Test commoncpp)
