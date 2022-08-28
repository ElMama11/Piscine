/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:54:57 by mverger           #+#    #+#             */
/*   Updated: 2021/09/08 14:23:47 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

int	ft_check_lowercase(char src)
{
	if (src >= 'a' && src <= 'z')
		return (1);
	return (0);
}

int	ft_uppercase(char src)
{
	if (src >= 'A' && src <= 'Z')
		return (1);
	return (0);
}

int	ft_other(char src)
{
	if (!(ft_check_lowercase(src) || ft_uppercase(src)
			|| (src >= '0' && src <= '9')))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if (ft_check_lowercase(str[0]))
	{
		str[0] -= 32;
		i++;
	}
	while (str[i])
	{
		if (ft_other(str[i - 1]) && ft_check_lowercase(str[i]))
			str[i] -= 32;
		i++;
	}	
	return (str);
}
