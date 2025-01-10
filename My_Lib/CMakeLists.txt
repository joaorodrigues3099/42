cmake_minimum_required(VERSION 3.29)

project(My_Lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_library(Char
		lib/char/ft_isalnum.c
		lib/char/ft_isalpha.c
		lib/char/ft_isascii.c
		lib/char/ft_isdigit.c
		lib/char/ft_isprint.c
		lib/char/lib_char.h
		lib/Makefile
)

add_library(Conversion
		lib/conversion/atoll_valid.c
		lib/conversion/ft_atoi.c
		lib/conversion/ft_itoa.c
		lib/conversion/ft_tolower.c
		lib/conversion/ft_toupper.c
		lib/conversion/lib_conversion.h
		lib/Makefile
)

add_library(List
		lib/list/ft_lstadd_back_bonus.c
		lib/list/ft_lstadd_front_bonus.c
		lib/list/ft_lstclear_bonus.c
		lib/list/ft_lstdelone_bonus.c
		lib/list/ft_lstiter_bonus.c
		lib/list/ft_lstlast_bonus.c
		lib/list/ft_lstmap_bonus.c
		lib/list/ft_lstnew_bonus.c
		lib/list/ft_lstsize_bonus.c
		lib/list/lstdel_safely.c
		lib/list/lstnew_int.c
		lib/list/lstget_int.c
		lib/list/lstdup.c
		lib/list/lstdetach.c
		lib/list/lib_list.h
		lib/Makefile
)

add_library(Memory
		lib/memory/free_matrix.c
		lib/memory/ft_bzero.c
		lib/memory/ft_calloc.c
		lib/memory/ft_memchr.c
		lib/memory/ft_memcmp.c
		lib/memory/ft_memcpy.c
		lib/memory/ft_memmove.c
		lib/memory/ft_memset.c
		lib/memory/realloc.c
		lib/memory/sort_tab.c
		lib/memory/lib_memory.h
		lib/Makefile
)

add_library(Print
		lib/print/ft_printf.c
		lib/print/print_error.c
		lib/print/put_numbers.c
		lib/print/put_characters.c
		lib/print/lib_print.h
		lib/Makefile
)

add_library(String
		lib/string/ft_split.c
		lib/string/ft_strchr.c
		lib/string/ft_strdup.c
		lib/string/ft_striteri.c
		lib/string/ft_strjoin.c
		lib/string/ft_strlcat.c
		lib/string/ft_strlcpy.c
		lib/string/ft_strlen.c
		lib/string/ft_strmapi.c
		lib/string/ft_strncmp.c
		lib/string/ft_strnstr.c
		lib/string/ft_strrchr.c
		lib/string/ft_strtrim.c
		lib/string/ft_substr.c
		lib/string/lib_string.h
		lib/Makefile
		lib/string/strcpy.c
)
add_library(Gnl
		lib/gnl/get_next_line.c
		lib/gnl/get_next_line_utils.c
		lib/gnl/lib_gnl.h
)
