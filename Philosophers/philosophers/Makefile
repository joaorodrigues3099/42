# ┏┓┓ •┓       ┓
# ┃┃┣┓┓┃┏┓┏┏┓┏┓┣┓┏┓┏┓┏
# ┣┛┛┗┗┗┗┛┛┗┛┣┛┛┗┗ ┛ ┛
#            ┛         by joao-alm

# Compiler Settings
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g
RM          = rm -rf
O_DIR       = .obj
header		= .obj/header

# Mandatory Files
NAME        = philo
M_SRC       = mandatory/src/main/main.c
M_INC       = -Imandatory/include
M_OBJ       = $(M_SRC:mandatory/src/%.c=$(O_DIR)/mandatory/%.o)

# Mandatory Rules
all: $(header) $(NAME) bonus

$(NAME): $(M_OBJ)
	@echo -ne "Compiling $(y)[$(NAME)]$(r): executable$(c)\r"
	@sleep 0.2
	@$(CC) $(CFLAGS) $(M_OBJ) -o $@ # <────────Command
	@echo -e "Compiling $(y)[$(NAME)]$(r): $(g)Success$(r)$(c)"

$(O_DIR)/mandatory/%.o: mandatory/src/%.c
	@mkdir -p $(dir $@)
	@echo -ne "Compiling $(y)[$(NAME)]$(r): $(notdir $@)$(c)\r"
	@sleep 0.2
	@$(CC) $(CFLAGS) -c $< -o $@ $(M_INC) # <────────Command

clean: .header
	@echo -ne "Removing $(p)[.objs]$(r): $(O_DIR)$(c)\r"
	@sleep 0.2
	@$(RM) $(O_DIR); # <────────Command
	@echo -e "Removing $(p)[.objs]$(r): $(g)Success$(r)$(c)"

fclean: .header clean .fclean_bonus
	@echo -ne "Removing $(p)[$(NAME)]$(r): $(NAME)$(c)\r"
	@sleep 0.2
	@$(RM) $(NAME); # <────────Command
	@echo -e "Removing $(p)[$(NAME)]$(r): $(g)Success$(r)$(c)"

re: fclean all

# Bonus Files
B_NAME      = philo_bonus
B_SRC       = bonus/src/main/main_bonus.c
B_INC       = -Ibonus/include
B_OBJ       = $(B_SRC:bonus/src/%.c=$(O_DIR)/bonus/%.o)

# Bonus Rules
bonus: $(header) $(B_NAME)

$(B_NAME): $(B_OBJ)
	@echo -ne "Compiling $(y)[$(B_NAME)]$(r): executable$(c)\r"
	@sleep 0.2
	@$(CC) $(CFLAGS) $(B_OBJ) -o $@ # <────────Command
	@echo -e "Compiling $(y)[$(B_NAME)]$(r): $(g)Success$(r)$(c)"

$(O_DIR)/bonus/%.o: bonus/src/%.c
	@mkdir -p $(dir $@)
	@echo -ne "Compiling $(y)[$(B_NAME)]$(r): $(notdir $@)$(c)\r"
	@sleep 0.2
	@$(CC) $(CFLAGS) -c $< -o $@ $(B_INC) # <────────Command

.fclean_bonus: clean
	@echo -ne "Removing $(p)[$(B_NAME)]$(r): $(B_NAME)$(c)\r"
	@sleep 0.2
	@$(RM) $(B_NAME); # <────────Command
	@echo -e "Removing $(p)[$(B_NAME)]$(r): $(g)Success$(r)$(c)"

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
	@echo "┏┓┓ •┓       ┓                  " > $(header)
	@echo "┃┃┣┓┓┃┏┓┏┏┓┏┓┣┓┏┓┏┓┏            " >> $(header)
	@echo "┣┛┛┗┗┗┗┛┛┗┛┣┛┛┗┗ ┛ ┛            " >> $(header)
	@echo "           ┛         by joao-alm" >> $(header)
	@echo -e "$(y)"
	@cat $(header)
	@echo -e "$(r)"

.header:
	@echo -e "$(p)"
	@echo "┏┓┓ •┓       ┓                  "
	@echo "┃┃┣┓┓┃┏┓┏┏┓┏┓┣┓┏┓┏┓┏            "
	@echo "┣┛┛┗┗┗┗┛┛┗┛┣┛┛┗┗ ┛ ┛            "
	@echo "           ┛         by joao-alm"
	@echo -e "$(r)"

# Phony
.PHONY: all clean fclean re
