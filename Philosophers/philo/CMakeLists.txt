cmake_minimum_required(VERSION 3.29)

project(Philosophers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(philo
		src/main/main.c
		Makefile
		include/error.h
		src/util/error.c
		include/philosophers.h
		src/init/init.c
		src/routine/routine.c
		src/util/util.c
		src/routine/monitor.c
		include/colour.h
		src/routine/routine_util.c
		src/util/exit.c
)

include_directories(
		include
)