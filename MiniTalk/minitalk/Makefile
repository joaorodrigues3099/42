##################################################################################
#                                     Makefile for                               #
#                                     Lib Library                                #
##################################################################################

#───────────────────────────────────────Bases────────────────────────────────

LIB_DIR      	= lib
LIB_INCS     	= $(LIB_DIR)/includes
ADD_LIB      	= -L $(LIB_DIR) -l ft
NAME			= Minitalk
CC           	= cc
CFLAGS       	= -Wall -Werror -Wextra -g
RM           	= rm -rf
INCS         	= -I $(LIB_INCS) -I includes
OBJS_DIR     	= .objs

CLIENT       	= client
CLIENT_SRCS  	= srcs/client.c
CLIENT_OBJS  	= $(CLIENT_SRCS:%.c=$(OBJS_DIR)/$(CLIENT)/%.o)

SERVER       	= server
SERVER_SRCS  	= srcs/server.c
SERVER_OBJS  	= $(SERVER_SRCS:%.c=$(OBJS_DIR)/$(SERVER)/%.o)

BCLIENT     	= client_bonus
BCLIENT_SRCS	= bonus/client_bonus.c
BCLIENT_OBJS	= $(BCLIENT_SRCS:%.c=$(OBJS_DIR)/$(BCLIENT)/%.o)

BSERVER     	= server_bonus
BSERVER_SRCS	= bonus/server_bonus.c
BSERVER_OBJS	= $(BSERVER_SRCS:%.c=$(OBJS_DIR)/$(BSERVER)/%.o)

#─────────────────────────────────────────Extras──────────────────────────────────

YELLOW					= \033[38;2;255;248;147m
PINK					= \033[38;2;231;133;190m
GREEN					= \033[38;2;129;223;164m
BOLD					= \033[1m
RESET					= \033[0m

MFA_DIR					= $(OBJS_DIR)/makefile_anim
MFA_JA_MANDATORY		= $(MFA_DIR)/mfa_ja_mandatory
MFA_JA_BONUS			= $(MFA_DIR)/mfa_ja_bonus
MFA_MANDATORY_HEADER	= $(MFA_DIR)/mfa_mandatory_header
MFA_BONUS_HEADER		= $(MFA_DIR)/mfa_bonus_header

#───────────────────────────────────Compilation Commands─────────────────────

mandatory: $(MFA_JA_MANDATORY) lib $(MFA_MANDATORY_HEADER) $(CLIENT) $(SERVER)

bonus: lib $(MFA_BONUS_HEADER) $(BCLIENT) $(BSERVER)

all: mandatory bonus

#───────────────────────────────────Client────────────────────────────────────

$(OBJS_DIR)/$(CLIENT)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "Compiling $(BOLD)$(notdir $<) $(RESET)into $(BOLD)$(notdir $@)$(RESET)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@printf " $(GREEN)$(BOLD)[✔]$(RESET)\n"

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CLIENT_OBJS) -o $@ $(ADD_LIB)
	@echo "$(BOLD)$(GREEN)>>>$(RESET) $(PINK)$(BOLD)$@ $(RESET)compiled $(BOLD)$(GREEN)successfully$(RESET)"


#───────────────────────────────────Server────────────────────────────────────

$(OBJS_DIR)/$(SERVER)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "Compiling $(BOLD)$(notdir $<) $(RESET)into $(BOLD)$(notdir $@)$(RESET)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@printf " $(GREEN)$(BOLD)[✔]$(RESET)\n"

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(SERVER_OBJS) -o $@ $(ADD_LIB)
	@printf "$(BOLD)$(GREEN)>>>$(RESET) $(PINK)$(BOLD)$@ $(RESET)compiled $(BOLD)$(GREEN)successfully$(RESET)\n"

#───────────────────────────────────Client_Bonus────────────────────────────────────

$(OBJS_DIR)/$(BCLIENT)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "Compiling $(BOLD)$(notdir $<) $(RESET)into $(BOLD)$(notdir $@)$(RESET)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@printf " $(GREEN)$(BOLD)[✔]$(RESET)\n"

$(BCLIENT): $(BCLIENT_OBJS)
	@$(CC) $(BCLIENT_OBJS) -o $@ $(ADD_LIB)
	@echo "$(BOLD)$(GREEN)>>> $@ $(RESET)compiled $(BOLD)$(GREEN)successfully$(RESET)"


#───────────────────────────────────Server_Bonus────────────────────────────────────

$(OBJS_DIR)/$(BSERVER)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "Compiling $(BOLD)$(notdir $<) $(RESET)into $(BOLD)$(notdir $@)$(RESET)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@printf " $(GREEN)$(BOLD)[✔]$(RESET)\n"

$(BSERVER): $(MFA_BSERVER_HEADER) $(BSERVER_OBJS)
	@$(CC) $(BSERVER_OBJS) -o $@ $(ADD_LIB)
	@printf "$(BOLD)$(GREEN)>>> $@ $(RESET)compiled $(BOLD)$(GREEN)successfully$(RESET)\n"

#───────────────────────────────────Library Commands──────────────────────────

lib:
	@make -C $(LIB_DIR) all --no-print-directory

lib_clean:
	@make -C $(LIB_DIR) clean --no-print-directory

lib_fclean:
	@make -C $(LIB_DIR) fclean --no-print-directory

#─────────────────────────────────────Cleaning Commands───────────────────────

clean: lib_clean
	@if [ -d "$(OBJS_DIR)" ]; then \
  		echo "\n$(PINK)────────────── Cleaning $(BOLD)[$(NAME)] $(RESET)$(PINK)──────────────$(RESET)"; \
		$(RM) $(OBJS_DIR); \
		echo "$(BOLD)$(GREEN)>>>$(RESET) $(PINK)$(BOLD)[$(NAME)] $(RESET)objects removed $(BOLD)$(GREEN)successfully$(RESET)"; \
	else \
		echo "Nothing to be done for 'clean'."; \
	fi

fclean: lib_fclean
	@if [ -d "$(OBJS_DIR)" ] || [ -f "$(CLIENT)" ] || [ -f "$(SERVER)" ]; then \
		echo "\n$(PINK)────────────── Cleaning $(BOLD)[$(NAME)] $(RESET)$(PINK)──────────────$(RESET)"; \
		if [ -d "$(OBJS_DIR)" ]; then \
			$(RM) $(OBJS_DIR); \
			echo "$(BOLD)$(GREEN)>>>$(RESET) $(PINK)$(BOLD)[$(NAME)] $(RESET)objects removed $(BOLD)$(GREEN)successfully$(RESET)"; \
		fi; \
		if [ -f "$(CLIENT)" ]; then \
			$(RM) $(CLIENT); \
			echo "$(BOLD)$(GREEN)>>>$(RESET) $(PINK)$(BOLD)[$(CLIENT)] $(RESET)removed $(BOLD)$(GREEN)successfully$(RESET)"; \
		fi; \
		if [ -f "$(SERVER)" ]; then \
			$(RM) $(SERVER); \
			echo "$(BOLD)$(GREEN)>>>$(RESET) $(PINK)$(BOLD)[$(SERVER)] $(RESET)removed $(BOLD)$(GREEN)successfully$(RESET)"; \
		fi; \
		if [ -f "$(BCLIENT)" ]; then \
        			$(RM) $(BCLIENT); \
        			echo "$(BOLD)$(GREEN)>>>$(RESET) $(GREEN)$(BOLD)[$(BCLIENT)] $(RESET)removed $(BOLD)$(GREEN)successfully$(RESET)"; \
        		fi; \
		if [ -f "$(BSERVER)" ]; then \
			$(RM) $(BSERVER); \
			echo "$(BOLD)$(GREEN)>>>$(RESET) $(GREEN)$(BOLD)[$(BSERVER)] $(RESET)removed $(BOLD)$(GREEN)successfully$(RESET)"; \
		fi; \
    else \
    	echo "Nothing to be done for 'fclean'."; \
    fi

re: fclean all

#─────────────────────────────────────────Colors──────────────────────────────

YELLOW = \033[38;2;255;248;147m # FFF893 - soft yellow
PINK   = \033[38;2;231;133;190m # E785BE - soft pink
GREEN  = \033[38;2;129;223;164m # 81DFA4 - soft green
RESET  = \033[0m

#─────────────────────────────────────Animation Rules────────────────────────

$(MFA_JA_MANDATORY):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(MFA_DIR)
	@echo "$(PINK)"
	@echo "█████████████████████████████"
	@echo "        ██  █▓███  ██  █▓███ "
	@echo "joao-alm  █████      █████   "
	@echo "$(YELLOW)"
	@echo "╔╦╗┬┌┐┌┬╔╦╗┌─┐┬  ┬┌─"
	@echo "║║║│││││ ║ ├─┤│  ├┴┐"
	@echo "╩ ╩┴┘└┘┴ ╩ ┴ ┴┴─┘┴ ┴$(RESET)"
	@touch $(MFA_JA_MANDATORY)

$(MFA_MANDATORY_HEADER):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(MFA_DIR)
	@echo "\n$(PINK)────────────── Generating $(BOLD)[$(NAME)]$(RESET)$(PINK) ──────────────$(RESET)"
	@touch $(MFA_MANDATORY_HEADER)

$(MFA_BONUS_HEADER):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(MFA_DIR)
	@echo "\n$(GREEN)────────────── Generating $(BOLD)[Bonus]$(RESET)$(GREEN) ──────────────$(RESET)"
	@touch $(MFA_BONUS_HEADER)

#─────────────────────────────────────────Phony Targets───────────────────────

.PHONY: clean fclean re all lib