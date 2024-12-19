# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: .frnki <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 16:20:42 by .frnki            #+#    #+#              #
#    Updated: 2024/11/16 16:20:42 by .frnki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS - CUSTOM
BLACK_ON_G	= \033[42;30m
COLOR_OFF	= \033[0m

# COMPILER
CC 		= cc
CFLAGS 		= -Wall -Wextra -Werror

# VARIABLES
NAME		= $(CLIENT) $(SERVER)
CLIENT		= client
SERVER		= server

# LIBRARIES
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft++.a
PRINTF_DIR	= $(LIBFT_DIR)/printf
PRINTF		= $(PRINTF_DIR)/printf.a

# SRC- & OBJ-FILES
CLIENT_SOURCE 	= client.c
CLIENT_OBJECT 	= ${CLIENT_SOURCE:.c=.o}
SERVER_SOURCE	= server.c
SERVER_OBJECT 	= ${SERVER_SOURCE:.c=.o}

# TARGETS
all: $(NAME)

$(CLIENT): $(SERVER) $(CLIENT_OBJECT)
	@ $(CC) $(CFLAGS) $(CLIENT_OBJECT) -o $(CLIENT) $(LIBFT) $(PRINTF)
	@echo "$(BLACK_ON_G)#    CLIENT COMPILED          .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"

$(SERVER): $(LIBFT) $(SERVER_OBJECT)
	@ $(CC) $(CFLAGS) $(SERVER_OBJECT) -o $(SERVER) $(LIBFT) $(PRINTF)
	@echo "$(BLACK_ON_G)#    SERVER COMPILED          .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
# LIBFT++ (LIBFT+PRINTF+GET_NEXT_LINE)
$(LIBFT):
	@make -sC $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make clean -sC $(LIBFT_DIR)
	@rm -f $(CLIENT_OBJECT) $(SERVER_OBJECT)
	@echo "$(BLACK_ON_G)#      MINITALK CLEANED       .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@rm -f $(CLIENT) $(SERVER)
re: fclean all
.PHONY: all clean fclean re
