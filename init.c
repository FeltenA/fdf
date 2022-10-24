/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:34:36 by afelten           #+#    #+#             */
/*   Updated: 2022/10/24 14:54:17 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera(t_cam *cam)
{
	cam->x = 0;
	cam->y = 0;
	cam->z = 0;
	cam->rx = 0;
	cam->ry = 0;
	cam->rz = 0;
}
