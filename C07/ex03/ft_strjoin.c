/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:03:42 by mverger           #+#    #+#             */
/*   Updated: 2021/09/23 12:14:20 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_super_strlen(int size, char **strs, char *sep)
{
	int	size_strs;
	int	size_sep;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size_strs = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			j++;
			size_strs++;
		}
		j = 0;
		i++;
	}
	size_sep = (i - 1) * ft_strlen(sep);
	size_strs = size_strs + size_sep;
	return (size_strs);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		size_strs;
	char	*output;

	i = 0;
	j = 0;
	if (size <= 0)
		return (output = 0);
	size_strs = ft_super_strlen(size, strs, sep);
	output = (char *)malloc(sizeof(char) * (size_strs + 1));
	if (output == NULL)
		return (NULL);
	output[0] = '\0';
	while (i < size)
	{	
		ft_strcat(output, strs[i]);
		i++;
		if (j < size - 1)
		{
			ft_strcat(output, sep);
			j++;
		}
	}
	return (output);
}

/*int	main(void)
{
	char	**tab;
	char	*sep = "a!!?|||||?!!a";
	char	*output;
	int		size = 5;

	tab = (char **)malloc(sizeof(char *) * (size + 1));
	tab[0] = "AUTOMATA";
	tab[1] = "NIER DRAKENGARD";
	tab[2] = "ZBEULZBEUL";
	tab[3] = "YEUZ PLISSES";
	tab[4] = "OKMEK";
	tab[5] = NULL;
	output = ft_strjoin(size, tab, sep);
	printf("%s", output);
	free(tab);
	free(output);
}*/
