/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:41:46 by ljeribha          #+#    #+#             */
/*   Updated: 2025/02/01 11:17:08 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_grid(int **grid, int rows)
{
	int	i = 0;

	if (!grid)
		return;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
