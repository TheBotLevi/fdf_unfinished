/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:41:46 by ljeribha          #+#    #+#             */
/*   Updated: 2025/02/06 17:32:26 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_grid(t_data *data)
{
	int	i = 0;

	if (!data->grid)
		return;
	while (i < data->rows)
	{
		free(data->grid[i]);
		i++;
	}
	free(data->grid);
}
