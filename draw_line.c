/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:37:07 by afelten           #+#    #+#             */
/*   Updated: 2023/01/15 17:01:47 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *img, t_pos pos, t_data *data);

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_pos	get_color(t_pos p1, t_pos p2, int x, int y)
{
	t_pos			new;
	unsigned char	color[4];
	int				diff_color[3];
	double			dist;

	diff_color[0] = ((p2.color >> 16) & 0xFF)
		- ((p1.color >> 16) & 0xFF);
	diff_color[1] = ((p2.color >> 8) & 0xFF)
		- ((p1.color >> 8) & 0xFF);
	diff_color[2] = (p2.color & 0xFF) - (p1.color & 0xFF);
	dist = sqrt((x - p1.x) * (x - p1.x) + (y - p1.y) * (y - p1.y))
		/ sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	color[3] = 0;
	color[2] = ((p1.color >> 16) & 0xFF) + dist * diff_color[0];
	color[1] = ((p1.color >> 8) & 0xFF) + dist * diff_color[1];
	color[0] = (p1.color & 0xFF) + dist * diff_color[2];
	new.color = *(int *)color;
	new.x = x;
	new.y = y;
	return (new);
}

void	plot_line(t_pos p1, t_pos p2, t_draw_line values, t_data *data)
{
	while (1)
	{
		my_mlx_pixel_put(values.img,
			get_color(p1, p2, values.x, values.y), data);
		if (values.x == p2.x && values.y == p2.y)
			break ;
		values.e2 = 2 * values.error;
		if (values.e2 >= values.dy)
		{
			if (values.x == p2.x)
				break ;
			values.error = values.error + values.dy;
			values.x = values.x + values.sx;
		}
		if (values.e2 <= values.dx)
		{
			if (values.y == p2.y)
				break ;
			values.error = values.error + values.dx;
			values.y = values.y + values.sy;
		}
	}
}

void	draw_line(t_pos p1, t_pos p2, t_img *img, t_data *data)
{
	t_draw_line	values;

	values.img = img;
	values.x = p1.x;
	values.y = p1.y;
	values.dx = ft_abs(p2.x - p1.x);
	if (p1.x < p2.x)
		values.sx = 1;
	else
		values.sx = -1;
	if (p1.y < p2.y)
		values.sy = 1;
	else
		values.sy = -1;
	values.dy = -ft_abs(p2.y - p1.y);
	values.error = values.dx + values.dy;
	plot_line(p1, p2, values, data);
}
