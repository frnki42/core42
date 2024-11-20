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

# COLORS - CUSTOM
BLACK_ON_G	:= \033[42;30m
COLOR_OFF	:= \033[0m

# VARIABLES
NAME = so_long
CC = cc

# FLAGS
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lminilibx-linux -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Iminilibx-linux

SOURCE_FILES = 
OBJECT_FILES = ${SOURCE_FILES:.c=.o}
#BONUS_SOURCE = 
#BONUS_OBJECT = ${BONUS_SOURCE:.c=.o}
#LIBFT_DIR	:= ./libft
#LIBFT		:= $(LIBFT_DIR)/libft.a

# COMMANDS
all: $(NAME)
$(NAME): $(OBJECT_FILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECT_FILES) $(MLXFLAGS)
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
