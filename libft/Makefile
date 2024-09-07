# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efembock <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 13:25:06 by efembock          #+#    #+#              #
#    Updated: 2024/09/06 20:09:13 by efembock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c

OBJECT_FILES = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
ft_isascii.o ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
ft_memmove.o ft_memset.o ft_strchr.o ft_strdup.o ft_strlcat.o ft_strlcpy.o \
ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_tolower.o ft_toupper.o

$(NAME): $(OBJECT_FILES)
	ar rcs $(NAME) $(OBJECT_FILES)
ft_atoi.o: ft_atoi.c
	$(CC) $(CFLAGS) -c ft_atoi.c -o ft_atoi.o
ft_bzero.o: ft_bzero.c
	$(CC) $(CFLAGS) -c ft_bzero.c -o ft_bzero.o
ft_calloc.o: ft_calloc.c
	$(CC) $(CFLAGS) -c ft_calloc.c -o ft_calloc.o
ft_isalnum.o: ft_isalnum.c
	$(CC) $(CFLAGS) -c ft_isalnum.c -o ft_isalnum.o
ft_isalpha.o: ft_isalpha.c
	$(CC) $(CFLAGS) -c ft_isalpha.c -o ft_isalpha.o
ft_isascii.o: ft_isascii.c
	$(CC) $(CFLAGS) -c ft_isascii.c -o ft_isascii.o
ft_isdigit.o: ft_isdigit.c
	$(CC) $(CFLAGS) -c ft_isdigit.c -o ft_isdigit.o
ft_isprint.o: ft_isprint.c
	$(CC) $(CFLAGS) -c ft_isprint.c -o ft_isprint.o
ft_memchr.o: ft_memchr.c
	$(CC) $(CFLAGS) -c ft_memchr.c -o ft_memchr.o
ft_memcmp.o: ft_memcmp.c
	$(CC) $(CFLAGS) -c ft_memcmp.c -o ft_memcmp.o
ft_memcpy.o: ft_memcpy.c
	$(CC) $(CFLAGS) -c ft_memcpy.c -o ft_memcpy.o
ft_memmove.o: ft_memmove.c
	$(CC) $(CFLAGS) -c ft_memmove.c -o ft_memmove.o
ft_memset.o: ft_memset.c
	$(CC) $(CFLAGS) -c ft_memset.c -o ft_memset.o
ft_strchr.o: ft_strchr.c
	$(CC) $(CFLAGS) -c ft_strchr.c -o ft_strchr.o
ft_strdup.o: ft_strdup.c
	$(CC) $(CFLAGS) -c ft_strdup.c -o ft_strdup.o
ft_strlcat.o: ft_strlcat.c
	$(CC) $(CFLAGS) -c ft_strlcat.c -o ft_strlcat.o
ft_strlcpy.o: ft_strlcpy.c
	$(CC) $(CFLAGS) -c ft_strlcpy.c -o ft_strlcpy.o
ft_strlen.o: ft_strlen.c
	$(CC) $(CFLAGS) -c ft_strlen.c -o ft_strlen.o
ft_strncmp.o: ft_strncmp.c
	$(CC) $(CFLAGS) -c ft_strncmp.c -o ft_strncmp.o
ft_strnstr.o: ft_strnstr.c
	$(CC) $(CFLAGS) -c ft_strnstr.c -o ft_strnstr.o
ft_strrchr.o: ft_strrchr.c
	$(CC) $(CFLAGS) -c ft_strrchr.c -o ft_strrchr.o
ft_tolower.o: ft_tolower.c
	$(CC) $(CFLAGS) -c ft_tolower.c -o ft_tolower.o
ft_toupper.o: ft_toupper.c
	$(CC) $(CFLAGS) -c ft_toupper.c -o ft_toupper.o
clean:
	rm -f $(OBJECT_FILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
all: $(NAME)
	
.PHONY: all clean flcean re
