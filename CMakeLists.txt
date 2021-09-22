cmake_minimum_required(VERSION 3.17)
project(ListeChainee C)

set(CMAKE_C_STANDARD 99)

add_executable(ListeChainee main.c Point2D.h link.h link.c)