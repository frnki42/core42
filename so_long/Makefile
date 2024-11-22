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

# MLX
MLXFLAGS 	= -Lminilibx-lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

# LIBRARIES
LIBFT_DIR	= ./printf/libft
LIBFT		= $(LIBFT_DIR)/libft.a
# SRC- & OBJ-FILES
SOURCE_FILES 	= main.c 
OBJECT_FILES 	= ${SOURCE_FILES:.c=.o}

INCLUDES 	= -I$(LIBFT_DIR)
#BONUS_SOURCE 	= 
#BONUS_OBJECT 	= ${BONUS_SOURCE:.c=.o}

# COMMANDS
all: $(NAME)
$(NAME): $(OBJECT_FILES)
	@$(CC) $(CFLAGS) $(OBJECT_FILES) $(MLXFLAGS) -o $(NAME) 
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#         SO_LONG COMPILED    .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
clean:
	@rm -f $(OBJECT_FILES) $(BONUS_OBJECT)
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#          SO_LONG CLEANED    .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
fclean: clean
	@rm -f $(NAME)
re: fclean all
#bonus: $(OBJECT_FILES) $(BONUS_OBJECT)
#	@ar rcs $(NAME) $(OBJECT_FILES) $(BONUS_OBJECT)
#	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
#	@echo "$(BLACK_ON_G)#     SO_LONG+BONUS COMPILED  .frnki  #$(COLOR_OFF)"
#	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
.PHONY: all clean fclean re #bonus
