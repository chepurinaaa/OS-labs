cmake_minimum_required(VERSION 3.15)
project(world C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -Wall -E")

add_executable(world main.c lib.h main2.c main1.c)