# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 09:32:38 by ljeribha          #+#    #+#              #
#    Updated: 2024/12/30 13:04:58 by ljeribha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = test.h
MLX_INC = minilibx-linux/minilibx-linux
MLX_LIB = ${MLX_INC}/libmlx_Linux.a

TEST_SRC = test.c
TEST_OBJS = ${TEST_SRC:.c=.o}

TEST = test

LDFLAGS = -L${MLX_INC} -lmlx_Linux -lX11 -lXext

all: ${TEST}

${TEST}: ${TEST_OBJS} ${MLX_LIB}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

${MLX_LIB}:
	${MAKE} -C ${MLX_INC}

%.o: %.c ${INCLUDES}
	${CC} ${CFLAGS} -I${MLX_INC} -c $< -o $@

clean:
	${MAKE} -C ${MLX_INC} clean
	rm -f *.o

fclean: clean
	${MAKE} -C ${MLX_INC} fclean
	rm -f ${TEST}

re: fclean all