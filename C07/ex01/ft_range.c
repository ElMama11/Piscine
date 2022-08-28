/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:17:52 by mverger           #+#    #+#             */
/*   Updated: 2021/09/22 18:20:13 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	size_tab;
	int	i;

	i = 0;
	tab = 0;
	if (min >= max)
		return (NULL);
	size_tab = (max - min) - 1;
	tab = (int *)malloc(sizeof(int) * size_tab);
	if (!tab)
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
