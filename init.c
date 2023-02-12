/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:34:36 by afelten           #+#    #+#             */
/*   Updated: 2022/10/24 14:54:17 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

int	get_max_z(t_point *map);
int	get_min_z(t_point *map);

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
void	init_camera_para(t_data *data)
{
	int	max_y;
	int	max;

	max = get_max_x(data->map);
	max_y = get_max_y(data->map);
	if (max_y > max)
		max = max_y;
	data->cam.x = -max - (data->max_z - data->min_z) / 3;
	data->cam.y = -max - (data->max_z - data->min_z) / 1.5;
	data->cam.z = 100 + 1.5 * max + (data->max_z - data->min_z);
	data->cam.rx = 0;
	data->cam.ry = 0;
	data->cam.rz = 0;
	data->cam.fov = 4000;
}

void	init_camera_iso(t_data *data)
{
	int	max_y;
	int	max;

	max = get_max_x(data->map);
	max_y = get_max_y(data->map);
	if (max_y > max)
		max = max_y;
	data->cam.x = -max - (data->max_z - data->min_z) / 3;
	data->cam.y = -2 * max - (data->max_z - data->min_z) / 1.5;
	data->cam.z = 1.5 * max + (data->max_z - data->min_z);
	data->cam.rx = 0.7853981633973;
	data->cam.ry = 0;
	data->cam.rz = -0.3490658504;
	data->cam.fov = 1000;
}

void	init_color(t_data *data)
{
	int	diff_z;
	int	diff_color[3];

	diff_z = data->max_z - data->min_z;
	if (diff_z == 0)
		diff_z = 1;
	diff_color[0] = ((data->max_color >> 16) & 0xFF)
		- ((data->min_color >> 16) & 0xFF);
	diff_color[1] = ((data->max_color >> 8) & 0xFF)
		- ((data->min_color >> 8) & 0xFF);
	diff_color[2] = (data->max_color & 0xFF) - (data->min_color & 0xFF);
	data->color_step[0] = (double) diff_color[0] / diff_z;
	data->color_step[1] = (double) diff_color[1] / diff_z;
	data->color_step[2] = (double) diff_color[2] / diff_z;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->heigth, "fdf");
	data->img = 0;
	data->max_z = get_max_z(data->map);
	data->min_z = get_min_z(data->map);
	data->intensity = 1.0;
	data->max_color = 0x00FF0000;
	data->min_color = 0x000000FF;
	init_camera_iso(data);
	init_color(data);
}
