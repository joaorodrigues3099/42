cmake_minimum_required(VERSION 3.29)

project(Get-Next-Line)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(Get-Next-Line
		get_next_line/get_next_line.c
		get_next_line/get_next_line.h
		get_next_line/get_next_line_utils.c
)

add_executable(Get-Next-Line_Bonus
		get_next_line/get_next_line_bonus.c
		get_next_line/get_next_line_bonus.h
		get_next_line/get_next_line_utils_bonus.c
)

include_directories(get_next_line)