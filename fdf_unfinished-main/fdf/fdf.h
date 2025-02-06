/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:14:51 by ljeribha          #+#    #+#             */
/*   Updated: 2025/02/06 17:32:15 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "miniLibX/minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 800
#define SCALE 20 // Scaling factor for isometric projection
#define ANGLE 0.523599 // 30 degrees in radians


typedef struct s_data {
	int	**grid;
	int	rows;
	int	cols;
}	t_data;

typedef struct {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

void	render_map(t_mlx *mlx, t_data *data);
int	**read_fdf_files(const char *filename, t_data *data);
int	key_press(int keycode, t_mlx *mlx, t_data *data);
int	close_window(t_mlx *mlx, t_data *data);
void	isometric(int *x, int *y, int z);
void	draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color);
void	free_grid(t_data *data);
void	error_message(char *message);
void	clean_up(t_mlx *mlx, t_data *data);

#endif