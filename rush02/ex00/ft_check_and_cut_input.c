/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_cut_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:57:16 by pdal-mol          #+#    #+#             */
/*   Updated: 2021/09/19 23:01:18 by pdal-mol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char	*str);

long long	ft_atoi(char *str)
{
	int			i;
	long long	output;

	i = 0;
	output = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		output = output * 10 + str[i] - '0';
		i++;
	}
	return (output);
}

int	ft_nblen(int nb)
{
	int			output;
	long long	nbl;

	output = 1;
	nbl = nb;
	if (nbl < 0)
	{
		nbl *= (-1);
		output++;
	}
	while (nbl > 9)
	{
		nbl /= 10;
		output++;
	}
	return (output);
}

char	*ft_strreverse(char *str)
{
	int		i;
	char	buff;

	i = 0;
	while (i < ft_strlen(str) / 2)
	{
		buff = str[i];
		str[i] = str[ft_strlen(str) - i - 1];
		str[ft_strlen(str) - i - 1] = buff;
		i++;
	}
	return (str);
}

char	*ft_itoa(long long nb)
{
	long long	nbl;
	char		*output;
	int			output_len;
	int			i;

	nbl = nb;
	output_len = ft_nblen(nb);
	i = 0;
	output = malloc(output_len * sizeof(char));
	while (nbl > 9)
	{
		output[i] = (nbl % 10) + '0';
		nbl /= 10;
		i++;
	}
	output[i] = (nbl % 10) + '0';
	i++;
	return (ft_strreverse(output));
}

char	*ft_check_input_nb(char **argv, int arg_i)
{
	int			i;
	long long	nb;
	char		*nb_num;

	i = 0;
	while (argv[arg_i][i])
		i++;
	if (i > 10)
		return (0);
	nb = ft_atoi(argv[arg_i]);
	if (nb <= 4294967295)
		nb_num = ft_itoa(nb);
	return (nb_num);
}
