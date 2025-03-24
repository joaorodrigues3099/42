cmake_minimum_required(VERSION 3.29)

project(Minishell_Joao C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Include header directories (fixed syntax)
include_directories(
		minishell/include
		minishell/lib/include
)

# Add executable with all found sources
add_executable(minishell
		minishell/src/main/main.c
		minishell/include/minishell.h
		minishell/src/util/error.c
		minishell/lib/include/jal_char.h
		minishell/lib/include/jal_conversion.h
		minishell/lib/include/jal_gnl.h
		minishell/lib/include/jal_list.h
		minishell/lib/include/jal_memory.h
		minishell/lib/include/jal_print.h
		minishell/lib/include/jal_string.h
		minishell/lib/src/char/ft_isalnum.c
		minishell/lib/src/char/ft_isalpha.c
		minishell/lib/src/char/ft_isascii.c
		minishell/lib/src/char/ft_isdigit.c
		minishell/lib/src/char/ft_isprint.c
		minishell/lib/src/conversion/atoll_valid.c
		minishell/lib/src/conversion/ft_atoi.c
		minishell/lib/src/conversion/ft_itoa.c
		minishell/lib/src/conversion/ft_tolower.c
		minishell/lib/src/conversion/ft_toupper.c
		minishell/lib/src/gnl/get_next_line.c
		minishell/lib/src/gnl/get_next_line_utils.c
		minishell/lib/src/list/ft_lstadd_back_bonus.c
		minishell/lib/src/list/ft_lstadd_front_bonus.c
		minishell/lib/src/list/ft_lstclear_bonus.c
		minishell/lib/src/list/ft_lstdelone_bonus.c
		minishell/lib/src/list/ft_lstiter_bonus.c
		minishell/lib/src/list/ft_lstlast_bonus.c
		minishell/lib/src/list/ft_lstmap_bonus.c
		minishell/lib/src/list/ft_lstnew_bonus.c
		minishell/lib/src/list/ft_lstsize_bonus.c
		minishell/lib/src/list/lstdel_safely.c
		minishell/lib/src/list/lstdetach.c
		minishell/lib/src/list/lstdup.c
		minishell/lib/src/list/lstget_int.c
		minishell/lib/src/list/lstnew_int.c
		minishell/lib/src/memory/free_matrix.c
		minishell/lib/src/memory/ft_bzero.c
		minishell/lib/src/memory/ft_calloc.c
		minishell/lib/src/memory/ft_memchr.c
		minishell/lib/src/memory/ft_memcmp.c
		minishell/lib/src/memory/ft_memcpy.c
		minishell/lib/src/memory/ft_memmove.c
		minishell/lib/src/memory/ft_memset.c
		minishell/lib/src/memory/realloc.c
		minishell/lib/src/memory/sort_tab.c
		minishell/lib/src/print/ft_printf.c
		minishell/lib/src/print/put_characters.c
		minishell/lib/src/print/put_numbers.c
		minishell/lib/src/string/ft_split.c
		minishell/lib/src/string/ft_strchr.c
		minishell/lib/src/string/ft_strcmp.c
		minishell/lib/src/string/ft_strdup.c
		minishell/lib/src/string/ft_striteri.c
		minishell/lib/src/string/ft_strjoin.c
		minishell/lib/src/string/ft_strlcat.c
		minishell/lib/src/string/ft_strlcpy.c
		minishell/lib/src/string/ft_strlen.c
		minishell/lib/src/string/ft_strmapi.c
		minishell/lib/src/string/ft_strncmp.c
		minishell/lib/src/string/ft_strnstr.c
		minishell/lib/src/string/ft_strrchr.c
		minishell/lib/src/string/ft_strtrim.c
		minishell/lib/src/string/ft_substr.c
		minishell/lib/src/string/strcpy.c
		minishell/lib/Makefile
		minishell/Makefile
		minishell/lib/Makefile
		minishell/Makefile
		minishell/src/builtins/echo.c
		minishell/src/parser/lexer.c
		minishell/src/util/token_util.c
		minishell/lib/src/string/strndup.c
		minishell/src/test/test_tokens.c
		minishell/include/test.h
		minishell/include/util.h
		minishell/src/parser/parser.c
		minishell/src/main/init.c
		minishell/lib/src/conversion/process_quotes.c
)
