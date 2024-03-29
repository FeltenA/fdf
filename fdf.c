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

int		key_hook(int keycode, t_data *data);
int		close_win(t_data *data);
t_point	*parse_map(char *file);
void	init_data(t_data *data);
void	draw_map(t_data *data, t_img *img);
void	free_map(t_point **map);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	putstr_err(char *str);

int	create_img(t_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (0);
	draw_map(data, img);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		free(data->img);
	}
	data->img = img;
	return (1);
}

int	check_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (!ft_strcmp(&(name[len - 4]), ".fdf"))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || check_name(argv[1]))
		putstr_err("Argument is not valid\n");
	data.map = parse_map(argv[1]);
	if (!data.map)
		putstr_err("Error in parsing\n");
	data.width = 900;
	data.heigth = 800;
	init_data(&data);
	create_img(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
	return (0);
}
