cmake_minimum_required(VERSION 3.10)
project(glad)

add_library(glad include/glad/glad.h include/KHR/khrplatform.h src/glad.c)
target_include_directories(glad PUBLIC include/)
set_property(TARGET glad PROPERTY "External")