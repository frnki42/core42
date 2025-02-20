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
NAME		= philo

# LIBRARIES
# SRC- & OBJ-FILES
PHILO_SOURCE 	= init.c philo.c
PHILO_OBJECT 	= ${PHILO_SOURCE:.c=.o}

# TARGETS
all: $(NAME)

$(NAME): $(PHILO_OBJECT)
	@ $(CC) $(CFLAGS) $(PHILO_OBJECT) -o $(NAME)
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#        PHILO COMPILED       .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(PHILO_OBJECT)
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#        PHILO CLEANED        .frnki  #$(COLOR_OFF)"
	@echo "$(BLACK_ON_G)#######################################$(COLOR_OFF)"
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
