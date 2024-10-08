# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efembock <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 13:25:06 by efembock          #+#    #+#              #
#    Updated: 2024/10/02 10:46:41 by efembock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS - CUSTOM
BLACK_ON_G	:= \033[42;30m
COLOR_OFF	:= \033[0m

# VARIABLES
NAME		:= libftprintf.a
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
SOURCE_FILES:= ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putptr.c ft_putstr.c \
	       ft_putunsigned.c ft_printf.c ft_format.c
OBJECT_FILES:= ${SOURCE_FILES:.c=.o}

# COMMANDS
$(NAME): $(OBJECT_FILES)
	ar -rcs $(NAME) $(OBJECT_FILES)
	@echo "$(BLACK_ON_G)########################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#        COMPILATION COMPLETE  .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)########################################$(COLOR_OFF)"
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJECT_FILES) $(BONUS_OBJECT)
	@echo "$(BLACK_ON_G)########################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#           CLEAN COMPLETE!  .frnki    #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)########################################$(COLOR_OFF)"
fclean: clean
	@rm -f $(NAME)
re: fclean all
all: $(NAME)
.PHONY: all clean fclean re
