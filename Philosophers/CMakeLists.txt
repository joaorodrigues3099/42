cmake_minimum_required(VERSION 3.29)

project(Philosophers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

include_directories(
)

add_executable(Philo
		philosophers/mandatory/src/main/main.c
		philosophers/Makefile
		philosophers/mandatory/src/util/ft_strlen.c
		philosophers/mandatory/src/init/input.c
		philosophers/mandatory/include/notlibft.h
		philosophers/mandatory/include/error.h
		philosophers/mandatory/src/error/error.c
		philosophers/mandatory/include/input.h
		philosophers/mandatory/include/philosophers.h
		philosophers/mandatory/src/util/atoll_valid.c
		philosophers/mandatory/src/init/init_philos.c
		philosophers/mandatory/src/main/routine.c
)

target_include_directories(Philo PRIVATE
		philosophers/mandatory/include
)

add_executable(Philo_Bonus
		philosophers/bonus/src/main/main_bonus.c
		philosophers/Makefile
)

target_include_directories(Philo_Bonus PRIVATE
		philosophers/bonus/include
)