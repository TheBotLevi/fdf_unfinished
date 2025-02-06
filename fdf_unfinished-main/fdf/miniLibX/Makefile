# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 09:32:38 by ljeribha          #+#    #+#              #
#    Updated: 2025/01/27 13:00:33 by ljeribha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I${MLX_INC} #-I${GET_NEXT_LINE_PATH} -I${LIBFT_PATH}

INCLUDES = test.h
MLX_INC = minilibx-linux
#GET_NEXT_LINE_PATH = ../get_next_line
#LIBFT_PATH = ../libft

MLX_LIB = ${MLX_INC}/libmlx_Linux.a
#GET_NEXT_LINE = ${GET_NEXT_LINE_PATH}/get_next_line.a
#LIBFT = ${LIBFT_PATH}/libft.a

TEST_SRC = test_test.c
TEST_OBJS = ${TEST_SRC:.c=.o}

TEST = test

LDFLAGS = -L${MLX_INC} -lmlx_Linux -lX11 -lXext -lm #-L${GET_NEXT_LINE_PATH} -lget_next_line -L${LIBFT_PATH} -lft

all: ${TEST}

${TEST}: ${TEST_OBJS} ${MLX_LIB} #${GET_NEXT_LINE} ${LIBFT}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

${MLX_LIB}:
	${MAKE} -C ${MLX_INC}

#{GET_NEXT_LINE}:
#	${MAKE} -C ${GET_NEXT_LINE_PATH}

#${LIBFT}:
#	${MAKE} -C ${LIBFT_PATH}

%.o: %.c ${INCLUDES}
	${CC} -g ${CFLAGS} -c $< -o $@

clean:
	${MAKE} -C ${MLX_INC} clean
#	${MAKE} -C ${GET_NEXT_LINE_PATH} clean
#	${MAKE} -C ${LIBFT_PATH} clean
	rm -f *.o

fclean: clean
	${MAKE} -C ${MLX_INC} fclean
#	${MAKE} -C ${GET_NEXT_LINE_PATH} fclean
#	${MAKE} -C ${LIBFT_PATH} fclean
	rm -f ${TEST}

re: fclean all