/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 23:09:07 by mverger           #+#    #+#             */
/*   Updated: 2021/09/16 20:23:49 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	power;
	unsigned int	nbr;

	nbr = nb;
	power = 0;
	while (power * power < nbr)
		power++;
	if (power * power == nbr)
		return (power);
	else
		return (0);
}

/*int	main(void)
{
	printf("sqrt of %d is %d\n", -1747, ft_sqrt(-1747));
       printf("sqrt of %d is %d\n", 0, ft_sqrt(0));
       printf("sqrt of %d is %d\n", 1, ft_sqrt(1));
       printf("sqrt of %d is %d\n", 2, ft_sqrt(2));
       printf("sqrt of %d is %d\n", 1640045925, ft_sqrt(1640045925));
       printf("sqrt of %d is %d\n", 2147395600, ft_sqrt(2147395600));
       printf("sqrt of %d is %d\n", 2147483646, ft_sqrt(2147483646));
       printf("sqrt of %d is %d\n", 658281649, ft_sqrt(658281649));
       printf("sqrt of %d is %d\n", 1628150304, ft_sqrt(1628150304));
       printf("sqrt of %d is %d\n", 1098723609, ft_sqrt(1098723609));
       printf("sqrt of %d is %d\n", 1456626656, ft_sqrt(1456626656));
       printf("sqrt of %d is %d\n", 848323876, ft_sqrt(848323876));
       printf("sqrt of %d is %d\n", 1741052876, ft_sqrt(1741052876));
       printf("sqrt of %d is %d\n", 469935684, ft_sqrt(469935684));
       printf("sqrt of %d is %d\n", 1007329317, ft_sqrt(1007329317));
       printf("sqrt of %d is %d\n", 713477521, ft_sqrt(713477521));
       printf("sqrt of %d is %d\n", 590568711, ft_sqrt(590568711));
}*/
