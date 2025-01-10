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
MYLIB		= $(MYLIB_DIR)/libft.a
MYLIB_INCS	= -I$(MYLIB_DIR)/includes
MYLIB_ADD	= -L$(MYLIB_DIR) -lft

#────────────────────────────────── Main Files ───────────────────────────────────
SRCS 		= main.c
INCS		= $(MLX_INCS) $(MYLIB_INCS)
LIBS_DIR	= libs
OBJS_DIR	= .objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

#────────────────────────────────── MFA Files ────────────────────────────────────
mfa_hminilib	= $(OBJS_DIR)/mfa_hminilib
mfa_header		= $(OBJS_DIR)/mfa_header
mfa_namegen		= $(OBJS_DIR)/mfa_namegen
mfa_mlxgen		= $(OBJS_DIR)/mfa_mlxgen
mfa_mylibgen	= $(OBJS_DIR)/mfa_mylibgen

#─────────────────────────────────── Main Rules ──────────────────────────────────
all: $(MLX) $(mfa_header) $(NAME)

$(NAME): $(MYLIB) $(mfa_namegen) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(MLX_ADD) $(MYLIB_ADD)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean: mlx_clean mylib_clean mfa_nameclean
	$(RM) $(OBJS_DIR)

fclean: mlx_clean mylib_fclean mfa_nameclean
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)

re: fclean all

#──────────────────────────────────── Mlx Rule ─────────────────────────────────────
$(MLX): $(mfa_hminilib) $(mfa_mlxgen)
	@make -C $(MLX_DIR) all > /dev/null 2>&1

mlx_clean: mfa_mlxclean
	@make -C $(MLX_DIR) clean

#────────────────────────────────── MyLib Rules ────────────────────────────────────
$(MYLIB): $(mfa_mylibgen)
	@make -C $(MYLIB_DIR) all

mylib_clean: mfa_mylibclean
	@make -C $(MYLIB_DIR) clean

mylib_fclean: mfa_mylibclean
	@make -C $(MYLIB_DIR) fclean

#─────────────────────────────────── Color Codes ───────────────────────────────────
yellow	= \033[38;2;255;248;147m
pink	= \033[1m\033[38;2;231;133;190m
green	= \033[1m\033[38;2;129;223;164m
reset	= \033[0m

#──────────────────────────────────── MFA Rules ────────────────────────────────────
$(mfa_header): $(mfa_dir)
	@mkdir -p $(OBJS_DIR)
	@printf "$(yellow)\n"
	@printf "              _____                  __                                     \n"
	@printf "             / ___/  ____           / /   ____    ____    ____ _            \n"
	@printf "             \__ \  / __ \         / /   / __ \  / __ \  / __ \`/           \n"
	@printf "            ___/ / / /_/ /        / /___/ /_/ / / / / / / /_/ /             \n"
	@printf "           /____/  \____/  ______/_____/\____/ /_/ /_/  \__, /              \n"
	@printf "Compiling                 /_____/                      /____/    by joao-alm $(reset)"
	@printf "$(reset)\n"
	@touch $(mfa_header)

$(mfa_hminilib): $(mfa_dir)
	@mkdir -p $(OBJS_DIR)
	@printf "$(yellow)\n"
	@printf "              __  ___  _           _   __      _   __      _               \n"
	@printf "             /  |/  / (_) ____    (_) / /     (_) / /_    (_) _  __        \n"
	@printf "            / /|_/ / / / / __ \  / / / /     / / / __ \  / / | |/_/        \n"
	@printf "           / /  / / / / / / / / / / / /___  / / / /_/ / / / _>  <          \n"
	@printf "Compiling /_/  /_/ /_/ /_/ /_/ /_/ /_____/ /_/ /_.___/ /_/ /_/|_|  by someone? $(reset)"
	@printf "$(reset)\n"
	@touch $(mfa_hminilib)

$(mfa_mlxgen): $(mfa_dir)
	@mkdir -p $(OBJS_DIR)
	@printf "$(green)\n───────────────────────────── Compiling [mlx] ──────────────────────────────\n$(reset)"
	@touch $(mfa_mlxgen)

mfa_mlxclean:
	@printf "$(pink)\n───────────────────────────── Cleaning [mlx] ───────────────────────────────\n$(reset)"

$(mfa_mylibgen): $(mfa_dir)
	@mkdir -p $(OBJS_DIR)
	@printf "$(green)\n──────────────────────────── Compiling [mylib] ─────────────────────────────\n$(reset)"
	@touch $(mfa_mylibgen)

mfa_mylibclean:
	@printf "$(pink)\n──────────────────────────── Cleaning [mylib] ──────────────────────────────\n$(reset)"

$(mfa_namegen): $(mfa_dir)
	@mkdir -p $(OBJS_DIR)
	@printf "$(green)\n─────────────────────────── Compiling [so_long] ────────────────────────────\n$(reset)"
	@touch $(mfa_namegen)

mfa_nameclean:
	@printf "$(pink)\n─────────────────────────── Cleaning [so_long] ─────────────────────────────\n$(reset)"

#────────────────────────────────── Phony Targets ───────────────────────────────
.PHONY: clean fclean re all
