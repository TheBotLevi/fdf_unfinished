# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 17:25:08 by ljeribha          #+#    #+#              #
#    Updated: 2025/01/27 14:20:48 by ljeribha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra

INCLUDES = fdf.h
LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf
GET_NEXT_LINE_PATH = get_next_line
MLX_INC = miniLibX/minilibx-linux
MLX_LIB = ${MLX_INC}/libmlx_Linux.a

FT_PRINTF = ${FT_PRINTF_PATH}/libftprintf.a
GET_NEXT_LINE = ${GET_NEXT_LINE_PATH}/get_next_line.a
LIBFT = ${LIBFT_PATH}/libft.a

SRCS = draw.c fdf.c hooks.c start.c read.c free.c error.c
OBJS = ${SRCS:.c=.o}

FDF = fdf

LDFLAGS = -L${MLX_INC} -lmlx_Linux -lX11 -lXext -L${FT_PRINTF_PATH} -L${GET_NEXT_LINE_PATH} -L${LIBFT_PATH} -l:libftprintf.a -l:get_next_line.a -lft -lm
HEADERS = -I. -I${LIBFT_PATH} -I${FT_PRINTF_PATH} -I${GET_NEXT_LINE_PATH} -I${MLX_INC}

all: ${FDF}

${FDF}: ${OBJS} ${MLX_LIB} ${FT_PRINTF} ${GET_NEXT_LINE} ${LIBFT}
	${CC} -g ${CFLAGS} ${HEADERS} -o $@ $^ ${LDFLAGS}

${MLX_LIB}:
	${MAKE} -C ${MLX_INC}

${FT_PRINTF}:
	${MAKE} -C ${FT_PRINTF_PATH}

${GET_NEXT_LINE}:
	${MAKE} -C ${GET_NEXT_LINE_PATH}

${LIBFT}:
	${MAKE} -C ${LIBFT_PATH}

%.o:%.c ${INCLUDES}
	${CC} -g ${CFLAGS} ${HEADERS} -c $< -o $@

clean:
	${MAKE} -C ${FT_PRINTF_PATH} clean
	${MAKE} -C ${GET_NEXT_LINE_PATH} clean
	${MAKE} -C ${LIBFT_PATH} clean
	rm -f *.o

fclean: clean
	${MAKE} -C ${FT_PRINTF_PATH} fclean
	${MAKE} -C ${GET_NEXT_LINE_PATH} fclean
	${MAKE} -C ${LIBFT_PATH} fclean
	rm -f ${FDF}

re: fclean all

.PHONY: all clean fclean re