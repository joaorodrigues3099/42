cmake_minimum_required(VERSION 3.30)
project(New_Get_Next_Line C)

set(CMAKE_C_STANDARD 11)

include_directories(get_next_line)

add_executable(New_Get_Next_Line
		get_next_line/get_next_line.h
		get_next_line/get_next_line.c
		get_next_line/get_next_line_utils.c
		get_next_line/get_next_line_bonus.h
		get_next_line/get_next_line_bonus.c
		get_next_line/get_next_line_utils_bonus.c
)
