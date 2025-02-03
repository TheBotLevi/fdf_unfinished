/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:48:50 by ljeribha          #+#    #+#             */
/*   Updated: 2025/02/01 11:15:30 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_cols(const char *line)
{
	int	count = 0;
	int	i = 0;

	while (line[i] && line[i] != '\n')
	{
		while (line[i] == ' ') // Skip spaces
			i++;
		if (line[i] && line[i] != '\n') // Found a number
		{
			count++;
			printf("Found number at index %d, count: %d\n", i, count);
			while (line[i] && line[i] != ' ' && line[i] != '\n')
			{
				printf("%c\n", line[i]);
				i++; // Move to next space or end of line
			}
		}
	}
	return (count);
}

int	count_rows(const char *filename)
{
	int	rows;
	int	fd;
	char	*line = NULL;

	rows = 0;
	fd = open(filename, O_RDONLY); //Open the file
	if (fd == -1)
	{
		perror("Error opening the file!");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL) //Read lines and count rows
	{
		if (line == NULL)
		{
			// Error occured in get_next_line
			perror("Error reading the file");
			free(line);
			close(fd);
			return (-1);
		}
		rows++;
		free(line); // Free the allocated memory in the curent line
	}
	if (close(fd) == -1) //If error in closing file
	{
		perror("Error closing the file");
		return (-1);
	}
	return (rows);
}

static int	*fill_row(char *line, int cols)
{
	int		*row;
	int		i;
	char	*ptr;

	row = malloc(sizeof(int) * cols);
	if (!row)
		return (NULL);
	i = 0; // Initialize index 0, pretty simple stuff
	ptr = line; // Point to the start of the line
	while (i < cols && *ptr)// Loop until th end of line or max columns reached
	{
		row[i] = ft_atoi(ptr); // Convert the current number into an integer
		i++;
		while (*ptr && *ptr != ' ') // Skip over the current number until dspace or end of the line
			ptr++;
		while (*ptr == ' ') // Skip consctutiv spaces between numbers
			ptr++;
	}
	if (i != cols)
	{
		free(row);
		return (NULL);
	}
	return (row);
}

int	**read_fdf_files(const char *filename, int *rows, int *cols)
{
	int		fd;
	int		**grid;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		perror("Error reading first line");
		close(fd);
		return (NULL);
	}
	*rows = count_rows(filename);
	if (fd == -1 || *rows <= 0)
	{
		perror("Error opening file");
		return (NULL);
	}
	*cols = count_cols(line);
	free(line);
	close(fd);

	// For debugging purposes
	ft_printf("Rows: %d, Cols: %d\n", *rows, *cols);
	
	grid = malloc(sizeof(int *) * (*rows));
	if (!grid)
	{
		close(fd);
		perror("Error allocating grid");
		return (NULL);
	}
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error reopening file");
		free(grid);
		return (NULL);
	}
	while (i < *rows && (line = get_next_line(fd)))
	{
		grid[i] = fill_row(line, *cols);
		free(line);
		if (!grid[i++])
		{
			perror("Error allocating row");
			free_grid(grid, i);
			close(fd);
			return (NULL);
		}
	}
	close(fd);
	return (grid);
}
