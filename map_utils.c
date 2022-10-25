/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:24:58 by afelten           #+#    #+#             */
/*   Updated: 2022/10/24 14:49:24 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	get_max_z(t_point *map)
{
	int	max_z;

	max_z = map->z;
	while (map)
	{
		if (map->z > max_z)
			max_z = map->z;
		map = map->next;
	}
	return (max_z);
}

int	get_min_z(t_point *map)
{
	int	min_z;

	min_z = map->z;
	while (map)
	{
		if (map->z < min_z)
			min_z = map->z;
		map = map->next;
	}
	return (min_z);
}

void	free_map(t_point **map)
{
	t_point	*save;

	while ((*map))
	{
		save = *map;
		*map = (*map)->next;
		free(save);
	}
}

void	add_point(t_point **map, t_point *point)
{
	t_point	*ppoint;

	if (!(*map))
		*map = point;
	else
	{
		ppoint = *map;
		while (ppoint->next)
			ppoint = ppoint->next;
		ppoint->next = point;
	}
}

t_point	*create_point(int column, int line, int value)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (0);
	point->x = column;
	point->y = line;
	point->z = value;
	point->next = 0;
	return (point);
}
