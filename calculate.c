/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:51 by afelten           #+#    #+#             */
/*   Updated: 2022/10/24 14:45:51 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_color(int z, t_data *data)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			diff_z;

	diff_z = z - data->min_z;
	r = round(diff_z * data->color_step[0]);
	g = round(diff_z * data->color_step[1]);
	b = round(diff_z * data->color_step[2]);
	return (*(int *)(unsigned char [4]){b, g, r, 0});
}

void	rotate_point(double *x, double *y, double *z, t_cam cam)
{
	double	result_x;
	double	result_y;

	result_x = cos(cam.ry) * (sin(cam.rz) * *y
			+ cos(cam.rz) * *x) - sin(cam.ry) * *z;
	result_y = sin(cam.rx) * (cos(cam.ry) * *z + sin(cam.ry)
			* (sin(cam.rz) * *y + cos(cam.rz) * *x)) + cos(cam.rx)
		* (cos(cam.rz) * *y - sin(cam.rx) * *x);
	*z = cos(cam.rx) * (cos(cam.ry) * *z + sin(cam.ry)
			* (sin(cam.rz) * *y + cos(cam.rz) * *x)) - sin(cam.rx)
		* (cos(cam.rz) * *y - sin(cam.rx) * *x);
	*x = result_x;
	*y = result_y;
}

t_pos	calculate_pos(t_point *point, t_data *data)
{
	t_pos	result;
	double	x;
	double	y;
	double	z;

	x = (double) point->x - data->cam.x;
	y = (double) point->y - data->cam.y;
	z = (double) point->z - data->cam.z;
	rotate_point(&x, &y, &z, data->cam);
	x = data->cam.fov / z * x;
	y = data->cam.fov / z * y;
	result.x = round(x);
	result.y = round(y);
	result.color = calculate_color(point->z, data);
	return (result);
}
