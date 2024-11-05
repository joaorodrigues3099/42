##############################################
#                Makefile for                #
#                Libft Library               #
##############################################

# File Variables
# ============================================

# String Manipulation Functions
STR_SRCS = ft_strlen.c \
           ft_strlcpy.c \
           ft_strlcat.c \
           ft_strchr.c \
           ft_strrchr.c \
           ft_strncmp.c \
           ft_strnstr.c \
           ft_strdup.c \
           ft_substr.c \
           ft_strjoin.c \
           ft_strtrim.c \
           ft_split.c \
           ft_strmapi.c \
           ft_striteri.c

# Memory Functions
MEM_SRCS = ft_bzero.c \
           ft_memcpy.c \
           ft_memset.c \
           ft_memmove.c \
           ft_memchr.c \
           ft_memcmp.c \
           ft_calloc.c

# Character Check and Conversion Functions
CHAR_SRCS = ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_toupper.c \
            ft_tolower.c

# Conversion and Utility Functions
UTIL_SRCS = ft_atoi.c \
            ft_itoa.c

# File Descriptor Functions
FD_SRCS = ft_putchar_fd.c \
          ft_putstr_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c

# Combine all source files
SRCS = $(STR_SRCS) $(MEM_SRCS) $(CHAR_SRCS) $(UTIL_SRCS) $(FD_SRCS)
OBJS = $(SRCS:.c=.o)

# Bonus Variables
# ============================================

#Node_list Manipulation Functions
BONUS_SRCS = ft_lstnew_bonus.c \
             ft_lstadd_front_bonus.c \
             ft_lstsize_bonus.c \
             ft_lstlast_bonus.c \
             ft_lstadd_back_bonus.c \
             ft_lstdelone_bonus.c \
             ft_lstclear_bonus.c \
             ft_lstiter_bonus.c \
             ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Compilation Variables
# ============================================

INCS    = ./
NAME    = libft.a
LIBC    = ar rc
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g
RM      = rm -f

# Color Codes
PINK = \033[38;2;255;105;180m
RESET = \033[0m

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
	$(CC) $^

##############################################
#               Main Commands                #
##############################################

# Default target, builds the library
all: $(NAME)

# Bonus target, includes additional linked list functions
bonus: $(OBJS) $(BONUS_OBJS)
	@echo "$(PINK)Adding bonus files to $(NAME)...$(RESET)"
	$(LIBC) $(NAME) $(OBJS) $(BONUS_OBJS)

# Create shared library
so:
	@echo "$(PINK)Creating shared library libft.so...$(RESET)"
	$(CC) -nostartfiles -fPIC ${CFLAGS} ${SRCS}
	$(CC) -nostartfiles -shared -o libft.so ${OBJS} $(BONUS_OBJS)

##############################################
#             Cleaning Commands              #
##############################################

# Remove object files
clean:
	@echo "$(PINK)Cleaning up object files...$(RESET)"
	$(RM) $(OBJS) $(BONUS_OBJS)

# Full clean: remove library files as well
fclean: clean
	@echo "$(PINK)Removing $(NAME) and libft.so...$(RESET)"
	$(RM) $(NAME)
	$(RM) libft.so

# Rebuild everything from scratch
re: fclean all

##############################################
#                Phony Targets               #
##############################################

.PHONY: all bonus so clean fclean re