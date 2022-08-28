/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:58:49 by mverger           #+#    #+#             */
/*   Updated: 2021/09/05 11:58:55 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	nb_stock;

	i = 0;
	nb_stock = 0;
	while (i < size)
	{
		nb_stock = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = nb_stock;
		i++;
		size--;
	}
}
