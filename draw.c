/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:53:31 by afelten           #+#    #+#             */
/*   Updated: 2022/09/25 17:53:35 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_point calculate_pos(t_point *point, t_cam cam)
{
    t_point result;

    result.x = (point->x - cam.x) + cos(cam.rx) * (point->z - cam.z)
                - cos(ry) * (point->y - cam.y);
    result.y = ()
}

void    draw_map(t_data *data)
{
    t_point *start;

    start = data->map;
    while (start->next)
    {

    }
}