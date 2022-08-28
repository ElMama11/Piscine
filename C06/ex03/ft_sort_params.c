/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:46:09 by mverger           #+#    #+#             */
/*   Updated: 2021/09/22 12:16:49 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	if (s1[i] > s2[i])
		return (0);
	return (1);
}

void	ft_swap(char **a, char **b)
{
	char	*c;
	char	*d;

	c = *a;
	d = *b;
	*a = d;
	*b = c;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putarg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{	
		ft_putstr(argv[i++]);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	j = argc - 1;
	i = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			while (j > 1)
			{
				if (ft_strcmp(argv[j], argv[j - 1]))
					ft_swap(&argv[j - 1], &argv[j]);
				j--;
			}
			j = argc - 1;
			i++;
		}
	}
	ft_putarg(argv);
	return (0);
}
