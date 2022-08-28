/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_tdict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:12:08 by pdal-mol          #+#    #+#             */
/*   Updated: 2021/09/21 10:45:00 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_dict.h"

char	**ft_dict_to_array(char *path);
char	*ft_trim(char *str, char c, char d);
char	**ft_split(char *str, char *charset);

int	ft_char_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**ft_format_dict(char *path)
{
	int		i;
	char	**to_trim;
	char	**output;

	to_trim = ft_dict_to_array(path);
	if (!to_trim)
		return (NULL);
	i = 0;
	while (to_trim[i])
		i++;
	output = malloc(sizeof(char *) * (i + 1));
	if (!output)
		return (0);
	i = 0;
	while (to_trim[i])
	{
		output[i] = ft_trim(to_trim[i], '\n', ' ');
		i++;
	}
	output[i] = 0;
	i = -1;
	while (output[++i])
		free(to_trim[i]);
	free(to_trim);
	return (output);
}

t_dict	*ft_char_to_tdict(char **array)
{
	t_dict	*output;
fd	char	**buff;
	int		i;

	i = 0;
	output = malloc(sizeof(t_dict) * (ft_char_arraylen(array) + 1));
	if (!output)
		return (0);
	while (array[i])
	{
		buff = ft_split(array[i], ":");
		output[i].num = buff[0];
		output[i].lit = buff[1];
		i++;
		free(buff);
	}
	output[i].num = 0;
	output[i].lit = 0;
	i = 0;
	return (output);
}
