# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efembock <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 16:20:42 by efembock          #+#    #+#              #
#    Updated: 2024/11/16 16:20:42 by efembock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER
CC 		= cc
CFLAGS 		= -Wall -Wextra -Werror

# VARIABLES
NAME = so_long

# COLORS - CUSTOM
BLACK_ON_G	= \033[42;30m
COLOR_OFF	= \033[0m

# LIBRARIES
LIBFT++_DIR	= ./libft++
LIBFT++		= $(LIBFT++_DIR)/libft++.a

# MLX
MLXFLAGS 	= -lminilibx-linux -lXext lX11
MLX_DIR		= ./minilibx-linux

# SRC- & OBJ-FILES
SOURCE_FILES 	= main.c 
OBJECT_FILES 	= ${SOURCE_FILES:.c=.o}

INCLUDES 	= -I$(LIBFT++_DIR) -I$(MLX_DIR)

# COMMANDS
all: $(NAME)

$(NAME): $(LIBFT++) $(OBJECT_FILES)
	@ $(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME) $(LIBFT++) $(MLXFLAGS) $(INCLUDES) 
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#         SO_LONG COMPILED    .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"

# LIBFT++ (LIBFT+PRINTF+GET_NEXT_LINE)
$(LIBFT++):
	@make -sC $(LIBFT++_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
clean:
	@make clean -sC $(LFTPFGNL_DIR)
	@rm -f $(OBJECT_FILES)
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#          SO_LONG CLEANED    .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
fclean: clean
	@rm -f $(LIBFT++)
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
