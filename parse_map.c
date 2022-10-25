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
#include <unistd.h>

char	*get_next_line(int fd);
void	free_map(t_point **map);
t_point	*create_point(int line, int column, int value);
void	add_point(t_point **map, t_point *point);

int	ft_atoi_spe(const char *nptr, int *i)
{
	int	nbr;
	int	neg;

	nbr = 0;
	neg = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg = -1;
		(*i)++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + *nptr - 48;
		(*i)++;
		nptr++;
	}
	return (nbr * neg);
}

int	create_line(t_point **map, char *line, int y)
{
	int		i;
	int		count;
	t_point	*point;

	i = 0;
	count = 0;
	while (line[i])
	{
		if ((!i || line[i - 1] == ' ') && ((line[i] >= '0' && line[i] <= '9')
			|| line[i] == '-' || line[i] == '+'))
		{
			point = create_point(count, y, ft_atoi_spe(line + i, &i));
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
	int		y;
	char	*line;

	y = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (!create_line(map, line, y))
			return (0);
		line = get_next_line(fd);
		y++;
	}
	return (1);
}

t_point	*parse_map(char *file)
{
	t_point	*map;
	int		fd;

	map = 0;
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
