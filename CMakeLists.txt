cmake_minimum_required(VERSION 2.8)
project(commoncpp CXX)

### User options ###

option(BUILD_SHARED_LIBS "Build as shared or static library" ON)
option(BUILD_TESTS "Build and run unit tests" ON)

#################################

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

file(GLOB_RECURSE source src/main/*.cpp)
file(GLOB_RECURSE tests src/test/*.cpp)

include_directories(src/include)
include_directories(/usr/include/GraphicsMagick/)

# Add catch testing framework
include_directories(catch/include)

add_library(commoncpp ${source})

find_library(crypto crypto)
find_package(OpenCV REQUIRED)


# Add required boost libraries
find_package(Boost 1.55.0 COMPONENTS log filesystem system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(commoncpp ${OpenCV_LIBRARIES} ${crypto} ${Boost_LIBRARIES})

if(BUILD_TESTS)
        SET(TEST_BINARY test_${PROJECT_NAME})
        add_executable (${TEST_BINARY} ${tests})
        target_link_libraries(${TEST_BINARY} commoncpp )

        # copy test files to build directory
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/test DESTINATION ${CMAKE_BINARY_DIR}/src)

        enable_testing()
        add_test(NAME ${TEST_BINARY} COMMAND ${TEST_BINARY} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        add_custom_command(TARGET ${TEST_BINARY} POST_BUILD COMMAND ctest -V)
else()
        message("Skipping tests...")
endif()

# Ignore in coverage report
set(LCOV_REMOVE_EXTRA 'include/*')

# Coverage target
SETUP_TARGET_FOR_COVERAGE(
        cov_${PROJECT_NAME}     # Name for custom target.
        ${TEST_BINARY}          # Name of the test driver executable that runs the tests.
        coverage                # Name of output directory.
)
