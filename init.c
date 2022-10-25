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

void	init_camera(t_cam *cam)
{
	cam->x = 0;
	cam->y = 0;
	cam->z = 0;
	cam->rx = 0;
	cam->ry = 0;
	cam->rz = 0;
	cam->fov = 1000;
}

void	init_color(t_data *data)
{
	int	diff_z;
	int	diff_color[3];

	diff_z = data->max_z - data->min_z;
	diff_color[0] = ((data->max_color >> 16) & 0xFF)
		- ((data->min_color >> 16) & 0xFF);
	diff_color[1] = ((data->max_color >> 8) & 0xFF)
		- ((data->min_color >> 8) & 0xFF);
	diff_color[2] = (data->max_color & 0xFF) - (data->min_color & 0xFF);
	data->color_step[0] = diff_color[0] / diff_z;
	data->color_step[1] = diff_color[1] / diff_z;
	data->color_step[2] = diff_color[2] / diff_z;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->heigth, "fdf");
	data->img = 0;
	data->max_z = get_max_z(data->map);
	data->min_z = get_min_z(data->map);
	data->max_color = 0x00FF0000;
	data->min_color = 0x000000FF;
	init_camera(&data->cam);
	init_color(data);
}
