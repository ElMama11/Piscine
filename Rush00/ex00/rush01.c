/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:36:39 by gdurand           #+#    #+#             */
/*   Updated: 2021/09/05 16:55:30 by gdurand          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* #include "ft_putchar.c" */

void	ft_putline(int x, char start, char mid, char end)
{
	int	i;

	i = 1;
	if (x <= 0)
		return ;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(start);
		if (x == 1)
		{
			ft_putchar('\n');
			return ;
		}	
		if (i != 1 && i != x)
			ft_putchar(mid);
		if (i == x)
		{
			ft_putchar(end);
			ft_putchar('\n');
		}
		i++;
	}
}

void	rush(int x, int y)
{
	int	i;

	if (y <= 0)
		return ;
	i = 2;
	ft_putline(x, '/', '*', '\\');
	while (++i <= y)
		ft_putline(x, '*', ' ', '*');
	if (y != 1)
		ft_putline(x, '\\', '*', '/');
}
