cmake_minimum_required(VERSION 3.29)

project(My_Lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_library(Char
		lib/src/char/ft_isalnum.c
		lib/src/char/ft_isalpha.c
		lib/src/char/ft_isascii.c
		lib/src/char/ft_isdigit.c
		lib/src/char/ft_isprint.c
		lib/src/char/lib_char.h
		lib/Makefile
)

add_library(Conversion
		lib/src/conversion/atoll_valid.c
		lib/src/conversion/ft_atoi.c
		lib/src/conversion/ft_itoa.c
		lib/src/conversion/ft_tolower.c
		lib/src/conversion/ft_toupper.c
		lib/src/conversion/lib_conversion.h
		lib/Makefile
)

add_library(List
		lib/src/list/ft_lstadd_back_bonus.c
		lib/src/list/ft_lstadd_front_bonus.c
		lib/src/list/ft_lstclear_bonus.c
		lib/src/list/ft_lstdelone_bonus.c
		lib/src/list/ft_lstiter_bonus.c
		lib/src/list/ft_lstlast_bonus.c
		lib/src/list/ft_lstmap_bonus.c
		lib/src/list/ft_lstnew_bonus.c
		lib/src/list/ft_lstsize_bonus.c
		lib/src/list/lstdel_safely.c
		lib/src/list/lstnew_int.c
		lib/src/list/lstget_int.c
		lib/src/list/lstdup.c
		lib/src/list/lstdetach.c
		lib/src/list/lib_list.h
		lib/Makefile
)

add_library(Memory
		lib/src/memory/free_matrix.c
		lib/src/memory/ft_bzero.c
		lib/src/memory/ft_calloc.c
		lib/src/memory/ft_memchr.c
		lib/src/memory/ft_memcmp.c
		lib/src/memory/ft_memcpy.c
		lib/src/memory/ft_memmove.c
		lib/src/memory/ft_memset.c
		lib/src/memory/realloc.c
		lib/src/memory/sort_tab.c
		lib/src/memory/lib_memory.h
		lib/Makefile
)

add_library(Print
		lib/src/print/ft_printf.c
		lib/src/print/print_error.c
		lib/src/print/put_numbers.c
		lib/src/print/put_characters.c
		lib/src/print/lib_print.h
		lib/Makefile
)

add_library(String
		lib/src/string/ft_split.c
		lib/src/string/ft_strchr.c
		lib/src/string/ft_strdup.c
		lib/src/string/ft_striteri.c
		lib/src/string/ft_strjoin.c
		lib/src/string/ft_strlcat.c
		lib/src/string/ft_strlcpy.c
		lib/src/string/ft_strlen.c
		lib/src/string/ft_strmapi.c
		lib/src/string/ft_strncmp.c
		lib/src/string/ft_strnstr.c
		lib/src/string/ft_strrchr.c
		lib/src/string/ft_strtrim.c
		lib/src/string/ft_substr.c
		lib/src/string/lib_string.h
		lib/src/string/strcpy.c
)
add_library(Gnl
		lib/src/gnl/get_next_line.c
		lib/src/gnl/get_next_line_utils.c
		lib/src/gnl/lib_gnl.h
)
