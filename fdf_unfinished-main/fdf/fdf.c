/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:10:08 by ljeribha          #+#    #+#             */
/*   Updated: 2025/02/06 19:05:22 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_data	data;

	data.cols = 0;
	data.rows = 0;
	if (ac != 2) {
		ft_printf("Usage: %s <file.fdf>.\n", av[0]);
		return(1);
	}
	mlx.mlx_ptr =  mlx_init();
	if (!mlx.mlx_ptr) {
		ft_printf("Error initializing MLX.\n");
		return (1);
	}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "FDF Project!");
	if (!mlx.win_ptr) {
		ft_printf("Error in creating window.\n");
		clean_up(&mlx, &data);
		return (1);
	}
	data.grid = read_fdf_files(av[1], &data);
	if (!data.grid) {
		ft_printf("Error reading file.\n");
		clean_up(&mlx, &data);
		return (1);
	}
	render_map(&mlx, &data);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, NULL);
	mlx_key_hook(mlx.win_ptr, key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
	clean_up(&mlx, &data);
	return (0);
}
