#    ___  __   _ __                   __
#   / _ \/ /  (_) /__  ___ ___  ___  / /  ___ _______
#  / ___/ _ \/ / / _ \(_-</ _ \/ _ \/ _ \/ -_) __(_-<
# /_/  /_//_/_/_/\___/___/\___/ .__/_//_/\__/_/ /___/
#                            /_/                      by joao-alm

# Compiler Settings
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -rf
O_DIR	= .obj
header	= .obj/header

# Mandatory Files
NAME	= philo
M_SRC	= src/main/main.c \
		  src/input/get_input.c \
		  src/error/error.c \
		  src/util/ft_strlen.c \
		  src/util/atoll_valid.c
M_INC	= -Iinclude
M_OBJ	= $(M_SRC:src/%.c=$(O_DIR)/%.o)

# Mandatory Rules
all: $(header) $(NAME) bonus

$(NAME): $(M_OBJ)
	@printf "Compiling [$(y)$(NAME)$(r)]: executable$(c)\r"
	@sleep 0.2
	@$(CC) $(CFLAGS) $(M_OBJ) -o $@
	@printf "Compiling [$(y)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(notdir $@)$(c)\r"
	@sleep 0.2
	@$(CC) $(CFLAGS) -c $< -o $@ $(M_INC)

clean:
	@printf "Removing [$(p).objs$(r)]: $(O_DIR)$(c)\r"
	@sleep 0.2
	@$(RM) $(O_DIR)
	@printf "Removing [$(p).objs$(r)]: $(g)Success$(r)$(c)\n"

fclean: clean .fclean_bonus
	@printf "Removing [$(p)$(NAME)$(r)]: $(NAME)$(c)\r"
	@sleep 0.2
	@$(RM) $(NAME)
	@printf "Removing [$(p)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

re: fclean all

re: fclean all

# Bonus Files
B_NAME	= philo_bonus
B_SRC	= bonus/src/main/main_bonus.c
B_INC	= -Ibonus/include
B_OBJ	= $(B_SRC:bonus/src/%.c=$(O_DIR)/bonus/%.o)

# Bonus Rules
bonus: $(header) $(B_NAME)

$(B_NAME): $(B_OBJ)
	@printf "Compiling [$(y)$(B_NAME)$(r)]: executable$(c)\r"
	@sleep 0.2
	@$(CC) $(CFLAGS) $(B_OBJ) -o $@
	@printf "Compiling [$(y)$(B_NAME)$(r)]: $(g)Success$(r)$(c)\n"

$(O_DIR)/bonus/%.o: bonus/src/%.c
	@mkdir -p $(dir $@)
	@printf "Compiling [$(y)$(B_NAME)$(r)]: $(notdir $@)$(c)\r"
	@sleep 0.2
	@$(CC) $(CFLAGS) -c $< -o $@ $(B_INC)

.fclean_bonus: clean
	@printf "Removing [$(p)$(B_NAME)$(r)]: $(B_NAME)$(c)\r"
	@sleep 0.2
	@$(RM) $(B_NAME)
	@printf "Removing [$(p)$(B_NAME)$(r)]: $(g)Success$(r)$(c)\n"

# Colours
c	= \033[K
y	= \033[1m\033[38;2;255;248;147m
p	= \033[1m\033[38;2;231;133;190m
g	= \033[1m\033[38;2;129;223;164m
b	= \033[1m
r	= \033[0m

# Headers
$(header):
	@mkdir -p $(O_DIR)
	@printf "$(y)\n"
	@printf "   ___  __   _ __                   __                         \n"
	@printf "  / _ \/ /  (_) /__  ___ ___  ___  / /  ___ _______            \n"
	@printf " / ___/ _ \/ / / _ \(_-</ _ \/ _ \/ _ \/ -_) __(_-<            \n"
	@printf "/_/  /_//_/_/_/\___/___/\___/ .__/_//_/\__/_/ /___/            \n"
	@printf "                           /_/                      by joao-alm\n"
	@printf "$(r)\n"
	@touch $(header)

# Phony
.PHONY: all clean fclean re
