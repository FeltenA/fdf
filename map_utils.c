/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:24:58 by afelten           #+#    #+#             */
/*   Updated: 2022/09/21 14:25:34 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_point	*create_point(int line, int column, int value)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (0);
	point->x = (double) column;
	point->y = (double) line;
	point->z = (double) value;
	point->next = 0;
	return (point);
}