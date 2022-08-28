/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:04:31 by mverger           #+#    #+#             */
/*   Updated: 2021/09/17 14:14:04 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	c = '\n';
	i = 1;
	if (argc > 0)
	{
		while (argv[i])
		{	
			i++;
		}
		while (i > 1)
		{	
			ft_putstr(argv[i - 1]);
			write(1, &c, 1);
			i--;
		}
	}
	return (0);
}
