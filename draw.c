/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:53:31 by afelten           #+#    #+#             */
/*   Updated: 2023/01/15 16:53:56 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

t_pos	calculate_pos(t_point *point, t_data *data);
void	draw_line(t_pos p1, t_pos p2, t_img *img, t_data *data);

void	my_mlx_pixel_put(t_img *img, t_pos pos, t_data *data)
{
	char	*dst;

	if (pos.x <= -data->width / 2 || pos.x >= data->width / 2
		|| pos.y <= -data->heigth / 2 || pos.y >= data->heigth / 2)
		return ;
	dst = img->addr + ((pos.y + data->heigth / 2) * img->line_len
			+ (pos.x + data->width / 2) * (img->bpp / 8));
	*(unsigned int *) dst = pos.color;
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

void	draw_map(t_data *data, t_img *img)
{
	t_point	*start;
	t_point	*tmp;

	img->img = mlx_new_image(data->mlx, data->width, data->heigth);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->line_len), &(img->endian));
	start = data->map;
	while (start)
	{
		if (start->next && start->y == start->next->y)
			draw_line(calculate_pos(start, data),
				calculate_pos(start->next, data), img, data);
		if (start->y > 0)
		{
			tmp = get_prev_point(data->map, start);
			if (tmp)
				draw_line(calculate_pos(start, data),
					calculate_pos(tmp, data), img, data);
		}
		start = start->next;
	}
}
