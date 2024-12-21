##################################################################################
#                                     Makefile for                               #
#                                     Lib Library                                #
##################################################################################

#───────────────────────────────────────Sources───────────────────────────────────

CONVERSION_SRCS	= srcs/conversion/ft_itoa.c \
                  srcs/conversion/ft_atoi.c \
                  srcs/conversion/ft_tolower.c \
                  srcs/conversion/ft_toupper.c \
                  srcs/conversion/atoll_valid.c

FT_PRINTF_SRCS	= srcs/ft_printf/ft_printf.c \
                  srcs/ft_printf/long_to_hex.c \
                  srcs/ft_printf/print_chars.c \
                  srcs/ft_printf/print_n_string.c \
                  srcs/ft_printf/print_numbers.c \
                  srcs/ft_printf/unsigned_itoa.c \
                  srcs/ft_printf/utils.c

LIST_SRCS		= srcs/list/ft_lstadd_back_bonus.c \
              	  srcs/list/ft_lstadd_front_bonus.c \
              	  srcs/list/ft_lstclear_bonus.c \
              	  srcs/list/ft_lstdelone_bonus.c \
              	  srcs/list/ft_lstiter_bonus.c \
              	  srcs/list/ft_lstlast_bonus.c \
              	  srcs/list/ft_lstmap_bonus.c \
              	  srcs/list/ft_lstnew_bonus.c \
              	  srcs/list/ft_lstsize_bonus.c \
              	  srcs/list/lstcpy.c

MEMORY_SRCS		= srcs/memory/ft_memset.c \
                  srcs/memory/ft_bzero.c \
                  srcs/memory/ft_memcpy.c \
                  srcs/memory/ft_memmove.c \
                  srcs/memory/ft_memchr.c \
                  srcs/memory/ft_memcmp.c \
                  srcs/memory/ft_calloc.c \
                  srcs/memory/free_matrix.c \
                  srcs/memory/realloc.c

STRING_SRCS		= srcs/string/ft_strlen.c \
                  srcs/string/ft_strlcpy.c \
                  srcs/string/ft_strlcat.c \
                  srcs/string/ft_strchr.c \
                  srcs/string/ft_strrchr.c \
                  srcs/string/ft_strncmp.c \
                  srcs/string/ft_strnstr.c \
                  srcs/string/ft_strdup.c \
                  srcs/string/ft_substr.c \
                  srcs/string/ft_strjoin.c \
                  srcs/string/ft_strtrim.c \
                  srcs/string/ft_split.c \
                  srcs/string/ft_strmapi.c \
                  srcs/string/ft_striteri.c \
                  srcs/string/ft_isalnum.c \
                  srcs/string/ft_isalpha.c \
                  srcs/string/ft_isascii.c \
                  srcs/string/ft_isdigit.c \
                  srcs/string/ft_isprint.c

WRITE_SRCS		= srcs/write/ft_putchar_fd.c \
                  srcs/write/ft_putendl_fd.c \
                  srcs/write/ft_putnbr_fd.c \
                  srcs/write/ft_putstr_fd.c

# Combine all source files
SRCS			= $(CONVERSION_SRCS) \
 		  		  $(FT_PRINTF_SRCS) \
 		  		  $(WRITE_SRCS) \
				  $(LIST_SRCS) \
				  $(MEMORY_SRCS) \
				  $(STRING_SRCS)

OBJ_DIR = objects
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

#───────────────────────────────────────Compilation───────────────────────────────────

INCS    		= includes
NAME   			= libft.a
LIBC    		= ar rcs
CC      		= cc
CFLAGS  		= -Wall -Werror -Wextra -g
RM      		= rm -rf

#─────────────────────────────────────────Colors───────────────────────────────────────
SOFT_PINK 		= \033[38;2;255;182;193m
DARK_PINK 		= \033[38;2;255;105;130m
RESET 			= \033[0m

#────────────────────────────────────Compilation Rules──────────────────────────────────

# Compile .c files into .o files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

# Link all object files into the library archive
$(NAME): $(OBJS)
	@echo "$(SOFT_PINK)Creating library "
	@for i in 1 2 3; do \
		echo -n "$(SOFT_PINK)."; \
		sleep 0.5; \
	done; \
	echo "$(RESET)" # Reset color and move to a new line
	@$(LIBC) $@ $^
	@echo "$(DARK_PINK)Compiled successfully!$(RESET)" # Strong pink for success message

#───────────────────────────────────Compilation Commands────────────────────────────────

# Default target, builds the library
all: $(NAME)

#─────────────────────────────────────Cleaning Commands──────────────────────────────────

# Remove object files
clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(SOFT_PINK)Objects removed successfully!$(RESET)"

# Full clean: remove library files as well
fclean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(SOFT_PINK)Objects and $(NAME) removed successfully!$(RESET)"

# Rebuild everything from scratch
re: fclean all

#────────────────────────────────────────Phony Targets─────────────────────────────────────

.PHONY: all bonus so clean fclean re