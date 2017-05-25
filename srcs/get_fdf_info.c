#include "fdf.h"

void			check_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_strcont("-+ ", line[i]))
		{
			ft_printf("Error: invalid symbol in the map: {%c}\n", line[i]);
			exit(0);
		}
		i++;
	}
}

size_t			get_cols(char *line)
{
	size_t	cols;
	char	**nbrs;

	nbrs = ft_strsplit(line, ' ');
	cols = 0;
	while (nbrs[cols])
		cols++;
	return (cols);
}

t_fdf_info		get_fdf_info(char *filename)
{
	t_fdf_info	info;
	char		*line;
	int			fd;

	info.rows = 0;
	info.cols = 0;
	line = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror(filename);
		exit(0);
	}
	if (get_next_line(fd, &line) > 0)
	{
		check_line(line);
		info.cols = get_cols(line);
		info.rows++;
	}
	while (get_next_line(fd, &line) > 0)
	{
		check_line(line);
		if (get_cols(line) != info.cols)
		{
			ft_printf("Error: columns not homogeneous\n");
			exit(0);
		}
		info.rows++;
	}
	close(fd);
	return (info);
}
