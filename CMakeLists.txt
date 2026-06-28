cmake_minimum_required(VERSION 3.28)
project(vitals C)

set(CMAKE_C_STANDARD 11)

add_executable(vitals main.c
        vitals.c
        vitals.h)
