/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:14:51 by ljeribha          #+#    #+#             */
/*   Updated: 2025/01/29 17:13:09 by ljeribha         ###   ########.fr       */
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

void	render_map(t_mlx *mlx, int **grid, int rows, int cols);
int	**read_fdf_files(const char *filename, int *rows, int *cols);
int	key_press(int keycode, t_mlx *mlx);
int	close_window(t_mlx *mlx);
void	isometric(int *x, int *y, int z);
void	draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color);
void	free_grid(int **grid, int rows);
void	error_message(char *message);
void	clean_up(t_mlx *mlx, int **grid, int rows);

#endif