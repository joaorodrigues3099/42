cmake_minimum_required(VERSION 3.29)

project(Philosophers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

include_directories(
)

add_executable(Philo
		philosophers/philo/src/main/main.c
		philosophers/philo/Makefile
		philosophers/philo/src/util/ft_strlen.c
		philosophers/philo/include/error.h
		philosophers/philo/src/error/error.c
		philosophers/philo/include/philosophers.h
		philosophers/philo/src/util/atoll_valid.c
		philosophers/philo/src/init/init.c
		philosophers/philo/src/event/routine.c
)

target_include_directories(Philo PRIVATE
		philosophers/philo/include
)

add_executable(M4nb3LL_Philo
		m4nb3ll_philo/philo_utils.c
		m4nb3ll_philo/Makefile
		m4nb3ll_philo/philo.h
		m4nb3ll_philo/main.c
		m4nb3ll_philo/init.c
		m4nb3ll_philo/libft_utils/ft_usleep.c
		m4nb3ll_philo/libft_utils/ft_strlen.c
		m4nb3ll_philo/libft_utils/ft_now_ms.c
		m4nb3ll_philo/libft_utils/ft_isint.c
		m4nb3ll_philo/libft_utils/ft_isdigit.c
		m4nb3ll_philo/libft_utils/ft_calloc.c
		m4nb3ll_philo/libft_utils/ft_atoi.c
)

target_include_directories(M4nb3LL_Philo PRIVATE
		m4nb3ll_philo
)