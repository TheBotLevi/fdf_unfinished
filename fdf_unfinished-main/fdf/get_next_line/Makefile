# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 11:14:40 by ljeribha          #+#    #+#              #
#    Updated: 2025/02/06 19:17:45 by ljeribha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
INCS = get_next_line.h
NAME = get_next_line
LIB = get_next_line.c
OBJS = ${SRCS:.c=.o}
SRCS = ${LIB}

.c.o: ${INCS}
	${CC} -g ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} -g ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

all: $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all