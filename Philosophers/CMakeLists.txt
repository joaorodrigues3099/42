cmake_minimum_required(VERSION 3.29)

project(Philosophers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

include_directories(
)

add_executable(Philo
		philosophers/mandatory/src/main/main.c
		philosophers/Makefile
		philosophers/Makefile
)

target_include_directories(Philo PRIVATE
		philosophers/mandatory/include
)

add_executable(Philo_Bonus
		philosophers/bonus/src/main/main_bonus.c
		philosophers/Makefile
		philosophers/Makefile
)

target_include_directories(Philo_Bonus PRIVATE
		philosophers/bonus/include
)