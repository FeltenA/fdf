/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:51 by afelten           #+#    #+#             */
/*   Updated: 2023/01/15 16:53:27 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	calculate_color(int z, t_data *data)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			diff_z;

	diff_z = z - data->min_z;
	r = round(((data->min_color >> 16) & 0xFF) + diff_z * data->color_step[0]);
	g = round(((data->min_color >> 8) & 0xFF) + diff_z * data->color_step[1]);
	b = round((data->min_color & 0xFF) + diff_z * data->color_step[2]);
	return (*(int *)(unsigned char [4]){b, g, r, 0});
}

/*void	rotate_iso(double *x, double *y, double *z)
{
	double	result_x;
	double	result_y;

	result_x = (1 / sqrt(6)) * (sqrt(3) * *x - sqrt(3) * *z);
	result_y = (1 / sqrt(6)) * (*x + 2 * *y + *z);
	*z = (1 / sqrt(6)) * (sqrt(2) * *x - sqrt(2) * *y + sqrt(2) * *z);
	*y = result_y;
	*x = result_x;
}*/

void	rotate_point(double *x, double *y, double *z, t_cam cam)
{
	double	result_x;
	double	result_y;

	result_x = cos(cam.ry) * (sin(cam.rz) * *y
			+ cos(cam.rz) * *x) - sin(cam.ry) * *z;
	result_y = sin(cam.rx) * (cos(cam.ry) * *z + sin(cam.ry)
			* (sin(cam.rz) * *y + cos(cam.rz) * *x)) + cos(cam.rx)
		* (cos(cam.rz) * *y - sin(cam.rz) * *x);
	*z = cos(cam.rx) * (cos(cam.ry) * *z + sin(cam.ry)
			* (sin(cam.rz) * *y + cos(cam.rz) * *x)) - sin(cam.rx)
		* (cos(cam.rz) * *y - sin(cam.rz) * *x);
	*x = result_x;
	*y = result_y;
}

t_pos	calculate_pos(t_point *point, t_data *data)
{
	t_pos	pos;
	double	x;
	double	y;
	double	z;

	x = (double) point->x + data->cam.x;
	y = (double) point->y + data->cam.y;
	z = (double) -point->z / data->intensity + data->cam.z;
	rotate_point(&x, &y, &z, data->cam);
	x = data->cam.fov / z * x;
	y = data->cam.fov / z * y;
	pos.x = round(x);
	pos.y = round(y);
	pos.color = calculate_color(point->z, data);
	return (pos);
}
