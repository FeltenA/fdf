/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:37:07 by afelten           #+#    #+#             */
/*   Updated: 2022/10/24 14:37:11 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void    plot_line_low(t_pos p1, t_pos p2, t_img *img)
{
    int dx;
    int dy;
    int i;
    int d;

    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    i = 1;
    if (dy < 0)
    {
        i = -1;
        dy = -dy;
    }
    d = 2 * dy - dx;
    while (p1.x <= p2.x)
    {
        my_mlx_pixel_put(img, p1.x, p1.y, p1.color);
        if (d > 0)
        {
            p1.y += i;
            d += 2 * (dy - dx);
        }
        else
            d += 2 * dy;
        p1.x += 1;
    }
}

void    plot_line_high(t_pos p1, t_pos p2, t_img *img)
{
    int dx;
    int dy;
    int i;
    int d;

    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    i = 0;
    if (dx < 0)
    {
        i = -1;
        dx = -dx;
    }
    d = 2 * dx - dy;
    while (p1.y <= p2.y)
    {
        my_mlx_pixel_put(img, p1.x, p1.y, p1.color);
        if (d > 0)
        {
            p1.x += i;
            d += 2 * (dx - dy);
        }
        else
            d += 2 * dx;
        p1.y += 1;
    }
}

void    draw_line(t_pos p1, t_pos p2, t_img *img)
{
    if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
    {
        if (p1.x > p2.x)
            plot_line_low(p2, p1, img);
        else
            plot_line_low(p1, p2, img);
    }
    else
    {
        if (p1.y > p2.y)
            plot_line_high(p2, p1, img);
        else
            plot_line_high(p1, p2, img);
    }
}
