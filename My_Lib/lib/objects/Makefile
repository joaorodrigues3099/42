################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	= maketest
CC 		= cc
CFLAGS	= -Wall -Werror -Wextra
AUTHOR	= tmatis
HASH	=

NOVISU 	= 0 # 1 = no progress bar useful when tty is not available

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

FILE_EXTENSION	= .c

SRCS_PATH		= srcs

INCLUDE_PATH	= ./includes

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
              	  srcs/list/lstcpy.c

MEMORY_SRCS		= srcs/memory/ft_memset.c \
                  srcs/memory/ft_bzero.c \
                  srcs/memory/ft_memcpy.c \
                  srcs/memory/ft_memmove.c \
                  srcs/memory/ft_memchr.c \
                  srcs/memory/ft_memcmp.c \
                  srcs/memory/ft_calloc.c \
                  srcs/memory/free_matrix.c \
                  srcs/memory/realloc.c

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

# Combine all source files
SRCS			= $(CONVERSION_SRCS) \
 		  		  $(FT_PRINTF_SRCS) \
 		  		  $(WRITE_SRCS) \
				  $(LIST_SRCS) \
				  $(MEMORY_SRCS) \
				  $(STRING_SRCS)

################################################################################
#                                  Makefile objs                               #
################################################################################

SHELL := /bin/bash

OBJS = $(SRCS:srcs/%.c=objs/%.o)

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

COM_STRING   = "compiling"

ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?),0)
	AUTHOR	:= $(shell git log --format='%aN' | sort -u | awk '{printf "%s, ", $$0}' | rev | cut -c 3- | rev)
	HASH	:= $(shell git rev-parse --short HEAD)
endif

define run_and_test
printf "%b%-46b" "$(COM_COLOR)$(COM_STRING) " "$(OBJ_COLOR)$(@F)$(NO_COLOR)"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
	printf "%b\n" "$(ERROR_COLOR)[✖]$(NO_COLOR)"; \
else \
	printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)"; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

################################################################################
#                                 Makefile rules                               #
################################################################################

all: header $(NAME)

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
	@echo

$(NAME): $(OBJS)
	ar rcs $@ $^

objs/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_PATH)

clean:
	@rm -rf objs
	@echo "$(COM_COLOR)clean: $(OK_COLOR)[✓]$(NO_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COM_COLOR)fclean: $(OK_COLOR)[✓]$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re header
