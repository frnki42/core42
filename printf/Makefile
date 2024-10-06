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

# VARIABLES
NAME		:= libftprintf.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
SOURCE_FILES:= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_striteri.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
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
