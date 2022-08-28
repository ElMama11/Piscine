/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:41:24 by pdal-mol          #+#    #+#             */
/*   Updated: 2021/09/19 22:48:57 by pdal-mol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "t_dict.h"

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_dict(t_dict *array)
{
	int	i;

	i = 0;
	while (array[i].num)
	{
		if (!ft_str_is_numeric(array[i].num))
			return (0);
		i++;
	}
	return (1);
}
