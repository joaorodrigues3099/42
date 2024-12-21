##################################################################################
#                                     Makefile for                               #
#                                     Lib Library                                #
##################################################################################

#───────────────────────────────────────Compilation───────────────────────────────

INCS   	= includes
NAME   	= libft.a
LIBC   	= ar rcs
CC     	= cc
CFLAGS 	= -Wall -Werror -Wextra -g
RM     	= rm -rf

#─────────────────────────────────────────Colors──────────────────────────────────

YELLOW	= \033[38;2;255;248;147m # FFF893 - soft yellow
PINK	= \033[38;2;231;133;190m # E785BE - soft pink
GREEN	= \033[38;2;129;223;164m # 81DFA4 - soft green
RESET	= \033[0m

#───────────────────────────────────────Sources───────────────────────────────────

CONVERSION_SRCS	= srcs/conversion/ft_itoa.c \
                  srcs/conversion/ft_atoi.c \
                  srcs/conversion/ft_tolower.c \
                  srcs/conversion/ft_toupper.c \
                  srcs/conversion/atoll_valid.c

FT_PRINTF_SRCS	= srcs/ft_printf/ft_printf.c \
                  srcs/ft_printf/long_to_hex.c \
                  srcs/ft_printf/print_chars.c \
                  srcs/ft_printf/print_n_string.c \
                  srcs/ft_printf/print_numbers.c \
                  srcs/ft_printf/unsigned_itoa.c \
                  srcs/ft_printf/utils.c

LIST_SRCS		= srcs/list/ft_lstadd_back_bonus.c \
              	  srcs/list/ft_lstadd_front_bonus.c \
              	  srcs/list/ft_lstclear_bonus.c \
              	  srcs/list/ft_lstdelone_bonus.c \
              	  srcs/list/ft_lstiter_bonus.c \
              	  srcs/list/ft_lstlast_bonus.c \
              	  srcs/list/ft_lstmap_bonus.c \
              	  srcs/list/ft_lstnew_bonus.c \
              	  srcs/list/ft_lstsize_bonus.c \
              	  srcs/list/lstdetach.c \
              	  srcs/list/lstdup.c \
              	  srcs/list/lstdel_safely.c \
              	  srcs/list/lstnew_int.c \
              	  srcs/list/lstget_int.c

MEMORY_SRCS		= srcs/memory/ft_memset.c \
                  srcs/memory/ft_bzero.c \
                  srcs/memory/ft_memcpy.c \
                  srcs/memory/ft_memmove.c \
                  srcs/memory/ft_memchr.c \
                  srcs/memory/ft_memcmp.c \
                  srcs/memory/ft_calloc.c \
                  srcs/memory/free_matrix.c \
                  srcs/memory/realloc.c \
                  srcs/memory/sort_tab.c

STRING_SRCS		= srcs/string/ft_strlen.c \
                  srcs/string/ft_strlcpy.c \
                  srcs/string/ft_strlcat.c \
                  srcs/string/ft_strchr.c \
                  srcs/string/ft_strrchr.c \
                  srcs/string/ft_strncmp.c \
                  srcs/string/ft_strnstr.c \
                  srcs/string/ft_strdup.c \
                  srcs/string/ft_substr.c \
                  srcs/string/ft_strjoin.c \
                  srcs/string/ft_strtrim.c \
                  srcs/string/ft_split.c \
                  srcs/string/ft_strmapi.c \
                  srcs/string/ft_striteri.c \
                  srcs/string/ft_isalnum.c \
                  srcs/string/ft_isalpha.c \
                  srcs/string/ft_isascii.c \
                  srcs/string/ft_isdigit.c \
                  srcs/string/ft_isprint.c

WRITE_SRCS		= srcs/write/ft_putchar_fd.c \
                  srcs/write/ft_putendl_fd.c \
                  srcs/write/ft_putnbr_fd.c \
                  srcs/write/ft_putstr_fd.c

SRCS			= $(CONVERSION_SRCS) \
 		  		  $(FT_PRINTF_SRCS) \
 		  		  $(WRITE_SRCS) \
				  $(LIST_SRCS) \
				  $(MEMORY_SRCS) \
				  $(STRING_SRCS)

#─────────────────────────────────────────Objects───────────────────────────────────────

OBJ_DIR = objs
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

#───────────────────────────────────Compilation Commands────────────────────────────────

all: name_text half_progress $(NAME)

$(NAME): $(OBJS) sec_half_progress
	@$(LIBC) $@ $(OBJS)

#─────────────────────────────────────Cleaning Commands──────────────────────────────────

pre_clean:
	@$(RM) $(OBJ_DIR)

clean: clean_text half_progress pre_clean sec_half_progress

pre_fclean: pre_clean
	@$(RM) $(NAME)

fclean: clean_text half_progress pre_fclean sec_half_progress

re: fclean all

#─────────────────────────────────────Animation Rules───────────────────────────────────

PROGRESS_TEXT ?= Progressing

name_text:
	@$(eval PROGRESS_TEXT = Creating lib)

clean_text:
	@$(eval PROGRESS_TEXT = Removing lib)


half_progress:
	@for i in 10 20 30 40 50; do \
		if [ $$i -eq 10 ]; then printf "$(PROGRESS_TEXT) ⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 20 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 30 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 40 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣿⣀⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 50 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣿⣿⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		sleep 0.05; \
	done

sec_half_progress:
	@for i in 60 70 80 90 100; do \
		if [ $$i -eq 60 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣿⣿⣿⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 70 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣿⣿⣿⣿⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 80 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣿⣿⣿⣿⣿⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 90 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣀ $$i%%\r"; fi; \
		if [ $$i -eq 100 ]; then printf "$(PROGRESS_TEXT) $(GREEN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ $$i%%$(RESET)"; fi; \
		sleep 0.05; \
	done; \
	echo "$(RESET)"

#────────────────────────────────────────Phony Targets─────────────────────────────────────

.PHONY: all clean fclean re header objs_msg name_msg clean_msg fclean_msg dot_animation