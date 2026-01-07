cmake_minimum_required(VERSION 3.10)
project(malloc_impl C)

set(CMAKE_C_STANDARD 99)

add_executable(malloc_impl
        main.c
        my_malloc.c
)