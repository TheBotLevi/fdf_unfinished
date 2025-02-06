/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:34:41 by ljeribha          #+#    #+#             */
/*   Updated: 2025/01/14 10:48:36 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H

#include "minilibx-linux/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

#define WIDTH 1000
#define HEIGHT 800
#define SCALE 20
#define ANGLE 0.523599 // 30 degrees in radians

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;


#endif