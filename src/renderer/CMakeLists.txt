cmake_minimum_required(VERSION 2.8)
project(renderer)
set(SOURCE_LIB renderer.cpp)
add_library(renderer STATIC ${SOURCE_LIB})
