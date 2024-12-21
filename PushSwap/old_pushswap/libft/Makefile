##############################################
#                Makefile for                #
#                Libft Library               #
##############################################

# File Variables
# ============================================

# Character Check and Conversion Functions
CHARCHECK_SRCS	= srcs/charlib/ft_isalnum.c \
           		  srcs/charlib/ft_isalpha.c \
           		  srcs/charlib/ft_isascii.c \
           		  srcs/charlib/ft_isdigit.c \
           		  srcs/charlib/ft_isprint.c \
           		  srcs/charlib/ft_tolower.c \
           		  srcs/charlib/ft_toupper.c

# File Descriptor Functions
FDLIB_SRCS		= srcs/fdlib/ft_putchar_fd.c \
          		  srcs/fdlib/ft_putendl_fd.c \
          		  srcs/fdlib/ft_putnbr_fd.c \
          		  srcs/fdlib/ft_putstr_fd.c

# FT_Printf Functions
FT_PRINTF_SRCS	= srcs/fdlib/ft_printf/ft_unsigned_itoa.c \
              	  srcs/fdlib/ft_printf/ft_long_to_hex.c \
              	  srcs/fdlib/ft_printf/ft_print_chars.c \
              	  srcs/fdlib/ft_printf/ft_print_n_string.c \
              	  srcs/fdlib/ft_printf/ft_print_numbers.c \
              	  srcs/fdlib/ft_printf/ft_printf.c \
              	  srcs/fdlib/ft_printf/ft_string_manipulation.c \
              	  srcs/fdlib/ft_printf/ft_utils.c

#Node_list Manipulation Functions
LINKLIST_SRCS	= srcs/listlib/ft_lstadd_back_bonus.c \
				  srcs/listlib/ft_lstadd_front_bonus.c \
				  srcs/listlib/ft_lstclear_bonus.c \
				  srcs/listlib/ft_lstdelone_bonus.c \
				  srcs/listlib/ft_lstiter_bonus.c \
				  srcs/listlib/ft_lstlast_bonus.c \
				  srcs/listlib/ft_lstmap_bonus.c \
				  srcs/listlib/ft_lstnew_bonus.c \
				  srcs/listlib/ft_lstsize_bonus.c \
				  srcs/listlib/jr_lstcpy.c

# Memory Functions
MEMLIB_SRCS		= srcs/memlib/ft_bzero.c \
            	  srcs/memlib/ft_calloc.c \
            	  srcs/memlib/ft_memchr.c \
            	  srcs/memlib/ft_memcmp.c \
            	  srcs/memlib/ft_memcpy.c \
            	  srcs/memlib/ft_memmove.c \
            	  srcs/memlib/ft_memset.c \
            	  srcs/memlib/jr_free_matrix.c \
            	  srcs/memlib/jr_realloc.c \
            	  srcs/memlib/jr_dup_data.c \
            	  srcs/memlib/jr_abs.c \

# String Manipulation Functions
STRMANP_SRCS	= srcs/strlib/ft_atoi.c \
        		  srcs/strlib/ft_itoa.c \
        		  srcs/strlib/ft_split.c \
        		  srcs/strlib/ft_strchr.c \
        		  srcs/strlib/ft_strdup.c \
        		  srcs/strlib/ft_striteri.c \
        		  srcs/strlib/ft_strjoin.c \
        		  srcs/strlib/ft_strlcat.c \
        		  srcs/strlib/ft_strlcpy.c \
        		  srcs/strlib/ft_strlen.c \
        		  srcs/strlib/ft_strmapi.c \
        		  srcs/strlib/ft_strncmp.c \
        		  srcs/strlib/ft_strnstr.c \
        		  srcs/strlib/ft_strrchr.c \
        		  srcs/strlib/ft_strtrim.c \
        		  srcs/strlib/ft_substr.c \
        		  srcs/strlib/jr_atoi_check_int.c

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
