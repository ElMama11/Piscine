/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:52:49 by mverger           #+#    #+#             */
/*   Updated: 2021/09/23 12:03:43 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str_mal;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	str_mal = malloc((i + 1) * sizeof(char));
	if (str_mal == NULL)
		return (NULL);
	while (src[j])
	{
		str_mal[j] = src[j];
		j++;
	}
	str_mal[j] = '\0';
	return (str_mal);
}

/*int	main(void)
{
	char	src[15] = "";
	char	*str_mal = ft_strdup(src);
	printf("%s", str_mal);
}*/
