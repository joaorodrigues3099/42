#
# ░█▀█░█░█░▀█▀░█░░░█▀█░█▀▀░█▀█░█▀█░█░█░█▀▀░█▀▄░█▀▀
# ░█▀▀░█▀█░░█░░█░░░█░█░▀▀█░█░█░█▀▀░█▀█░█▀▀░█▀▄░▀▀█
# ░▀░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░░░▀░▀░▀▀▀░▀░▀░▀▀▀
#                                      by joao-alm

# Compiler Settings
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -rf
O_DIR	= .obj
header	= .obj/header
sleep	= 0.05

# Mandatory Files
NAME	= philo_bonus
M_SRC	= $(wildcard src/**/*.c)
M_INC	= -Iinclude
M_OBJ	= $(M_SRC:src/%.c=$(O_DIR)/$(notdir %.o))

# Mandatory Rules
all: $(header) $(NAME)

$(NAME): $(M_OBJ)
	@printf "Compiling [$(y)$(NAME)$(r)]: executable$(c)\r"
	@sleep $(sleep)
	@$(CC) $(CFLAGS) $(M_OBJ) -o $@
	@printf "Compiling [$(y)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(notdir $@)$(c)\r"
	@sleep $(sleep)
	@$(CC) $(CFLAGS) -c $< -o $@ $(M_INC)

clean:
	@printf "Removing [$(p).objs$(r)]: $(O_DIR)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(O_DIR)
	@printf "Removing [$(p).objs$(r)]: $(g)Success$(r)$(c)\n"

fclean: clean
	@printf "Removing [$(p)$(NAME)$(r)]: $(NAME)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(NAME)
	@printf "Removing [$(p)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

re: fclean all

# Colours
c	= \033[K
p	= \033[38;2;231;133;190m
y	= \033[38;2;255;248;147m
g	= \033[38;2;129;223;164m
b	= \033[1m
r	= \033[0m

# Headers
$(header):
	@mkdir -p $(O_DIR)
	@printf "$(y)\n"
	@printf "░█▀█░█░█░▀█▀░█░░░█▀█░░░░░█▀▄░█▀█░█▀█░█░█░█▀▀\n"
	@printf "░█▀▀░█▀█░░█░░█░░░█░█░░░░░█▀▄░█░█░█░█░█░█░▀▀█\n"
	@printf "░▀░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀░░▀▀▀░▀░▀░▀▀▀░▀▀▀\n"
	@printf "                                 by joao-alm\n"
	@printf "$(r)\n"
	@touch $(header)

# Phony
.PHONY: all clean fclean re
