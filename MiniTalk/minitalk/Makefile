#################################################################################
#                    ▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖▗▄▄▄▖ ▗▄▖ ▗▖   ▗▖ ▗▖                 #
#                    ▐▛▚▞▜▌  █  ▐▛▚▖▐▌  █    █  ▐▌ ▐▌▐▌   ▐▌▗▞▘                 #
#                    ▐▌  ▐▌  █  ▐▌ ▝▜▌  █    █  ▐▛▀▜▌▐▌   ▐▛▚▖                  #
#                    ▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▗▄█▄▖  █  ▐▌ ▐▌▐▙▄▄▖▐▌ ▐▌                 #
#################################################################################

#───────────────────────────────────────Bases────────────────────────────────────

NAME			= Minitalk
CC           	= cc
CFLAGS       	= -Wall -Werror -Wextra -g
RM           	= rm -rf
INCS         	= $(LIB_INCS) -I includes
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

#─────────────────────────────────────── Lib ────────────────────────────────────

LIB_DIR      	= lib
LIB_INCS     	= -I $(LIB_DIR)/conversion \
				  -I $(LIB_DIR)/char \
				  -I $(LIB_DIR)/print
ADD_LIB      	= -L $(LIB_DIR) -l ft

#─────────────────────────────────────── Color Codes ──────────────────────────────────

YELLOW			= \033[0m\033[38;2;255;248;147m
B_YELLOW		= \033[1m\033[38;2;255;248;147m
PINK			= \033[0m\033[38;2;231;133;190m
B_PINK			= \033[1m\033[38;2;231;133;190m
GREEN			= \033[0m\033[38;2;129;223;164m
B_GREEN			= \033[1m\\033[38;2;129;223;164m
B_BASE			= \033[1m
BASE			= \033[0m

#─────────────────────────────────────── MFA Settings ─────────────────────────────────

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
	@echo -n "Compiling $(B_BASE)$(notdir $<) $(BASE)into $(B_BASE)$(notdir $@)$(BASE)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo " $(B_GREEN)[✔]$(BASE)"

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CLIENT_OBJS) -o $@ $(ADD_LIB)
	@echo "$(B_GREEN)>>> $(B_BASE)[$@] $(BASE)compiled $(B_GREEN)successfully$(BASE)"


#───────────────────────────────────Server────────────────────────────────────

$(OBJS_DIR)/$(SERVER)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -n "Compiling $(B_BASE)$(notdir $<) $(BASE)into $(B_BASE)$(notdir $@)$(BASE)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo " $(B_GREEN)[✔]$(BASE)"

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(SERVER_OBJS) -o $@ $(ADD_LIB)
	@echo "$(B_GREEN)>>> $(B_BASE)[$@] $(BASE)compiled $(B_GREEN)successfully$(BASE)"

#───────────────────────────────────Client_Bonus────────────────────────────────────

$(OBJS_DIR)/$(BCLIENT)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -n "Compiling $(B_BASE)$(notdir $<) $(BASE)into $(B_BASE)$(notdir $@)$(BASE)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo " $(B_GREEN)[✔]$(BASE)"

$(BCLIENT): $(BCLIENT_OBJS)
	@$(CC) $(BCLIENT_OBJS) -o $@ $(ADD_LIB)
	@echo "$(B_GREEN)>>> $(B_BASE)[$@] $(BASE)compiled $(B_GREEN)successfully$(BASE)"


#───────────────────────────────────Server_Bonus────────────────────────────────────

$(OBJS_DIR)/$(BSERVER)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -n "Compiling $(B_BASE)$(notdir $<) $(BASE)into $(B_BASE)$(notdir $@)$(BASE)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo " $(B_GREEN)[✔]$(BASE)"

$(BSERVER): $(MFA_BSERVER_HEADER) $(BSERVER_OBJS)
	@$(CC) $(BSERVER_OBJS) -o $@ $(ADD_LIB)
	@echo "$(B_GREEN)>>> $(B_BASE)[$@] $(BASE)compiled $(B_GREEN)successfully$(BASE)"

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
	  	echo "\n$(PINK)───────────────── Cleaning $(B_PINK)[$(NAME)] $(PINK)───────────────────$(BASE)"; \
	  	$(RM) $(OBJS_DIR); \
	  	echo "$(B_GREEN)>>> $(B_BASE)[$(NAME)] $(BASE)objects removed $(B_GREEN)successfully$(BASE)"; \
	  else \
	  	echo "Nothing to be done for 'clean'."; \
	fi

fclean: lib_fclean
	@if [ -d "$(OBJS_DIR)" ] || [ -f "$(CLIENT)" ] || [ -f "$(SERVER)" ] || [ -f "$(B_CLIENT)" ] || [ -f "$(B_SERVER)" ]; then \
		echo "\n$(PINK)───────────────── Cleaning $(B_PINK)[$(NAME)] $(PINK)───────────────────$(BASE)"; \
		if [ -d "$(OBJS_DIR)" ]; then \
			$(RM) $(OBJS_DIR); \
			echo "$(B_GREEN)>>> $(B_BASE)[$(NAME)] $(BASE)objects removed $(B_GREEN)successfully$(BASE)"; \
		fi; \
		if [ -f "$(CLIENT)" ]; then \
			$(RM) $(CLIENT); \
			echo "$(B_GREEN)>>> $(B_BASE)[$(CLIENT)] $(BASE)removed $(B_GREEN)successfully$(BASE)"; \
		fi; \
		if [ -f "$(SERVER)" ]; then \
			$(RM) $(SERVER); \
			echo "$(B_GREEN)>>> $(B_BASE)[$(SERVER)] $(BASE)removed $(B_GREEN)successfully$(BASE)"; \
		fi; \
		if [ -f "$(BCLIENT)" ]; then \
        	$(RM) $(BCLIENT); \
        	echo "$(B_GREEN)>>> $(B_BASE)[$(BCLIENT)] $(BASE)removed $(B_GREEN)successfully$(BASE)"; \
        fi; \
		if [ -f "$(BSERVER)" ]; then \
			$(RM) $(BSERVER); \
			echo "$(B_GREEN)>>> $(B_BASE)[$(BSERVER)] $(BASE)removed $(B_GREEN)successfully$(BASE)"; \
		fi; \
    else \
    	echo "Nothing to be done for 'fclean'."; \
    fi


re: fclean all

#─────────────────────────────────────Animation Rules────────────────────────

$(MFA_JA_MANDATORY):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(MFA_DIR)
	@echo "$(YELLOW)"
	@echo "▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖▗▄▄▄▖ ▗▄▖ ▗▖   ▗▖ ▗▖            "
	@echo "▐▛▚▞▜▌  █  ▐▛▚▖▐▌  █    █  ▐▌ ▐▌▐▌   ▐▌▗▞▘            "
	@echo "▐▌  ▐▌  █  ▐▌ ▝▜▌  █    █  ▐▛▀▜▌▐▌   ▐▛▚▖             "
	@echo "▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▗▄█▄▖  █  ▐▌ ▐▌▐▙▄▄▖▐▌ ▐▌ by $(B_YELLOW)joao-alm$(BASE)"
	@touch $(MFA_JA_MANDATORY)

$(MFA_MANDATORY_HEADER):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(MFA_DIR)
	@echo "\n$(YELLOW)───────────────── Generating $(B_YELLOW)[$(NAME)] $(YELLOW)─────────────────$(BASE)"
	@touch $(MFA_MANDATORY_HEADER)

$(MFA_BONUS_HEADER):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(MFA_DIR)
	@echo "\n$(YELLOW)───────────────── Generating $(B_YELLOW)[Bonus] $(YELLOW)────────────────────$(BASE)"
	@touch $(MFA_BONUS_HEADER)

#─────────────────────────────────────────Phony Targets───────────────────────

.PHONY: clean fclean re all lib