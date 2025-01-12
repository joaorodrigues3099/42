########################################################################################
#                                      ▗▖   ▗▄▄▄▖▗▄▄▖                                  #
#                                      ▐▌     █  ▐▌ ▐▌                                 #
#                                      ▐▌     █  ▐▛▀▚▖                                 #
#                                      ▐▙▄▄▖▗▄█▄▖▐▙▄▞▘                                 #
########################################################################################

#─────────────────────────────────────── Compilation ──────────────────────────────────

NAME           = libmylib.a
LIBC           = ar rcs
CC             = cc
CFLAGS         = -Wall -Werror -Wextra -g
RM             = rm -rf

#─────────────────────────────────────── Source Files ─────────────────────────────────

CHAR_SRCS      = src/char/ft_isalnum.c \
                 src/char/ft_isalpha.c \
                 src/char/ft_isascii.c \
                 src/char/ft_isdigit.c \
                 src/char/ft_isprint.c

CONVERSION_SRCS= src/conversion/ft_itoa.c \
                 src/conversion/ft_atoi.c \
                 src/conversion/ft_tolower.c \
                 src/conversion/ft_toupper.c \
                 src/conversion/atoll_valid.c

GNL_SRCS       = src/gnl/get_next_line.c \
                 src/gnl/get_next_line_utils.c

LIST_SRCS      = src/list/ft_lstadd_back_bonus.c \
                 src/list/ft_lstadd_front_bonus.c \
                 src/list/ft_lstclear_bonus.c \
                 src/list/ft_lstdelone_bonus.c \
                 src/list/ft_lstiter_bonus.c \
                 src/list/ft_lstlast_bonus.c \
                 src/list/ft_lstmap_bonus.c \
                 src/list/ft_lstnew_bonus.c \
                 src/list/ft_lstsize_bonus.c \
                 src/list/lstdel_safely.c \
                 src/list/lstnew_int.c \
                 src/list/lstget_int.c \
                 src/list/lstdup.c

MEMORY_SRCS    = src/memory/free_matrix.c \
                 src/memory/ft_bzero.c \
                 src/memory/ft_calloc.c \
                 src/memory/ft_memchr.c \
                 src/memory/ft_memcmp.c \
                 src/memory/ft_memcpy.c \
                 src/memory/ft_memmove.c \
                 src/memory/ft_memset.c \
                 src/memory/realloc.c \
                 src/memory/sort_tab.c

PRINT_SRCS     = src/print/ft_printf.c \
                 src/print/put_characters.c \
                 src/print/put_numbers.c \
                 src/print/print_error.c

STRING_SRCS    = src/string/ft_split.c \
                 src/string/ft_strchr.c \
                 src/string/ft_strdup.c \
                 src/string/ft_striteri.c \
                 src/string/ft_strjoin.c \
                 src/string/ft_strlcat.c \
                 src/string/ft_strlcpy.c \
                 src/string/ft_strlen.c \
                 src/string/ft_strmapi.c \
                 src/string/ft_strncmp.c \
                 src/string/ft_strnstr.c \
                 src/string/ft_strrchr.c \
                 src/string/ft_strtrim.c \
                 src/string/ft_substr.c \
                 src/string/strcpy.c

SRCS			= $(CHAR_SRCS) \
                  $(CONVERSION_SRCS)
                  #$(GNL_SRCS) \
                  #$(LIST_SRCS) \
                  #$(MEMORY_SRCS) \
                  #$(PRINT_SRCS) \
                  #$(STRING_SRCS)
INCS			= -Iinclude
OBJS_DIR		= .objs
OBJS			= $(SRCS:%.c=$(OBJS_DIR)/%.o)

mfa_h_len		= 49
yellow 			= \033[38;2;255;248;147m
pink			= \033[1m\033[38;2;231;133;190m
green			= \033[1m\033[38;2;129;223;164m
reset			= \033[0m
spaces			= "                                                                                                   "
debug_on		= .debug_on

#─────────────────────────────────────── Build Targets ────────────────────────────────
all: $(NAME)

$(NAME): $(OBJS)
	@if [ -f "$(debug_on)" ]; then \
		echo "$(LIBC) $@ $(OBJS)"; \
  		$(LIBC) $@ $(OBJS); \
  	else \
		$(LIBC) $@ $(OBJS); \
	fi

$(OBJS_DIR)/%.o: %.c
	@if [ -f "$(debug_on)" ]; then \
		echo "mkdir -p $(dir $@)"; \
  		mkdir -p $(dir $@); \
  		echo "$(CC) $(CFLAGS) -c $< -o $@ $(INCS)"; \
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS); \
	else \
		mkdir -p $(dir $@); \
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS); \
		make mfa_object mfa_name="$(notdir $@)" mfa_symbol="$(green)[✔]"; \
	fi

clean:
	@if [ -f "$(debug_on)" ]; then \
  		echo "$(RM) $(OBJS_DIR)"; \
		$(RM) $(OBJS_DIR); \
	else \
		if [ -f "$(OBJS_DIR)" ]; then \
        	$(RM) $(OBJS_DIR); \
        	make mfa_object mfa_name="mylib objects" mfa_symbol="$(green)[✖]" --no-print-directory; \
        else \
        	printf "Nothing to be removed\n"; \
        fi; \
    fi

fclean:
	@if [ -f "$(debug_on)" ]; then \
      		echo "$(RM) $(NAME)"; \
    		$(RM) $(NAME); \
  	else \
  		if [ -f "$(NAME)" ] || [ -f "$(OBJS_DIR)" ]; then \
      		$(RM) $(NAME); \
      		make mfa_object mfa_name="libmylib.a" mfa_symbol="$(green)[✖]" --no-print-directory; \
      	else \
      		printf "Nothing to be removed\n"; \
      	fi; \
    fi

re: fclean all

mfa_compiling:
	@make mfa_line_message mfa_name1="$(yellow)Compiling [$(mfa_name)] /" mfa_name2="$(reset)\\n" mfa_line="─" --no-print-directory

mfa_object:
	@make mfa_line_message mfa_name1="$(mfa_name)" mfa_name2="$(mfa_symbol)$(reset)\\n" mfa_line=" " --no-print-directory

mfa_removing:
	@make mfa_line_message mfa_name1="$(pink)Removing [$(mfa_name)] /" mfa_name2="$(reset)\\n" mfa_line="─" --no-print-directory

mfa_success:
	@make mfa_line_message mfa_name1="$(green)" mfa_name2="/ Success$(reset)\\n" mfa_line="─" --no-print-directory

mfa_line_message:
	@name1_len=$$(echo -n "$(mfa_name1)" | sed -E 's/\x1b\[[0-9;]*m//g' | wc -m); \
		name2_len=$$(($(shell echo -n "$(mfa_name2)" | sed -E 's/\x1b\[[0-9;]*m//g' | wc -m) )); \
		line_len=$$(($(mfa_h_len) - $$name1_len - $$name2_len)); \
		printf "$(mfa_name1)"; \
		for i in $$(seq 1 $$line_len); do \
			$(if $(mfa_line), printf "$(mfa_line)", printf " "); \
		done; \
		printf "$(mfa_name2)";

debug:
	@if [ ! -f "$(debug_on)" ]; then \
		touch $(debug_on); \
		make mfa_line_message mfa_name1="$(green)Debug Mode /" mfa_name2="/ ON$(reset)\\n" mfa_line="─" --no-print-directory; \
	else \
	  	$(RM) $(debug_on); \
	  	make mfa_line_message mfa_name1="$(pink)Debug Mode /" mfa_name2="/ OFF$(reset)\\n" mfa_line="─" --no-print-directory; \
	fi
#───────────────────────────────────────── Phony Targets ──────────────────────────────

.PHONY: all clean fclean re
