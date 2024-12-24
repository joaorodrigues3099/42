cmake_minimum_required(VERSION 3.29)

project(GetNextLine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(GetNextLine
		get_next_line.c
		get_next_line.h
		get_next_line_utils.c
)
target_include_directories(GetNextLine PRIVATE ./)

add_executable(GetNextLine_Bonus
		get_next_line_bonus.c
		get_next_line_bonus.h
		get_next_line_utils_bonus.c
)
target_include_directories(GetNextLine_Bonus PRIVATE ./)