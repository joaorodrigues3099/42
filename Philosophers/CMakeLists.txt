cmake_minimum_required(VERSION 3.29)

project(Philosophers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

include_directories(
)

add_executable(Philo
		philo/src/main.c
		philo/Makefile
		philo/include/error.h
		philo/src/error.c
		philo/include/philosophers.h
		philo/src/atoi_v.c
		philo/src/init.c
		philo/src/routine.c
)

target_include_directories(Philo PRIVATE
		philo/include
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

add_executable(Dpetrosy_Philo
		dpetrosy_philo/philo/includes/init.h
		dpetrosy_philo/philo/includes/philo.h
		dpetrosy_philo/philo/includes/simulation.h
		dpetrosy_philo/philo/includes/utils.h
		dpetrosy_philo/philo/srcs/init.c
		dpetrosy_philo/philo/srcs/main.c
		dpetrosy_philo/philo/srcs/utils.c
		dpetrosy_philo/philo/srcs/str_utils.c
		dpetrosy_philo/philo/srcs/simulation.c
		dpetrosy_philo/philo/Makefile

)

target_include_directories(Dpetrosy_Philo PRIVATE
		dpetrosy_philo/philo/includes
)