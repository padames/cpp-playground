cmake_minimum_required(VERSION 3.10)

# set the project name
project(watched-and-observed)

#Other compilation units required
add_library(Watched Watched.cpp)
add_library(Observer Observer.cpp)

add_executable(main main.cpp)
target_link_libraries(main Watched Observer)

# Third-party library
include(ExternalProject)
ExternalProject_Add(googletest
    PREFIX "${CMAKE_BINARY_DIR}/lib"
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "master"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/../lib/installed
)
# Prevent build on all targets build
set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Define ${CMAKE_INSTALL_...} variables
include(GNUInstallDirs)

# Specify where third-party libraries are located
link_directories(${CMAKE_BINARY_DIR}/../lib/installed/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/../lib/installed/${CMAKE_INSTALL_INCLUDEDIR})

# This is required for googletest
find_package(Threads REQUIRED)

# Test
add_executable(watched_test test/watched_test.cpp)
target_link_libraries(watched_test Watched gtest Threads::Threads)
# Make sure third-party is built before executable
add_dependencies(watched_test googletest)
set_target_properties(watched_test PROPERTIES EXCLUDE_FROM_ALL TRUE)
