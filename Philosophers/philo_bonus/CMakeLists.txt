cmake_minimum_required(VERSION 3.29)

project(Philosophers_Bonus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(philo_bonus
		include/philo_bonus.h
		src/main/main.c
		src/util/exit.c
		src/util/error.c
		src/util/util.c
		src/util/init.c
		include/util.h
		src/routine/routine.c
		src/routine/monitor.c
)

include_directories(
		include
)