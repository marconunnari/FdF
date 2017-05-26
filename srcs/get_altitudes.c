/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_altitudes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:47:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 15:45:22 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_row(int i, char *line, int **alts, t_fdf_info info)
{
	int			j;
	char		**nbrs;

	alts[i] = (int*)malloc(sizeof(int) * info.cols);
	nbrs = ft_strsplit(line, ' ');
	j = 0;
	while (*nbrs)
	{
		alts[i][j] = ft_atoi(*nbrs);
		nbrs++;
		j++;
	}
}

int			**get_altitudes(char *filename, t_fdf_info info)
{
	int			**alts;
	char		*line;
	int			fd;
	int			i;

	line = NULL;
	fd = open(filename, O_RDONLY);
	alts = (int**)malloc(sizeof(int*) * info.rows);
	i = 0;
	while (get_next_line(fd, &line) > 0)
		set_row(i++, line, alts, info);
	close(fd);
	return (alts);
}
