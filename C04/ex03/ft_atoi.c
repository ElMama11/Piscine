/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:50:02 by mverger           #+#    #+#             */
/*   Updated: 2021/09/15 20:17:05 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	neg(int nb, int pair)
{
	if ((pair % 2) != 0)
		nb *= -1;
	return (nb);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	pair;

	nb = 0;
	i = 0;
	pair = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			pair++;
		}
		i++;
	}
	while (ft_check_numeric(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}	
	return (neg(nb, pair));
}

/*int	main(void)
{
	printf("%d\n", ft_atoi("42t4457"));
}*/
