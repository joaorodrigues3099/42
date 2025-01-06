########################################################################################
#             ▗▖   ▗▄▄▄▖▗▄▄▖     ▗▖  ▗▖ ▗▄▖ ▗▖ ▗▖▗▄▄▄▖▗▄▄▄▖▗▄▄▄▖▗▖   ▗▄▄▄▖             #
#             ▐▌     █  ▐▌ ▐▌    ▐▛▚▞▜▌▐▌ ▐▌▐▌▗▞▘▐▌   ▐▌     █  ▐▌   ▐▌                #
#             ▐▌     █  ▐▛▀▚▖    ▐▌  ▐▌▐▛▀▜▌▐▛▚▖ ▐▛▀▀▘▐▛▀▀▘  █  ▐▌   ▐▛▀▀▘             #
#             ▐▙▄▄▖▗▄█▄▖▐▙▄▞▘    ▐▌  ▐▌▐▌ ▐▌▐▌ ▐▌▐▙▄▄▖▐▌   ▗▄█▄▖▐▙▄▄▖▐▙▄▄▖             #
########################################################################################

#───────────────────────────────────────Compilation───────────────────────────────

INCS   			= includes
NAME   			= libft.a
LIBC   			= ar rcs
CC     			= cc
CFLAGS 			= -Wall -Werror -Wextra -g
RM     			= rm -rf

CONVERSION_SRCS	= srcs/conversion/ft_itoa.c \
                  srcs/conversion/ft_atoi.c \
                  srcs/conversion/ft_tolower.c \
                  srcs/conversion/ft_toupper.c \
                  srcs/conversion/atoll_valid.c

FT_PRINTF_SRCS	= srcs/lib_print/ft_printf.c \
                  srcs/lib_print/put_characters.c \
                  srcs/lib_print/put_numbers.c \
                  srcs/lib_print/print_error.c

SRCS			= $(CONVERSION_SRCS) \
 		  		  $(FT_PRINTF_SRCS)

OBJS_DIR 		= .objs
OBJS 			= $(SRCS:%.c=$(OBJS_DIR)/%.o)

#─────────────────────────────────────────Extras──────────────────────────────────

YELLOW			= \033[38;2;255;248;147m
PINK			= \033[38;2;231;133;190m
GREEN			= \033[38;2;129;223;164m
BOLD			= \033[1m
RESET			= \033[0m

MFA_DIR			= $(OBJS_DIR)/makefile_anim
MFA_NAME_HEADER	= $(MFA_DIR)/mfa_name_header

all: $(NAME)

$(NAME):  $(MFA_NAME_HEADER) $(OBJS)
	@$(LIBC) $@ $(OBJS)
	@printf "$(BOLD)$(GREEN)>>>$(RESET) $(YELLOW)$(BOLD)$@ $(RESET)compiled $(BOLD)$(GREEN)successfully$(RESET)\n"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "Compiling $(BOLD)$(notdir $<) $(RESET)into $(BOLD)$(notdir $@)$(RESET)..."
	@cc $(CFLAGS) -c $< -o $@ -I $(INCS)
	@printf " $(GREEN)$(BOLD)[✔]$(RESET)\n"

clean:
	@$(RM) $(MFA_NAME_HEADER)
	@if [ -d "$(OBJS_DIR)" ]; then \
      		echo "\n$(YELLOW)────────────── Cleaning $(BOLD)[$(NAME)] $(RESET)$(YELLOW)──────────────$(RESET)"; \
    		$(RM) $(OBJS_DIR); \
    		echo "$(BOLD)$(GREEN)>>>$(RESET) $(YELLOW)$(BOLD)[$(NAME)] $(RESET)objects removed $(BOLD)$(GREEN)successfully$(RESET)"; \
    	else \
    		echo "Nothing to be done for 'clean'."; \
    fi

fclean:
	@$(RM) $(MFA_NAME_HEADER)
	@if [ -d "$(OBJS_DIR)" ] || [ -f "$(NAME)" ]]; then \
    		echo "\n$(YELLOW)────────────── Cleaning $(BOLD)[$(NAME)] $(RESET)$(YELLOW)──────────────$(RESET)"; \
    		if [ -d "$(OBJS_DIR)" ]; then \
    			$(RM) $(OBJS_DIR); \
    			echo "$(BOLD)$(GREEN)>>>$(RESET) $(YELLOW)$(BOLD)[$(NAME)] $(RESET)objects removed $(BOLD)$(GREEN)successfully$(RESET)"; \
    		fi; \
    		if [ -f "$(NAME)" ]; then \
    			$(RM) $(NAME); \
    			echo "$(BOLD)$(GREEN)>>>$(RESET) $(YELLOW)$(BOLD)[$(NAME)] $(RESET)removed $(BOLD)$(GREEN)successfully$(RESET)"; \
    		fi; \
        else \
        	echo "Nothing to be done for 'fclean'."; \
        fi

re: fclean all

$(MFA_NAME_HEADER):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(MFA_DIR)
	@echo "\n$(YELLOW)────────────── Generating $(BOLD)[$(NAME)]$(RESET)$(YELLOW) ──────────────$(RESET)"
	@touch $(MFA_NAME_HEADER)

.PHONY: all clean fclean re