# CMakeLists.txt
cmake_minimum_required(VERSION 2.8.2)

project(watched-and-observed)

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

# configure the required compilation units
add_library(Watched Watched.cpp)
add_library(Observer Observer.cpp)

add_executable(main main.cpp)

target_link_libraries(main Watched Observer)

# tests
add_executable(watched_test test/watched_test.cpp)
target_link_libraries(watched_test Watched gtest)
add_test(NAME test_one COMMAND watched_test)

set_target_properties(watched_test PROPERTIES EXCLUDE_FROM_ALL TRUE)


