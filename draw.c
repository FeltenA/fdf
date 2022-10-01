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

t_point calculate_pos(t_point *point, t_data *data);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_point *get_prev_point(t_point *start, t_point *point)
{
    while (start && start->y < point->y)
    {
        if (start->y == point->y - 1 && start->x == point->x)
            return (start);
        start = start->next;
    }
    return (0);
}

void    draw_map(t_data *data)
{
    t_point *start;
    t_point *tmp;

    start = data->map;
    while (start->next)
    {
        if (start->y == start->next->y)
            draw_line(start, start->next);
        if (start->y > 0)
        {
            tmp = get_prev_point(data->map, start);
            if (tmp)
                draw_line(start, tmp);
        }
        start = start->next;
    }
}