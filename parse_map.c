/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:43:57 by afelten           #+#    #+#             */
/*   Updated: 2022/10/24 14:53:22 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	free_map(int **map);
t_point	*create_point(int line, int column, int value);

int	create_line(t_point **map, char *line, int x)
{
	int		i;
	int		count;
	t_point	*point;

	i = 0;
	count = 0;
	while (line[i])
	{
		if ((!i || line[i - 1] == ' ') && line[i] >= '0' && line[i] <= '9')
		{
			point = create_point(x, count, ft_atoi(&(line[i])));
			if (!point)
			{
				free_map(map);
				return (0);
			}
			add_point(map, point);
			count++;
		}
		i++;
	}
	return (1);
}

int	convert_map(t_point **map, int fd)
{
	int		x;
	char	*line;

	x = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (!create_line(map, line, x))
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}

t_point	*parse_map(char *file)
{
	t_point	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!convert_map(&map, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (map);
}
