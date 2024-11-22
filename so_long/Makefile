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
LFTPFGNL_DIR	= ./lftpfgnl
LFTPFGNL	= $(LFTPFGNL_DIR)/lftpfgnl.a
LIBFT		= $(LFTPFGNL_DIR)/libft/libft.a 

# MLX
MLXFLAGS 	= -L/usr/lib/X11 -lXext -lX11 -lm -lz
MLX_DIR		= ./minilibx-linux

# SRC- & OBJ-FILES
SOURCE_FILES 	= main.c 
OBJECT_FILES 	= ${SOURCE_FILES:.c=.o}

INCLUDES 	= -I$(LFTPFGNL_DIR) -I$(MLX_DIR)

# COMMANDS
all: $(NAME)

$(NAME): $(LFTPFGNL) $(OBJECT_FILES)
	@ $(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME) $(LFTPFGNL) $(MLXFLAGS) $(INCLUDES) 
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#         SO_LONG COMPILED    .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"

# LIBFT+PRINTF+GET_NEXT_LINE
$(LFTPFGNL):
	@make -sC $(LFTPFGNL_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
clean:
	@make clean -sC $(LFTPFGNL_DIR)
	@rm -f $(OBJECT_FILES)
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#          SO_LONG CLEANED    .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(LFTPFGNL)
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re #bonus
