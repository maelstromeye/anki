cmake_minimum_required(VERSION 3.15)
project(anki)

set(CMAKE_CXX_STANDARD 11)

add_executable(anki main.cpp Component.cpp Component.h)