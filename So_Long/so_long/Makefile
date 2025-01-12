#################################################################################
#                           ▗▄▄▖ ▗▄▖ ▗▖    ▗▄▖ ▗▖  ▗▖ ▗▄▄▖                      #
#                          ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌▐▛▚▖▐▌▐▌                         #
#                           ▝▀▚▖▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌ ▝▜▌▐▌▝▜▌                      #
#                          ▗▄▄▞▘▝▚▄▞▘▐▙▄▄▖▝▚▄▞▘▐▌  ▐▌▝▚▄▞▘                      #
#################################################################################

#──────────────────────────────────── Bases ─────────────────────────────────────
NAME		= so_long
CC         	= cc
CFLAGS     	= -Wall -Werror -Wextra -g
RM         	= rm -rf

#─────────────────────────────────── Mlx Files ───────────────────────────────────
MLX_DIR		= $(LIBS_DIR)/mlx
MLX			= $(MLX_DIR)/libmlx.a
MLX_INCS	= -I$(MLX_DIR)
MLX_ADD		= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

#────────────────────────────────── MyLib Files ──────────────────────────────────
MYLIB_DIR	= $(LIBS_DIR)/mylib
MYLIB		= $(MYLIB_DIR)/libmylib.a
MYLIB_INCS	= -I$(MYLIB_DIR)/includes
MYLIB_ADD	= -L$(MYLIB_DIR) -lft

#────────────────────────────────── Main Files ───────────────────────────────────
SRCS 		= main.c
INCS		= $(MLX_INCS) $(MYLIB_INCS)
LIBS_DIR	= libs
OBJS_DIR	= .objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

#────────────────────────────────── MFA Files ────────────────────────────────────
mfa_dir			= $(OBJS_DIR)/makefile
mfa_header		= $(mfa_dir)/mfa_header
mfa_h_len		= 49
debug_on		= .debug_on

#─────────────────────────────────── Main Rules ──────────────────────────────────
all: $(mfa_header) $(MLX) $(MYLIB)

$(NAME): $(mfa_namegen) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX_ADD) $(MYLIB_ADD)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean: mlx_clean mylib_clean
	$(RM) $(OBJS_DIR)

fclean: mlx_clean mylib_fclean
	@$(RM) $(OBJS_DIR)

re: fclean all

#──────────────────────────────────── Mlx Rule ─────────────────────────────────────
$(MLX):
	@printf "\n"
	@make mfa_compiling mfa_name="mlx" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MLX_DIR) all V=1; \
	else \
		make -C $(MLX_DIR) all --no-print-directory > /dev/null 2>&1; \
		make mfa_object mfa_name="libmlx.a" mfa_symbol="$(green)[✔]" --no-print-directory; \
		make mfa_object mfa_name="libmlx_Linux.a" mfa_symbol="$(green)[✔]" --no-print-directory; \
	fi
	@make mfa_success --no-print-directory; \

mlx_clean:
	@printf "\n"
	@make mfa_removing mfa_name="mlx" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MLX_DIR) clean; \
	else \
		if [ -f "$(MLX)" ]; then \
			make -C $(MLX_DIR) clean --no-print-directory > /dev/null 2>&1; \
			make mfa_object mfa_name="mlx objects" mfa_symbol="$(green)[✖]" --no-print-directory; \
			make mfa_object mfa_name="libmlx.a" mfa_symbol="$(green)[✖]" --no-print-directory; \
			make mfa_object mfa_name="libmlx_Linux.a" mfa_symbol="$(green)[✖]" --no-print-directory; \
		else \
			printf "Nothing to be removed\n"; \
		fi; \
	fi
	@make mfa_success --no-print-directory; \

#────────────────────────────────── MyLib Rules ────────────────────────────────────
$(MYLIB):
	@printf "\n"
	@make mfa_compiling mfa_name="mylib" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MYLIB_DIR) all V=1; \
	else \
		make -C $(MYLIB_DIR) all --no-print-directory; \
		make mfa_object mfa_name="libmylib.a" mfa_symbol="$(green)[✔]" --no-print-directory; \
	fi
	@make mfa_success --no-print-directory; \

mylib_clean:
	@printf "\n"
	@make mfa_removing mfa_name="mylib" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MYLIB_DIR) clean; \
	else \
		if [ -f "$(MYLIB_DIR)/.objs" ]; then \
			make -C $(MYLIB_DIR) clean --no-print-directory > /dev/null 2>&1; \
		else \
			printf "Nothing to be removed\n"; \
		fi; \
	fi
	@make mfa_success --no-print-directory; \

mylib_fclean:
	@printf "\n"
	@make mfa_removing mfa_name="mylib" --no-print-directory
	@if [ -f "$(debug_on)" ]; then \
		make -C $(MYLIB_DIR) fclean; \
	else \
		if [ -f "$(MYLIB_DIR)/.objs" ]; then \
			make -C $(MYLIB_DIR) clean --no-print-directory > /dev/null 2>&1; \
		else \
			printf "Nothing to be removed\n"; \
		fi; \
	fi
	@make mfa_success --no-print-directory; \

#─────────────────────────────────── Color Codes ───────────────────────────────────
yellow 	= \033[1m\033[38;2;255;248;147m
pink	= \033[1m\033[38;2;231;133;190m
green	= \033[1m\033[38;2;129;223;164m
reset	= \033[0m

#──────────────────────────────────── MFA Rules ────────────────────────────────────
$(mfa_dir):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)

$(mfa_header):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(mfa_dir)
	@printf "$(yellow)\n"
	@printf "   ____        __                               \n"
	@printf "  / __/ ___   / /  ___   ___   ___ _            \n"
	@printf " _\ \  / _ \ / /__/ _ \ / _ \ / _ \`/           \n"
	@printf "/___/  \___//____/\___//_//_/ \_, /             \n"
	@printf "                             /___/   by joao-alm$(reset)\n"
	@touch $(mfa_header)

mfa_compiling:
	@make mfa_line_message mfa_name1="$(yellow)Compiling [$(mfa_name)] /" mfa_name2="$(reset)\\n" mfa_line="─" --no-print-directory

mfa_object:
	@make mfa_line_message mfa_name1="$(green)>>> $(reset)$(mfa_name)" mfa_name2="$(mfa_symbol)$(reset)\\n" mfa_line=" " --no-print-directory

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
	@make -C $(MYLIB_DIR) debug --no-print-directory
	@if [ ! -f "$(debug_on)" ]; then \
		touch $(debug_on); \
		make mfa_line_message mfa_name1="$(green)Debug Mode /" mfa_name2="/ ON$(reset)\\n" mfa_line="─" --no-print-directory; \
	else \
	  	$(RM) $(debug_on); \
	  	make mfa_line_message mfa_name1="$(pink)Debug Mode /" mfa_name2="/ OFF$(reset)\\n" mfa_line="─" --no-print-directory; \
	fi

#────────────────────────────────── Phony Targets ───────────────────────────────
.PHONY: clean fclean re all
