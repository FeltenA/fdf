/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:48:28 by afelten           #+#    #+#             */
/*   Updated: 2023/02/12 19:04:52 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int		create_img(t_data *data);
void	free_map(t_point **map);
void	init_camera_iso(t_data *data);
void	init_camera_para(t_data *data);

int	close_win(t_data *data)
{
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx && data->win && data->img->img)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		free(data->img);
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map(&(data->map));
	exit(0);
}

static int	key_rotation(int keycode, t_data *data)
{
	if (keycode == 105)
		data->cam.rx += 0.087266463;
	if (keycode == 107)
		data->cam.rx -= 0.087266463;
	if (keycode == 108)
		data->cam.ry += 0.087266463;
	if (keycode == 106)
		data->cam.ry -= 0.087266463;
	if (keycode == 111)
		data->cam.rz += 0.087266463;
	if (keycode == 117)
		data->cam.rz -= 0.087266463;
	return (1);
}

static int	key_move(int keycode, t_data *data)
{
	if (keycode == 97)
		data->cam.x += 1;
	if (keycode == 100)
		data->cam.x -= 1;
	if (keycode == 119)
		data->cam.y += 1;
	if (keycode == 115)
		data->cam.y -= 1;
	if (keycode == 114)
		data->cam.z += 1;
	if (keycode == 102)
		data->cam.z -= 1;
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_win(data);
	if (keycode == 65453)
		data->cam.fov /= 2;
	if (keycode == 65451)
		data->cam.fov *= 2;
	if (keycode == 103)
		data->intensity *= 2;
	if (keycode == 116)
		data->intensity /= 2;
	if (keycode == 112 && data->proj)
		init_camera_iso(data);
	else if (keycode == 112)
		init_camera_para(data);
	key_move(keycode, data);
	key_rotation(keycode, data);
	create_img(data);
	return (1);
}
