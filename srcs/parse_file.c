/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:32:40 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/23 22:40:24 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*parse_line(char *line)
{
	ft_printf("%s\n", line);
	return (NULL);
}

int			**parse_file(char *filename)
{
	int			**res;
	char		*line;
	int			fd;

	line = NULL;
	res = NULL;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		parse_line(line);
	close(fd);
	return (res);
}
