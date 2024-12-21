# --------------------------------------
# All .c files
SRCS = ft_printf.c \
       ft_put_characters.c \
       ft_put_numbers.c

# --------------------------------------
# All .o files
OBJS = $(SRCS:.c=.o)

# --------------------------------------
# Name of the Final lib file
NAME = libftprintf.a

# --------------------------------------
# Compiler to use
CC = cc

# --------------------------------------
# Flags to use
CFLAGS = -Wall -Werror -Wextra

# --------------------------------------
# Includes location '-I' specifies the include path
INCS = -I ./

# --------------------------------------
# Library creation tool and options
AR = ar crs

# --------------------------------------
# LIBFT's location
LIBFT = libft/libft.a

# --------------------------------------
# Remove files, 'rm' with '-r' removes directories and '-f' forces removal
RM = rm -rf

# --------------------------------------
# Default rule: builds everything
all: libft $(NAME)

# -------------------------------------------------------------------------
# Rule to compile .c files into .o files
# $< represents the first prerequisite (source file)
# $@ represents the target (object file)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
# -------------------------------------------------------------------------

# --------------------------------------
# Builds libft.a by navigating to libft directory
libft:
	make -C libft all

# -------------------------------------------------------------------------
# Builds the final static library libftprintf.a by combining libft.a with
# the compiled object files
$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
# -------------------------------------------------------------------------

# --------------------------------------
# Clean rule to remove .o files
clean:
	$(RM) $(OBJS)
	make -C libft clean

# --------------------------------------
# Full clean: runs 'clean' and also removes the final library
fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

# -------------------------------------------------------------------------
# Rebuilds the project: runs 'fclean' and then 'all'
re: fclean all
# -------------------------------------------------------------------------

# --------------------------------------
# Specifies phony targets (not associated with files)
.PHONY: all clean fclean re libft
# --------------------------------------