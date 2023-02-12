/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:38:42 by afelten           #+#    #+#             */
/*   Updated: 2023/02/12 16:38:46 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_intersect_line(t_pos p1, t_pos p2, int p3[2], int p4[2])
{
	float	ua;
	float	ub;

	ua = ((p4[0] - p3[0]) * (p1.y - p3[1]) - (p4[1] - p3[1]) * (p1.x - p3[0]))
		/ (float)((p4[1] - p3[1]) * (p2.x - p1.x)
			- (p4[0] - p3[0]) * (p2.y - p1.y));
	ub = ((p2.x - p1.x) * (p1.y - p4[1]) - (p2.y - p1.y) * (p1.x - p3[0]))
		/ (float)((p4[1] - p3[1]) * (p2.x - p1.x)
			- (p4[0] - p3[0]) * (p2.y - p1.y));
	if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1)
		return (1);
	return (0);
}

int	check_intersect(t_pos p1, t_pos p2, t_data *data)
{
	int		rect[4];
	int		left;
	int		right;
	int		top;
	int		bottom;

	rect[0] = 0;
	rect[1] = 0;
	rect[2] = 0;
	rect[3] = data->heigth;
	left = check_intersect_line(p1, p2, &rect[0], &rect[2]);
	rect[0] = data->width;
	rect[2] = data->width;
	right = check_intersect_line(p1, p2, &rect[0], &rect[2]);
	rect[0] = 0;
	rect[3] = 0;
	top = check_intersect_line(p1, p2, &rect[0], &rect[2]);
	rect[1] = data->heigth;
	rect[3] = data->heigth;
	bottom = check_intersect_line(p1, p2, &rect[0], &rect[2]);
	return (left || right || top || bottom);
}
