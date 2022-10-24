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

typedef struct s_pos
{
	int	x;
	int	y;
	int		color;
}	t_pos;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
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
	int		fov;
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
	t_img	*img;
	t_cam	cam;
	t_point	*map;
	t_cam	t_cam;
	int		width;
	int		heigth;
	int		max_z;
	int		min_z;
	int		max_color;
	int		min_color;
	double	color_step[3];
	int		space;
}	t_data;

#endif
