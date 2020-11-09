cmake_minimum_required(VERSION 3.10)

# set the project name
project(watched-and-observed)

#Other compilation units required
add_library(Watched Watched.cpp)
add_library(Observer Observer.cpp)

add_executable(main main.cpp)

target_link_libraries(main Watched Observer)
