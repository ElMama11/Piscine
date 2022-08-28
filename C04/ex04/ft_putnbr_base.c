/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:49:32 by mverger           #+#    #+#             */
/*   Updated: 2021/09/15 17:36:32 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int i, char *base)
{
	char			print[50];
	int				j;
	unsigned int	n;

	j = 0;
	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	while (n > 0)
	{
		print[j++] = base[n % i];
		n = n / i;
	}
	while (j >= 0)
	{
		write(1, &print[j--], 1);
	}
}

int	ft_print_error(char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (base[0] == 0 || i == 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_print_error(base))
	{
		while (base[i])
			i++;
		ft_putnbr(nbr, i, base);
	}
}

/*int	main(void)
{
	ft_putnbr_base(-2147483648, "01");
}*/
