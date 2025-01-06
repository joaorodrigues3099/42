cmake_minimum_required(VERSION 3.29)

project(PushSwap)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

include_directories(includes lib/includes)

add_executable(Client
		srcs/client.c
		Makefile
		lib/includes/lib_conversion.h
		lib/srcs/conversion/ft_toupper.c
		lib/srcs/conversion/ft_tolower.c
		lib/srcs/conversion/ft_itoa.c
		lib/srcs/conversion/ft_atoi.c
		lib/srcs/conversion/atoll_valid.c
		lib/Makefile
		includes/minitalk.h
		lib/includes/lib_print.h
		lib/srcs/lib_print/print_error.c
)

add_executable(Server
		srcs/server.c
		Makefile
		lib/includes/lib_conversion.h
		lib/srcs/conversion/ft_toupper.c
		lib/srcs/conversion/ft_tolower.c
		lib/srcs/conversion/ft_itoa.c
		lib/srcs/conversion/ft_atoi.c
		lib/srcs/conversion/atoll_valid.c
		lib/Makefile
		includes/minitalk.h
		lib/includes/lib_print.h
		lib/srcs/lib_print/print_error.c
)

add_executable(Client_Bonus
		Makefile
		lib/includes/lib_conversion.h
		lib/srcs/conversion/ft_toupper.c
		lib/srcs/conversion/ft_tolower.c
		lib/srcs/conversion/ft_itoa.c
		lib/srcs/conversion/ft_atoi.c
		lib/srcs/conversion/atoll_valid.c
		lib/Makefile
		includes/minitalk.h
		lib/includes/lib_print.h
		lib/srcs/lib_print/print_error.c
		bonus/client_bonus.c
)

add_executable(Server_Bonus
		Makefile
		lib/includes/lib_conversion.h
		lib/srcs/conversion/ft_toupper.c
		lib/srcs/conversion/ft_tolower.c
		lib/srcs/conversion/ft_itoa.c
		lib/srcs/conversion/ft_atoi.c
		lib/srcs/conversion/atoll_valid.c
		lib/Makefile
		bonus/server_bonus.c
		includes/minitalk.h
		lib/includes/lib_print.h
		lib/srcs/lib_print/print_error.c
)