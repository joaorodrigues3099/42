##############################################
#                Makefile for                #
#                Libft Library               #
##############################################

# File Variables
# ============================================

# Combine all source files
SRCS			= srcs/main.c \
				  srcs/utils.c \
				  srcs/tab.c \
				  srcs/checks.c \
				  srcs/quartiles.c

OBJS 			= $(SRCS:.c=.o)

# Compilation Variables
# ============================================

INCS    		= includes
NAME   			= push_swap
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

libft:
	@echo "$(PINK)Compiling Libft...$(RESET)"
	make -C libft all

# Link all object files into the library archive
$(NAME): $(OBJS) libft
	@echo "$(PINK)Creating library $(NAME)...$(RESET)"
	$(CC) $(OBJS) -o $@ -Llibft -lft

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
	make -C libft clean

# Full clean: remove library files as well
fclean: clean
	@echo "$(PINK)Removing $(NAME) and libft.so...$(RESET)"
	$(RM) $(NAME)
	make -C libft fclean

# Rebuild everything from scratch
re: fclean all

##############################################
#                Phony Targets               #
##############################################

.PHONY: libft all bonus so clean fclean re
