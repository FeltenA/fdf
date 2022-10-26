
#include "fdf.h"
#include <mlx.h>

int	create_img(t_data *data);

void	close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(&(data->map));
	exit(0);
}

static int  key_rotation(int keycode, t_data *data)
{
    if (keycode == 0)
        data->cam.rx += 0.087266463;
    if (keycode == 0)
        data->cam.rx -= 0.087266463;
    if (keycode == 0)
        data->cam.ry += 0.087266463;
    if (keycode == 0)
        data->cam.ry -= 0.087266463;
    if (keycode == 0)
        data->cam.rz += 0.087266463;
    if (keycode == 0)
        data->cam.rz -= 0.087266463;
}

static int  key_move(int keycode, t_data *data)
{
    if (keycode == 0)
        data->cam.x += 1;
    if (keycode == 0)
        data->cam.x -= 1;
    if (keycode == 0)
        data->cam.y += 1;
    if (keycode == 0)
        data->cam.y -= 1;
    if (keycode == 0)
        data->cam.z += 1;
    if (keycode == 0)
        data->cam.x -= 1;
}

int key_hook(int keycode, t_data *data)
{
    if (keycode == 65305)
        close(data);
    if (keycode == 0)
        data->cam.fov += 10;
    if (keycode == 0)
        data->cam.fov -= 10;
}