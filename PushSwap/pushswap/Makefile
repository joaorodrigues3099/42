##################################################################################
#                                     Makefile for                               #
#                                     Lib Library                                #
##################################################################################

#───────────────────────────────────────Compilation───────────────────────────────

INCS   		= includes
LIB_DIR		= lib_2.0
LIB_INCS	= $(LIB_DIR)/includes
NAME   		= push_swap
CC     		= cc
CFLAGS 		= -Wall -Werror -Wextra -g
RM     		= rm -rf

#─────────────────────────────────────────Colors──────────────────────────────────

YELLOW	= \033[38;2;255;248;147m # FFF893 - soft yellow
PINK	= \033[38;2;231;133;190m # E785BE - soft pink
GREEN	= \033[38;2;129;223;164m # 81DFA4 - soft green
RESET	= \033[0m

#───────────────────────────────────────Sources───────────────────────────────────

MAIN_SRCS	= srcs/input.c \
			  srcs/push_swap.c \
			  srcs/ps_utils.c \
			  srcs/sort_small.c \
			  srcs/ops_list.c

OPER_SRCS	= srcs/operations/push.c \
			  srcs/operations/swap.c \
			  srcs/operations/rotate.c \
			  srcs/operations/rev_rotate.c

QUICKSORT_SRCS	= srcs/quicksort/chunk_sort_one_two.c \
			  srcs/quicksort/chunk_sort_three.c \
			  srcs/quicksort/pivots.c \
			  srcs/quicksort/chunk_split.c \
			  srcs/quicksort/chunk_utils.c \
			  srcs/quicksort/move.c \
			  srcs/quicksort/quicksort.c

SRCS		= $(MAIN_SRCS) \
			  $(OPER_SRCS) \
			  $(QUICKSORT_SRCS)

#─────────────────────────────────────────Objects───────────────────────────────────────

OBJ_DIR = objs/pushswap
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS) -I $(LIB_INCS)

#───────────────────────────────────Compilation Commands────────────────────────────────

all: header lib name_text half_progress $(NAME)

$(NAME): header $(OBJS) sec_half_progress
	@$(CC) $(OBJS) -o $@ -L $(LIB_DIR) -l ft

lib:
	@make -C $(LIB_DIR) all --no-print-directory

#─────────────────────────────────────Cleaning Commands──────────────────────────────────

lib_clean:
	@make -C $(LIB_DIR) clean --no-print-directory

pre_clean:
	@$(RM) objs

clean: header lib_clean clean_text half_progress pre_clean sec_half_progress

lib_fclean:
	@make -C $(LIB_DIR) fclean --no-print-directory

pre_fclean: pre_clean
	@$(RM) $(NAME) $(CHECKER)

fclean: header lib_fclean clean_text half_progress pre_fclean fclean_text sec_half_progress

re: fclean new_line all

#─────────────────────────────────────Bonus──────────────────────────────────

CHECKER				= checker
CHECKER_SRCS		= bonus/checker_bonus.c \
					  bonus/checker_utils_bonus.c \
                      $(OPER_SRCS) \
                      srcs/input.c \
                      srcs/ps_utils.c

CHECKER_INCS		= bonus
CHECKER_OBJS_DIR	= objs/checker
CHECKER_OBJS		= $(CHECKER_SRCS:%.c=$(CHECKER_OBJS_DIR)/%.o)

$(CHECKER_OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS) -I $(LIB_INCS) -I $(CHECKER_INCS)

bonus: header lib name_text half_progress $(CHECKER)

$(CHECKER): header $(CHECKER_OBJS) sec_half_progress
	@$(CC) $(CHECKER_OBJS) -o $@ -L $(LIB_DIR) -l ft


#─────────────────────────────────────Animation Rules───────────────────────────────────

header:
	@printf "%b"
	@echo "$(PINK)"
	@echo "█████████████████████████████"
	@echo "        ██  █▓███  ██  █▓███ "
	@echo "joao-alm  █████      █████   "
	@echo "$(YELLOW)"
	@echo "╔═╗┬ ┬┌─┐┬ ┬  ╔═╗┬ ┬┌─┐┌─┐"
	@echo "╠═╝│ │└─┐├─┤  ╚═╗│││├─┤├─┘"
	@echo "╩  └─┘└─┘┴ ┴  ╚═╝└┴┘┴ ┴┴  $(RESET)"

PROGRESS_TEXT ?= Progressing

name_text:
	@$(eval PROGRESS_TEXT = Creating exe)

clean_text:
	@$(eval PROGRESS_TEXT = Removing obj)

fclean_text:
	@$(eval PROGRESS_TEXT = Removing exe)

new_line:
	@echo ""

FORCE: ;

half_progress: FORCE
	@for i in 10 20 30 40 50; do \
		if [ $$i -eq 10 ]; then printf "$(PROGRESS_TEXT) ⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 20 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 30 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 40 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣿⣀⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		if [ $$i -eq 50 ]; then printf "$(PROGRESS_TEXT) ⣿⣿⣿⣿⣿⣀⣀⣀⣀⣀ $$i%%\r"; fi; \
		sleep 0.05; \
	done

sec_half_progress: FORCE
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
.PHONY: all lib clean pre_clean lib_clean fclean pre_fclean lib_fclean re header \
        name_text clean_text fclean_text half_progress sec_half_progress new_line
