# --------------------------------------
# All .c files
SRCS        = ft_printf.c \
              ft_put_characters.c \
              ft_put_numbers.c

# --------------------------------------
# All .o files
OBJS        = $(SRCS:.c=.o)

# --------------------------------------
# Name of the Final lib file
NAME        = libftprintf.a

# --------------------------------------
# Compiler to use
CC          = cc

# --------------------------------------
# Flags to use
CFLAGS      = -Wall -Werror -Wextra

# ----------------------------------------------------------------------------------------------
# Includes location '-I' specifies the include path
INCS        = -I ./

# ----------------------------------------------------------------------------------------------
# Compiler for lib, 'ar' is the tool and 'crs' are the options for compilation
AR          = ar crs

# ----------------------------------------------------------------------------------------------
# Remove files command; 'rm' removes files, 'r' removes directories, 'f' forces removal
RM          = rm -rf

# -------------------------------------------------------------------------------------------------------------------------
# Builds the final static library libftprintf.a by combining the compiled object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
# When running the program, this will execute: 'ar crs libftprintf.a objs'
# -------------------------------------------------------------------------------------------------------------------------

# -------------------------------------------------------------------------------------------------------------------------
# This rule converts .c files to .o files using specified flags and includes
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
# When running the program, this will execute something like: 'cc -Wall -Werror -Wextra -c srcs -o objs -I ./'
# -------------------------------------------------------------------------------------------------------------------------

# --------------------------------------
# 'make all' will build the target $(NAME)
all: $(NAME)

# --------------------------------------
# Clean rule to remove .o files
clean:
	$(RM) $(OBJS)
# Running 'make clean' will remove the .o files

# --------------------------------------
# Full clean: runs 'clean' and also removes the final library
fclean: clean
	$(RM) $(NAME)
# Running 'make fclean' will run 'clean' and also remove libftprintf.a

# -------------------------------------------------------------------------------------------------------------------------
# Rebuild rule: runs 'fclean' to clean everything, then 'all' to build from scratch
re: fclean all

# --------------------------------------
# Specifies phony targets (not associated with files)
.PHONY: all clean fclean re