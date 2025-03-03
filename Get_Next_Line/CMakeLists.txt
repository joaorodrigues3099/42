cmake_minimum_required(VERSION 3.29)

project(Get-Next-Line)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(Get-Next-Line
		get_next_line/2nd_gnl/get_next_line.h
)

include_directories(
		get_next_line
)