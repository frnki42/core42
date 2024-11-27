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
NAME		= so_long

# COLORS - CUSTOM
BLACK_ON_G	= \033[42;30m
COLOR_OFF	= \033[0m

# LIBRARIES
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft++.a
PRINTF_DIR	= $(LIBFT_DIR)/printf
PRINTF		= $(PRINTF_DIR)/printf.a

# MLX
MLX_DIR		= ./minilibx-linux
MLXFLAGS 	= -L$(MLX_DIR) -lmlx -L/usr/lib  -lXext -lX11 -lm

# SRC- & OBJ-FILES
SOURCE_FILES 	= exit_game.c movement.c game.c load_game_textures.c \
		  start_mlx.c create_window.c init_structs.c display_mary.c \
		  parsing_map.c check_map.c render_map.c manipulate_map.c \
		  check_move.c check_surrounded.c flood_fill.c check_argv.c
OBJECT_FILES 	= ${SOURCE_FILES:.c=.o}

# INCLUDES
INCLUDES 	= -I$(LIBFT_DIR) -I$(MLX_DIR)

# COMMANDS
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECT_FILES)
	@ $(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME) $(LIBFT) $(PRINTF) $(MLXFLAGS) $(INCLUDES) 
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#        SO_LONG COMPILED     .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"

# LIBFT++ (LIBFT+PRINTF+GET_NEXT_LINE)
$(LIBFT):
	@make -sC $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
clean:
	@make clean -sC $(LIBFT_DIR)
	@rm -f $(OBJECT_FILES)
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#         SO_LONG CLEANED     .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
