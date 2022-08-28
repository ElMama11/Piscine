/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:33:10 by aandric           #+#    #+#             */
/*   Updated: 2021/09/21 10:20:02 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "t_dict.h"

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);

char	*ft_strcat(char c, char d)
{
	char	*tab;

	tab = malloc(sizeof(char) * 2 + 1);
	if (tab == 0)
		return (0);
	tab[0] = c;
	tab[1] = d;
	return (tab);
}

int	ft_ccmp(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c != str[i])
			return (c - str[i]);
		i++;
	}
	return (0);
}

void	ft_print_dict_str(char *nb_num, t_dict *array)
{
	int	i;

	i = 0;
	while (array[i].num)
	{
		if (ft_strcmp(nb_num, array[i].num) == 0)
		{
			ft_putstr(array[i].lit);
			write(1, " ", 1);
			break ;
		}
		i++;
	}
}

void	ft_print_dict_char(char nb_num, t_dict *array)
{
	int	i;

	i = 0;
	while (array[i].num)
	{
		if (ft_ccmp(nb_num, array[i].num) == 0)
		{
			ft_putstr(array[i].lit);
			write(1, " ", 1);
			break ;
		}
		i++;
	}
}

int	ft_print_dec(char nb_num, char nb_num2, t_dict *array, int i)
{
	char	*tab;

	tab = malloc(sizeof(char) * 2 + 1);
	if (tab == 0)
		return (0);
	if (nb_num == '1')
	{
		tab = ft_strcat(nb_num, nb_num2);
		ft_print_dict_str(tab, array);
		i += 2;
	}
	if (nb_num > '1')
	{
		tab = ft_strcat(nb_num, '0');
		ft_print_dict_str(tab, array);
		i++;
	}
	return (i);
}

void	ft_print_hundred(char nb_num, t_dict *array)
{
	ft_print_dict_char(nb_num, array);
	ft_print_dict_str("100", array);
}

void	ft_read_num(char *nb_num, t_dict *array)
{

	int	i;

	i = 0;
	if (ft_strlen(nb_num)  == 1)
		i = 2;
	if (ft_strlen(nb_num) == 2)
		i = 1;
	while (nb_num[i])
	{
		while (nb_num[i] == '0')
			i++;
		if (i == 0)
		{	
			ft_print_hundred(nb_num[i], array);
			i++;
		}
		while (nb_num[i] == '0')
			i++;
		if (i == 1)
			i = ft_print_dec(nb_num[i], nb_num[i + 1], array, i);
		while (nb_num[i] == '0')
			i++;
		if (i == 2)
		{
			if (ft_strlen(nb_num) == 1)
				ft_print_dict_char(nb_num[0], array);
			else 
				ft_print_dict_char(nb_num[i], array);
			i++;
		}
	}
}
