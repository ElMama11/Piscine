/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:06:31 by pdal-mol          #+#    #+#             */
/*   Updated: 2021/09/21 10:35:10 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);
void	ft_putstr(char *str);

int	ft_buff_len(char *path)
{
	int		count;
	char	buff[1];
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	count = 0;
	while (read(fd, buff, 1))
		count++;
	close(fd);
	return (count);
}

char	**ft_dict_to_array(char *path)
{
	int		fd;
	int		ret;
	char	*buff;
	int		buff_len;
	char	**array;

	buff_len = ft_buff_len(path);
	if (buff_len == -1)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buff = malloc(sizeof(char) * (buff_len + 1));
	if (!buff)
		return (0);
	ret = read(fd, buff, buff_len);
	buff[ret] = '\0';
	array = ft_split(buff, "\n");
	close(fd);
	free(buff);
	return (array);
}
