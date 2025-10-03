cmake_minimum_required(VERSION 4.0)
project(advent_of_code C)

set(CMAKE_C_STANDARD 17)

add_executable(advent_of_code main.c
        day1/a.c
        day1/b.c
        day2/a.c
        day2/b.c
        day3/a.c
        day3/b.c)
