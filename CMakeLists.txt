cmake_minimum_required(VERSION 2.8)
project(commoncpp CXX)

add_definitions(-std=c++11)

# Boost needs additional flags
if(BUILD_SHARED_LIBS)
	ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
else()
	SET(Boost_USE_STATIC_LIBS ON)
endif()

# Add additional cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Use code coverage
INCLUDE(CodeCoverage)

option (BUILD_TESTS "Build and run unit tests" ON)

file(GLOB_RECURSE source src/main/*.cpp)
file(GLOB_RECURSE tests src/test/*.cpp)

include_directories(src/include)
include_directories(/usr/include/GraphicsMagick/)

# Add catch testing framework
include_directories(catch/include)

add_library(commoncpp ${source})

find_library(GMagick GraphicsMagick++)
find_library(gtest gtest)
find_library(crypto crypto)

# Add required boost libraries
find_package(Boost 1.55.0 COMPONENTS log log_setup filesystem system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(commoncpp ${GMagick} ${crypto} ${Boost_LIBRARIES})

# Only build tests if GTest is installed and option is selected
if(BUILD_TESTS)
	add_executable (Test ${tests})
	target_link_libraries(Test commoncpp )

	# copy test files to build directory
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/test DESTINATION ${CMAKE_BINARY_DIR}/src)

	enable_testing()
	add_test(NAME Test COMMAND Test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
	add_custom_command(TARGET Test POST_BUILD COMMAND ctest -V)
else()
	message("Skipping tests...")
endif()

# Coverage target
SETUP_TARGET_FOR_COVERAGE(
	cov  		# Name for custom target.
	Test         	# Name of the test driver executable that runs the tests.
	coverage        # Name of output directory.
)
