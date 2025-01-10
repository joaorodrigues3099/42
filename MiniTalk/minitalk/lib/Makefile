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

CHAR_SRCS      = char/ft_isalnum.c \
                 char/ft_isalpha.c \
                 char/ft_isascii.c \
                 char/ft_isdigit.c \
                 char/ft_isprint.c

CONVERSION_SRCS= conversion/ft_itoa.c \
                 conversion/ft_atoi.c \
                 conversion/ft_tolower.c \
                 conversion/ft_toupper.c \
                 conversion/atoll_valid.c

GNL_SRCS       = gnl/get_next_line.c \
                 gnl/get_next_line_utils.c

LIST_SRCS      = list/ft_lstadd_back_bonus.c \
                 list/ft_lstadd_front_bonus.c \
                 list/ft_lstclear_bonus.c \
                 list/ft_lstdelone_bonus.c \
                 list/ft_lstiter_bonus.c \
                 list/ft_lstlast_bonus.c \
                 list/ft_lstmap_bonus.c \
                 list/ft_lstnew_bonus.c \
                 list/ft_lstsize_bonus.c \
                 list/lstdel_safely.c \
                 list/lstnew_int.c \
                 list/lstget_int.c \
                 list/lstdup.c

MEMORY_SRCS    = memory/free_matrix.c \
                 memory/ft_bzero.c \
                 memory/ft_calloc.c \
                 memory/ft_memchr.c \
                 memory/ft_memcmp.c \
                 memory/ft_memcpy.c \
                 memory/ft_memmove.c \
                 memory/ft_memset.c \
                 memory/realloc.c \
                 memory/sort_tab.c

PRINT_SRCS     = print/ft_printf.c \
                 print/put_characters.c \
                 print/put_numbers.c \
                 print/print_error.c

STRING_SRCS    = string/ft_split.c \
                 string/ft_strchr.c \
                 string/ft_strdup.c \
                 string/ft_striteri.c \
                 string/ft_strjoin.c \
                 string/ft_strlcat.c \
                 string/ft_strlcpy.c \
                 string/ft_strlen.c \
                 string/ft_strmapi.c \
                 string/ft_strncmp.c \
                 string/ft_strnstr.c \
                 string/ft_strrchr.c \
                 string/ft_strtrim.c \
                 string/ft_substr.c \
                 string/strcpy.c

SRCS           = $(CHAR_SRCS) \
                 $(CONVERSION_SRCS) \
                 $(PRINT_SRCS)
                 #$(GNL_SRCS) \
                 #$(LIST_SRCS) \
                 #$(MEMORY_SRCS) \
                 #$(STRING_SRCS)

OBJS_DIR       = .objs
OBJS           = $(SRCS:%.c=$(OBJS_DIR)/%.o)

#─────────────────────────────────────── Color Codes ──────────────────────────────────

YELLOW			= \033[0m\033[38;2;255;248;147m
B_YELLOW		= \033[1m\033[38;2;255;248;147m
PINK			= \033[0m\033[38;2;231;133;190m
B_PINK			= \033[1m\\033[38;2;231;133;190m
GREEN			= \033[0m\033[38;2;129;223;164m
B_GREEN			= \033[1m\\033[38;2;129;223;164m
B_BASE			= \033[0m\033[1m
BASE			= \033[0m

#─────────────────────────────────────── MFA Settings ─────────────────────────────────

MFA_DIR        = $(OBJS_DIR)/makefile_anim
MFA_NAME_HEADER= $(MFA_DIR)/mfa_name_header

#─────────────────────────────────────── Build Targets ────────────────────────────────

all: $(NAME)

$(NAME): $(MFA_NAME_HEADER) $(OBJS)
	@$(LIBC) $@ $(OBJS)
	@echo "$(B_GREEN)>>> $(B_BASE)[$@] $(BASE)compiled $(B_GREEN)successfully$(BASE)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -n "$(GREEN)Compiling $(B_BASE)$(notdir $<) $(BASE)into $(B_BASE)$(notdir $@)$(BASE)..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " $(GREEN)$(BOLD)[✔]$(RESET)"

#───────────────────────────────────────── Cleaning ───────────────────────────────────

clean:
	@$(RM) $(MFA_NAME_HEADER)
	@if [ -d "$(OBJS_DIR)" ]; then \
		echo "\n$(PINK)───────────────── Cleaning $(B_PINK)[$(NAME)] $(PINK)────────────────────$(BASE)"; \
		$(RM) $(OBJS_DIR); \
		echo "$(B_GREEN)>>> $(B_BASE)[$(NAME)] $(BASE)objects removed $(B_GREEN)successfully$(BASE)"; \
	else \
		echo "Nothing to be done for 'clean'."; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(RM) $(NAME); \
		echo "$(B_GREEN)>>> $(B_BASE)[$(NAME)] $(BASE)removed $(B_GREEN)successfully$(BASE)"; \
	else \
		echo "Nothing to be done for 'fclean'."; \
	fi

re: fclean all

#───────────────────────────────────────── Extras ───────────────────────────────────

$(MFA_NAME_HEADER):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(MFA_DIR)
	@echo "\n$(YELLOW)────────────────── Generating $(B_YELLOW)[$(NAME)]$(YELLOW) ─────────────────$(BASE)"
	@touch $(MFA_NAME_HEADER)

#───────────────────────────────────────── Phony Targets ──────────────────────────────

.PHONY: all clean fclean re
