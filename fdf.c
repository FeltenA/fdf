/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:28:24 by afelten           #+#    #+#             */
/*   Updated: 2022/09/18 18:43:12 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

t_point	*parse_map(char *file);
void	init_data(t_data *data);
void	draw_map(t_data *data, t_img *img);
void	free_map(t_point **map);

int	close(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img->img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(&(data->map));
		exit(0);
	}
	return (0);
}

int	create_img(t_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (0);
	draw_map(data, img);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img->img);
	data->img = img;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (1);
	data.map = parse_map(argv[1]);
	if (!data.map)
		return (1);
	data.width = 900;
	data.heigth = 800;
	init_data(&data);
	create_img(&data);
	mlx_key_hook(data.win, close, &data);
	mlx_loop(data.mlx);
	return (0);
}
