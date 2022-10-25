/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:53:31 by afelten           #+#    #+#             */
/*   Updated: 2022/10/24 14:48:29 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

t_pos	calculate_pos(t_point *point, t_data *data, t_pos *pos);
void	draw_line(t_pos p1, t_pos p2, t_img *img);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

t_point	*get_prev_point(t_point *start, t_point *point)
{
	while (start && start->y < point->y)
	{
		if (start->y == point->y - 1 && start->x == point->x)
			return (start);
		start = start->next;
	}
	return (0);
}
#include <stdio.h>
void	draw_map(t_data *data, t_img *img)
{
	t_point	*start;
	t_point	*tmp;
	t_pos	p1;
	t_pos	p2;

	img->img = mlx_new_image(data->mlx, data->width, data->heigth);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->line_len), &(img->endian));
	start = data->map;
	while (start)
	{
		printf("x: %d y: %d z: %d\n", start->x, start->y, start->z);
		if (start->next && start->y == start->next->y)
		{
			calculate_pos(start, data, &p1);
			calculate_pos(start->next, data, &p2);
			draw_line(p1, p2, img);
		}
		if (start->y > 0)
		{
			tmp = get_prev_point(data->map, start);
			if (tmp)
			{
				calculate_pos(start, data, &p1);
				calculate_pos(tmp, data, &p2);
				draw_line(p1, p2, img);
			}
		}
		start = start->next;
	}
}
