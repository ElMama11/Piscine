/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:17:38 by pdal-mol          #+#    #+#             */
/*   Updated: 2021/09/19 18:02:02 by pdal-mol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	ft_trim_strlen(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (ft_strlen(str) - count);
}

char	*ft_trim(char *str, char c, char d)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	output = malloc((ft_trim_strlen(str, c) + 1) * sizeof(char));
	if (!output)
		return (0);
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && str[i] != d)
		{
			output[j] = str[i];
			j++;
		}
		i++;
	}
	output[i] = '\0';
	return (output);
}
