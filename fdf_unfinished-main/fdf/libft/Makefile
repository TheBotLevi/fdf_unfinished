# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 14:43:37 by ljeribha          #+#    #+#              #
#    Updated: 2025/01/27 13:00:01 by ljeribha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC = ar rc
LIBR = ranlib
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCS = .
NAME = libft.a
LIB = ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
ADDFONC = ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstlast.c
BONUS_OBJS = ${BONUS:.c=.o}
OBJS = $(SRCS:.c=.o)
SRCS = ${LIB} ${ADDFONC}

.c.o:
	${CC} -g ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

clean:
	rm -f $(OBJS) ${BONUS_OBJS}

all: $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus : ${OBJS} ${BONUS_OBJS}
	${LIBC} ${NAME} ${OBJS} ${BONUS_OBJS}
	${LIBR} ${NAME}
