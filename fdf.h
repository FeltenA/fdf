/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:41:12 by afelten           #+#    #+#             */
/*   Updated: 2022/09/18 18:41:40 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	struct s_point	next;
}	t_point;

typedef struct s_cam
{
	double	x;
	double	y;
	double	z;
	double	rx;
	double	ry;
	double	rz;
}	t_cam;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_cam	cam;
	t_point	*map;
}	t_data;

#endif
