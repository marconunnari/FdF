/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fdf_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:45:29 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 15:46:52 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			derive_info(t_fdf_info *info)
{
	info->tilewidth = SW / (info->cols + info->rows);
	if (info->tilewidth < 1)
		info->tilewidth = 1;
	info->mapwidth = (info->rows + info->cols - 2) * info->tilewidth;
	info->mapheight = (info->rows - 1) * info->tilewidth / 2 +
						(info->cols - 1) * info->tilewidth / 2;
	info->oy = (SH - info->mapheight) / 2;
	info->ox = (SW - info->mapwidth) / 2;;
	ft_printf("mapwidth %d\n", info->mapwidth);
}

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

void			parse_fd(int fd, t_fdf_info *info)
{
	char	*line;

	info->rows = 0;
	info->cols = 0;
	line = NULL;
	if (get_next_line(fd, &line) > 0)
	{
		check_line(line);
		info->cols = get_cols(line);
		info->rows++;
	}
	while (get_next_line(fd, &line) > 0)
	{
		check_line(line);
		if (get_cols(line) != info->cols)
		{
			ft_printf("Error: columns not homogeneous\n");
			exit(0);
		}
		info->rows++;
	}
}

t_fdf_info		get_fdf_info(char *filename)
{
	t_fdf_info	info;
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror(filename);
		exit(0);
	}
	else
	{
		parse_fd(fd, &info);
		close(fd);
	}
	derive_info(&info);
	return (info);
}
