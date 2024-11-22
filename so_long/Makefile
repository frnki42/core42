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
LFTPFGNL_DIR	= ./libftprintfgnl
LFTPFGNL	= $(LFTPFGNL_DIR)/libftprintfgnl.a

# MLX
MLXFLAGS 	= -L/usr/lib/X11 -lXext -lX11 -lm -lz

# SRC- & OBJ-FILES
SOURCE_FILES 	= main.c 
OBJECT_FILES 	= ${SOURCE_FILES:.c=.o}

INCLUDES 	= -I$(LFTPFGNL_DIR)

# COMMANDS
all: $(NAME)

$(NAME): $(LFTPFGNL) $(OBJECT_FILES)
	@ar -rcs $(NAME) $(OBJECT_FIES) $(LFTPFGNL_DIR)/*.o 
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#         SO_LONG COMPILED    .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
# LIBFT+PRINTF+GET_NEXT_LINE
$(LFTPFGNL):
	@make -sC $(LFTPFBNL_DIR)

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
.PHONY: all clean fclean re #bonus
