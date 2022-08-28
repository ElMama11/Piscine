/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:25:06 by mverger           #+#    #+#             */
/*   Updated: 2021/09/21 15:23:04 by mverger          ###   ########lyon.fr   */
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
			ft_putstr(argv[i]);
			write(1, &c, 1);
			i++;
		}
	}
	return (0);
}
