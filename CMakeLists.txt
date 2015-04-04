cmake_minimum_required(VERSION 2.8)
project(commoncpp)

file(GLOB_RECURSE source src/main/*.cpp)
file(GLOB_RECURSE tests src/test/*.cpp)

include_directories(src/include)
include_directories(/usr/include/GraphicsMagick/)

add_library(commoncpp SHARED ${source})

find_library(GMagick GraphicsMagick++)
find_library(gtest gtest)
find_library(log4cplus log4cplus)
find_library(crypto crypto)

# Add required boost libraries
find_package(Boost 1.36.0 COMPONENTS filesystem system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Add GTest library
find_package(GTest)

target_link_libraries(commoncpp ${GMagick} ${log4cplus} ${crypto} ${Boost_LIBRARIES})

# Only build tests if GTest is installed
if(GTEST_FOUND)
	add_executable (Test ${tests})
	target_link_libraries(Test commoncpp ${GTEST_LIBRARIES})

	enable_testing()
	add_test(NAME Test COMMAND Test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
	add_custom_command(TARGET Test POST_BUILD COMMAND ctest -V)
endif()
