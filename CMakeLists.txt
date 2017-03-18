cmake_minimum_required(VERSION 3.6)
project(nm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(includes)
include_directories(libft/includes)
add_subdirectory(libft)

set(SRCS_TEST
    true_nm.c
    test_sort.c)

set(SRCS
    srcs/ft_nm.c
        srcs/handle_64.c
    srcs/handle_32.c
    srcs/print_64.c
    srcs/print_32.c
    srcs/print_type.c
    srcs/debug.c
    srcs/util.c
    srcs/util2.c
    srcs/handle_fat.c
    srcs/handle_ar.c
    srcs/sort_64.c
    srcs/sort_32.c
    )

set(HEADERS includes/ft_nm.h)

add_executable(nm ${SRCS} ${HEADERS})

target_link_libraries(nm ft)