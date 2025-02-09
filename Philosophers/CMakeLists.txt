cmake_minimum_required(VERSION 3.29)

project(Philosophers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(Philo
		philo/src/main/main.c
		philo/Makefile
		philo/include/error.h
		philo/src/util/error.c
		philo/include/philosophers.h
		philo/src/init/init.c
		philo/src/routine/routine.c
		philo/src/util/util.c
		philo/src/routine/monitor.c
		philo/include/colour.h
		philo/src/routine/routine_util.c
		philo/src/util/exit.c
)

target_include_directories(Philo PRIVATE
		philo/include
)

add_executable(Philo_Bonus
		philo_bonus/include/philo_bonus.h
		philo_bonus/src/main/main.c

)

target_include_directories(Philo_Bonus PRIVATE
		philo_bonus/include
)