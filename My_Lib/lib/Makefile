########################################################################################
#                                      ▗▖   ▗▄▄▄▖▗▄▄▖                                  #
#                                      ▐▌     █  ▐▌ ▐▌                                 #
#                                      ▐▌     █  ▐▛▀▚▖                                 #
#                                      ▐▙▄▄▖▗▄█▄▖▐▙▄▞▘                                 #
########################################################################################

#─────────────────────────────────────── Compilation ──────────────────────────────────

NAME           = libft.a
LIBC           = ar rcs
CC             = cc
CFLAGS         = -Wall -Werror -Wextra -g
RM             = rm -rf

#─────────────────────────────────────── Source Files ─────────────────────────────────

CHAR_SRCS      = srcs/char/ft_isalnum.c \
                 srcs/char/ft_isalpha.c \
                 srcs/char/ft_isascii.c \
                 srcs/char/ft_isdigit.c \
                 srcs/char/ft_isprint.c

CONVERSION_SRCS= srcs/conversion/ft_itoa.c \
                 srcs/conversion/ft_atoi.c \
                 srcs/conversion/ft_tolower.c \
                 srcs/conversion/ft_toupper.c \
                 srcs/conversion/atoll_valid.c

GNL_SRCS       = srcs/gnl/get_next_line.c \
                 srcs/gnl/get_next_line_utils.c

LIST_SRCS      = srcs/list/ft_lstadd_back_bonus.c \
                 srcs/list/ft_lstadd_front_bonus.c \
                 srcs/list/ft_lstclear_bonus.c \
                 srcs/list/ft_lstdelone_bonus.c \
                 srcs/list/ft_lstiter_bonus.c \
                 srcs/list/ft_lstlast_bonus.c \
                 srcs/list/ft_lstmap_bonus.c \
                 srcs/list/ft_lstnew_bonus.c \
                 srcs/list/ft_lstsize_bonus.c \
                 srcs/list/lstdel_safely.c \
                 srcs/list/lstnew_int.c \
                 srcs/list/lstget_int.c \
                 srcs/list/lstdup.c

MEMORY_SRCS    = srcs/memory/free_matrix.c \
                 srcs/memory/ft_bzero.c \
                 srcs/memory/ft_calloc.c \
                 srcs/memory/ft_memchr.c \
                 srcs/memory/ft_memcmp.c \
                 srcs/memory/ft_memcpy.c \
                 srcs/memory/ft_memmove.c \
                 srcs/memory/ft_memset.c \
                 srcs/memory/realloc.c \
                 srcs/memory/sort_tab.c

PRINT_SRCS     = srcs/print/ft_printf.c \
                 srcs/print/put_characters.c \
                 srcs/print/put_numbers.c \
                 srcs/print/print_error.c

STRING_SRCS    = srcs/string/ft_split.c \
                 srcs/string/ft_strchr.c \
                 srcs/string/ft_strdup.c \
                 srcs/string/ft_striteri.c \
                 srcs/string/ft_strjoin.c \
                 srcs/string/ft_strlcat.c \
                 srcs/string/ft_strlcpy.c \
                 srcs/string/ft_strlen.c \
                 srcs/string/ft_strmapi.c \
                 srcs/string/ft_strncmp.c \
                 srcs/string/ft_strnstr.c \
                 srcs/string/ft_strrchr.c \
                 srcs/string/ft_strtrim.c \
                 srcs/string/ft_substr.c \
                 srcs/string/strcpy.c

SRCS			= $(CHAR_SRCS) \
                  $(CONVERSION_SRCS) \
                  $(GNL_SRCS) \
                  $(LIST_SRCS) \
                  $(MEMORY_SRCS) \
                  $(PRINT_SRCS) \
                  $(STRING_SRCS)
INCS			= -Iincludes
OBJS_DIR		= .objs
OBJS			= $(SRCS:%.c=$(OBJS_DIR)/%.o)

#─────────────────────────────────────── Build Targets ────────────────────────────────
all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $@ $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all


#───────────────────────────────────────── Phony Targets ──────────────────────────────

.PHONY: all clean fclean re
