# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: .frnki <frnki@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 16:20:42 by .frnki            #+#    #+#              #
#    Updated: 2025/02/18 16:42:42 by .frnki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS - CUSTOM
BLACK_ON_G	= \033[42;30m
COLOR_OFF	= \033[0m

# COMPILER
CC 		= cc
CFLAGS 		= -Wall -Wextra -Werror

# VARIABLES
NAME		= minishell

# LIBRARIES
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft++.a
PRINTF_DIR	= $(LIBFT_DIR)/printf
PRINTF		= $(PRINTF_DIR)/printf.a

# SRC- & OBJ-FILES
MINISH_SOURCE 	= minishell.c
MINISH_OBJECT 	= ${MINISH_SOURCE:.c=.o}

# TARGETS
all: $(NAME)

$(NAME): $(MINISH_OBJECT) $(LIBFT)
	@ $(CC) $(CFLAGS) $(MINISH_OBJECT) -o $(NAME) $(LIBFT) $(PRINTF) -lreadline
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#      MINISHELL COMPILED     .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"

# LIBFT++ (LIBFT+PRINTF+GET_NEXT_LINE)
$(LIBFT):
	@make -sC $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make clean -sC $(LIBFT_DIR)
	@rm -f $(MINISH_OBJECT)
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#       MINISHELL CLEANED     .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
