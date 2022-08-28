/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:36:51 by mverger           #+#    #+#             */
/*   Updated: 2021/09/16 18:51:54 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	nbr;

	nbr = 2;
	if (nb <= 1)
		return (0);
	while (nbr <= nb / nbr)
	{
		if (nb % nbr == 0)
			return (0);
		nbr++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (i >= nb)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
	return (nb);
}

/*int	main(void)
{
	printf("%d\n", ft_find_next_prime(90));
}*/
