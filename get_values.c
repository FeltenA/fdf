/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:56:21 by afelten           #+#    #+#             */
/*   Updated: 2023/02/12 16:56:25 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	get_max_x(t_point *map)
{
	int	max_x;

	max_x = map->x;
	while (map)
	{
		if (map->x > max_x)
			max_x = map->x;
		map = map->next;
	}
	return (max_x);
}

int	get_max_y(t_point *map)
{
	int	max_y;

	max_y = map->y;
	while (map)
	{
		if (map->y > max_y)
			max_y = map->y;
		map = map->next;
	}
	return (max_y);
}
