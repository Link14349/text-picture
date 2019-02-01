cmake_minimum_required(VERSION 3.9)
project(textPicture)

set(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(
        include
)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_executable(textPicture main.cpp)