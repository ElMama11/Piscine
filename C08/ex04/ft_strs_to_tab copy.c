/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:43:11 by mverger           #+#    #+#             */
/*   Updated: 2021/09/23 17:18:28 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	char	*str_mal;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	str_mal = malloc((i + 1) * sizeof(char));
	if (str_mal == NULL)
		return (NULL);
	while (src[j])
	{
		str_mal[j] = src[j];
		j++;
	}
	str_mal[j] = '\0';
	return (str_mal);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str)
		i++;
	return (i);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*str;
	int			i;

	i = 0;
	str = malloc(sizeof(t_stock_str) * (ac + 1));
	if (str == NULL)
		return (0);
	while (i < ac)
	{
		str[i].size = ft_strlen(av[i]);
		str[i].str = av[i];
		str[i].copy = ft_strdup(av[i]);
		i++;
	}
	str[i].str = 0;
	return (str);
}
