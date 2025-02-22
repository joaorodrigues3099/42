cmake_minimum_required(VERSION 3.29)

project(Philosophers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(philo
		src/main.c
		Makefile
		src/error.c
		include/philosophers.h
		src/init.c
		src/routine.c
		src/util.c
		src/monitor.c
		include/util.h
		src/routine_util.c
		src/exit.c
)

include_directories(
		include
)