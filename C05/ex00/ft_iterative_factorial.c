/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:21:55 by mverger           #+#    #+#             */
/*   Updated: 2021/09/14 22:09:29 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorielle;

	factorielle = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		factorielle = factorielle * nb;
		nb--;
	}
	return (factorielle);
}

/*int main(void)
{
	printf("%d", ft_iterative_factorial(5));
	return (0);
}*/
