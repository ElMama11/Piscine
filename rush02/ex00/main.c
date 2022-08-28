#include <stdlib.h>
#include <fcntl.h>
#include "t_dict.h"
#define PATH_FILE "./numbers.dict"

void	ft_putstr(char *str);
char	**ft_format_dict(char *path);
t_dict	*ft_char_to_tdict(char **array);
int		ft_check_dict(t_dict *array);
int		ft_print_error(int argc, char **argv);
void    ft_read_num(char *nb_num, t_dict *array);

int	main(int argc, char **argv)
{
	int	i;
	char **array;
	t_dict *structarray;

	/* doesnt works */
	if (!ft_print_error(argc, argv))
		return (0); 
	array = ft_format_dict(PATH_FILE);
	if (!array)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	structarray = ft_char_to_tdict(array);
	if (!ft_check_dict(structarray))
	{
		ft_putstr("Dict Error\n");
		return (0);
	}

	/* only works with hundreds */	
	ft_read_num(argv[1], structarray);
	i = 0;
	while (array[i])
	{
		free (structarray[i].num);
		free(structarray[i].lit);
		free(array[i]);
		i++;
	}
	free(array);
	free(structarray);
}
