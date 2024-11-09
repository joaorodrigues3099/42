##############################################
#                Makefile for                #
#                Libft Library               #
##############################################

# File Variables
# ============================================

# Character Check and Conversion Functions
CHARCHECK_SRCS	= srcs/ft_charcheck/ft_isalnum.c \
           		  srcs/ft_charcheck/ft_isalpha.c \
           		  srcs/ft_charcheck/ft_isascii.c \
           		  srcs/ft_charcheck/ft_isdigit.c \
           		  srcs/ft_charcheck/ft_isprint.c \
           		  srcs/ft_charcheck/ft_tolower.c \
           		  srcs/ft_charcheck/ft_toupper.c

# File Descriptor Functions
FDLIB_SRCS		= srcs/ft_fdlib/ft_putchar_fd.c \
          		  srcs/ft_fdlib/ft_putendl_fd.c \
          		  srcs/ft_fdlib/ft_putnbr_fd.c \
          		  srcs/ft_fdlib/ft_putstr_fd.c

# FT_Printf Functions
FT_PRINTF_SRCS	= srcs/ft_fdlib/ft_printf/ft_unsigned_itoa.c \
              	  srcs/ft_fdlib/ft_printf/ft_long_to_hex.c \
              	  srcs/ft_fdlib/ft_printf/ft_print_chars.c \
              	  srcs/ft_fdlib/ft_printf/ft_print_n_string.c \
              	  srcs/ft_fdlib/ft_printf/ft_print_numbers.c \
              	  srcs/ft_fdlib/ft_printf/ft_printf.c \
              	  srcs/ft_fdlib/ft_printf/ft_string_manipulation.c \
              	  srcs/ft_fdlib/ft_printf/ft_utils.c

#Node_list Manipulation Functions
LINKLIST_SRCS	= srcs/ft_linklist/ft_lstadd_back_bonus.c \
				  srcs/ft_linklist/ft_lstadd_front_bonus.c \
				  srcs/ft_linklist/ft_lstclear_bonus.c \
				  srcs/ft_linklist/ft_lstdelone_bonus.c \
				  srcs/ft_linklist/ft_lstiter_bonus.c \
				  srcs/ft_linklist/ft_lstlast_bonus.c \
				  srcs/ft_linklist/ft_lstmap_bonus.c \
				  srcs/ft_linklist/ft_lstnew_bonus.c \
				  srcs/ft_linklist/ft_lstsize_bonus.c

# Memory Functions
MEMLIB_SRCS		= srcs/ft_memlib/ft_bzero.c \
            	  srcs/ft_memlib/ft_calloc.c \
            	  srcs/ft_memlib/ft_memchr.c \
            	  srcs/ft_memlib/ft_memcmp.c \
            	  srcs/ft_memlib/ft_memcpy.c \
            	  srcs/ft_memlib/ft_memmove.c \
            	  srcs/ft_memlib/ft_memset.c

# String Manipulation Functions
STRMANP_SRCS	= srcs/ft_strmanp/ft_atoi.c \
        		  srcs/ft_strmanp/ft_itoa.c \
        		  srcs/ft_strmanp/ft_split.c \
        		  srcs/ft_strmanp/ft_strchr.c \
        		  srcs/ft_strmanp/ft_strdup.c \
        		  srcs/ft_strmanp/ft_striteri.c \
        		  srcs/ft_strmanp/ft_strjoin.c \
        		  srcs/ft_strmanp/ft_strlcat.c \
        		  srcs/ft_strmanp/ft_strlcpy.c \
        		  srcs/ft_strmanp/ft_strlen.c \
        		  srcs/ft_strmanp/ft_strmapi.c \
        		  srcs/ft_strmanp/ft_strncmp.c \
        		  srcs/ft_strmanp/ft_strnstr.c \
        		  srcs/ft_strmanp/ft_strrchr.c \
        		  srcs/ft_strmanp/ft_strtrim.c \
        		  srcs/ft_strmanp/ft_substr.c

# Combine all source files
SRCS			= $(CHARCHECK_SRCS) \
 		  		  $(FT_PRINTF_SRCS) \
 		  		  $(FDLIB_SRCS) \
				  $(LINKLIST_SRCS) \
				  $(MEMLIB_SRCS) \
				  $(STRMANP_SRCS)

OBJS 			= $(SRCS:.c=.o)

# Compilation Variables
# ============================================

INCS    		= includes
NAME   			= libft.a
LIBC    		= ar rcs
CC      		= cc
CFLAGS  		= -Wall -Werror -Wextra -g
RM      		= rm -f

# Color Codes
PINK 			= \033[38;2;255;105;180m
RESET 			= \033[0m

##############################################
#                Compilation Rules           #
##############################################

# Compile .c files into .o files
.c.o:
	@echo "$(PINK)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

# Link all object files into the library archive
$(NAME): $(OBJS)
	@echo "$(PINK)Creating library $(NAME)...$(RESET)"
	$(LIBC) $@ $^

##############################################
#               Main Commands                #
##############################################

# Default target, builds the library
all: $(NAME)

##############################################
#             Cleaning Commands              #
##############################################

# Remove object files
clean:
	@echo "$(PINK)Cleaning up object files...$(RESET)"
	$(RM) $(OBJS)

# Full clean: remove library files as well
fclean: clean
	@echo "$(PINK)Removing $(NAME) and libft.so...$(RESET)"
	$(RM) $(NAME)

# Rebuild everything from scratch
re: fclean all

##############################################
#                Phony Targets               #
##############################################

.PHONY: all bonus so clean fclean re
