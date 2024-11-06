##############################################
#                Makefile for                #
#                FT_Printf Library           #
##############################################

# Base Variables
# ============================================

# Base Sources
SRCS 		= ft_printf.c \
			  ft_put_characters.c \
			  ft_put_numbers.c

# Base Objects
OBJS 		= $(SRCS:.c=.o)

# Compilation Variables
# ============================================

NAME 		= libftprintf.a
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -g
INCS 		= -I .
AR			= ar crs
RM			= rm -rf

# Color Codes
# ============================================
PINK 		= \033[38;2;255;105;180m
RESET 		= \033[0m

##############################################
#                Compilation Rules           #
##############################################

# Compile .c files into .o files
.c.o:
		@echo "$(PINK)Compiling $<...$(RESET)"
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

# Link all base object files into the base library archive
$(NAME): $(OBJS)
		@echo "$(PINK)Creating base library $(NAME)...$(RESET)"
		$(AR) $@ $^

##############################################
#               Main Commands                #
##############################################

# Default target, builds the base library only
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
		@echo "$(PINK)Removing $(NAME)...$(RESET)"
		$(RM) $(NAME)

# Rebuild everything from scratch
re: fclean all

##############################################
#                Phony Targets               #
##############################################

.PHONY: all clean fclean re
