cmake_minimum_required(VERSION 3.6)
project(nm_otool)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(otool/includes)
include_directories(nm/includes)
include_directories(libft/includes)
add_subdirectory(libft)

set(SRCS_TEST
    true_nm.c
    test_sort.c)

set(SRCS_NM
        nm/srcs/ft_nm.c
        nm/srcs/handle_64.c
        nm/srcs/handle_32.c
        nm/srcs/print_64.c
        nm/srcs/print_32.c
        nm/srcs/print_type.c
        nm/srcs/util.c
        nm/srcs/util2.c
        nm/srcs/handle_fat.c
        nm/srcs/handle_ar.c
        nm/srcs/sort_64.c
        nm/srcs/sort_32.c
    )

set(SRCS_OTOOL
        otool/srcs/ft_otool.c
        otool/srcs/handle_64.c
        otool/srcs/handle_32.c
        otool/srcs/util.c
        otool/srcs/util2.c
        otool/srcs/handle_fat.c
        otool/srcs/handle_ar.c
        )

set(HEADERS_NM otool/includes/ft_otool.h)
set(HEADERS_OTOOL otool/includes/ft_otool.h)

add_executable(ft_nm ${SRCS_NM} ${HEADERS_NM})
add_executable(ft_otool ${SRCS_OTOOL} ${HEADERS_OTOOL})

target_link_libraries(ft_nm ft)
target_link_libraries(ft_otool ft)