/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:07:31 by ljeribha          #+#    #+#             */
/*   Updated: 2025/01/27 14:24:27 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	j;

	j = (char) c;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (j == *s)
			return ((char *)s);
		s++;
	}
	if (*s == j)
		return ((char *)s);
	return (0);
}

/*int	main()
{
	const char	*str = "Hello, World!";
	int	i = 'o';

	char	*result = ft_strchr(str, i);

	if (result != NULL)
		printf("Found '%c' in the String: %s\n", i, result);
	else
		printf("Character '%c' not found in String: %s\n", i, str);
	return (0);
}*/
