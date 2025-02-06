/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:39 by ljeribha          #+#    #+#             */
/*   Updated: 2025/01/14 15:14:31 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	count_cols(const char *line) // Function to count the number of columns in a line
{
	int			count;
	int			i;
	const char	*cols = line;

	count = 0;
	i = 0;
	while (cols[i])
	{
		while (cols[i] == ' ')
			i++; // Skip spaces
		if (cols[i] && cols[i] != '\n')
		{
			count++; // Found a number
			while (cols[i] && cols[i] != ' ' && cols[i] != '\n')
				i++; // Move to next space or end of the line
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
	// Open the file
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file!");
		return (-1);
	}
	// Read lines and count rows
	while ((line = get_next_line(fd)) != NULL)
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
	// Error in closing file
	if (close(fd) == -1)
	{
		perror("Error closing the file");
		return (-1);
	}
	return (rows);
}

int	**read_fdf_files(const char *filename, int *rows, int *cols)
{
	int	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file: %s\n", filename);
		return (NULL);
	}
	char	*line = NULL;
	*rows = count_rows(filename);
	if ((line = get_next_line(fd)) != NULL)
	{
		*cols = count_cols(line);
		free(line);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error reopening file");
		exit(EXIT_FAILURE);
	}
	int	**grid = malloc(sizeof(int *) * (*rows));
	if (!grid)
	{
		printf("Memory allocation failed for grid.\n");
		close(fd);
		return (NULL);
	}
	int	i = 0;
	while (i < *rows)
	{
		grid[i] = malloc(sizeof(int) * (*cols));
		if (!grid[i])
		{
			printf("Memory allocation failed for grid[%d].\n", i);
			close(fd);
			return (NULL);
		}
		i++;
	}
	int	row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		int	col = 0;
		char	*ptr = line;
		char	*end;

		// Process each token until the end of the line or max columns reached
		while (col < *cols && (end = ft_strchr(ptr, ' ')))
		{
			*end = '\0'; // Replace space with null terminator to isolate each token
			grid[row][col] = ft_atoi(ptr); // Convert the isolated token to an integer
			ptr = end + 1; // Move the pointer to the character after the space
			col++; // Move to the next column
		}
		// Handle the last token if there are no trailing spaces
		if (col < *cols && *ptr != '\0')
			grid[row][col] = ft_atoi(ptr);
		row++;
	}
	close(fd);
	return (grid);
}

int	main(int ac, char **av)
{
	// Handeling the error
	if (ac != 2)
	{
		printf("Usage: %s <file.fdf>\n", av[0]);
		return (1);
	}
	int	rows;
	int	cols;
	int	**grid = read_fdf_files(av[1], &rows, &cols);
	if (!grid)
		return (1);
	// Print the grid (Testing purposes!)
	int	i = 0;
	while (i < rows)
	{
		int	j = 0;
		while (j < cols)
		{
			printf("%d", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	// Memory allocation
	i = 0;
	while (i < rows)
	{
		if (grid[i])
			free(grid[i]);
		i++;
	}
	free(grid);
	return (0);
}