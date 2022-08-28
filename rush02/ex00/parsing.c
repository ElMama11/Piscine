/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:26:11 by mverger           #+#    #+#             */
/*   Updated: 2021/09/19 23:06:08 by pdal-mol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
char    *ft_check_input_nb(char **argv, int arg_i);

int	ft_check_isspace(char **argv, int arg_i)
{
	int	i;

	i = 0;
	while (argv[arg_i][i] == ' ' ||
		(argv[arg_i][i] >= 9 && argv[arg_i][i] <= 13))
	{
		i++;
	}
	return (i);
}

int	ft_check_sign(char **argv, int arg_i)
{
	int	pair;
	int	i;

	i = ft_check_isspace(argv, arg_i);
	pair = 0;
	while (argv[arg_i][i] == '+' || argv[arg_i][i] == '-')
	{
		if (argv[arg_i][i] == '-')
			pair++;
		i++;
	}
	if ((pair % 2) != 0)
		return (0);
	return (1);
}

int	ft_print_error(int argc, char **argv)
{
	int	arg_i;
	int	i;

	arg_i = 0;
	if (argc == 1 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		arg_i = 1;
		if (!(ft_check_sign(argv, arg_i)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (!(ft_check_input_nb(argv, arg_i)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	if (argc == 3)
	{
		arg_i = 2;
		if (!(ft_check_sign(argv, arg_i)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (!(ft_check_input_nb(argv, arg_i)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}
