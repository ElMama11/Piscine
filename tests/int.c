/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:02:16 by mverger           #+#    #+#             */
/*   Updated: 2021/09/23 18:43:36 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char output[55];
	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					if (check(output, argv[1][i]))
					{
						output[k] = argv[1][i];
						k++;
					}
				}
				j++;
			}
			i++;
		}
		output[k] = '\0';
		i = 0;
		while (output[i])
		{	
			write(1, &output[i],1);
			i++;
		}
		write(1,"\n",1);
	}
	else
		write(1, "\n", 1);
	
	return (0);
}


