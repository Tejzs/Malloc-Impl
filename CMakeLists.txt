cmake_minimum_required(VERSION 3.14)
project(malloc_impl C)

set(CMAKE_C_STANDARD 99)

add_executable(malloc_impl
        main.c
        my_malloc.c
)

enable_testing()

add_executable(test_malloc
        test_malloc.c
        my_malloc.c
)

# Register each test individually so they show up by name
add_test(NAME BasicAlloc     COMMAND test_malloc)
add_test(NAME ZeroAlloc      COMMAND test_malloc)
add_test(NAME MultipleAllocs COMMAND test_malloc)