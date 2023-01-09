
#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int	    create_img(t_data *data);
void	free_map(t_point **map);

void	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_display(data->mlx);
    free(data->img);
	free(data->mlx);
	free_map(&(data->map));
	exit(0);
}

static int  key_rotation(int keycode, t_data *data)
{
    if (keycode == 105)
        data->cam.rx += 0.087266463;
    if (keycode == 107)
        data->cam.rx -= 0.087266463;
    if (keycode == 106)
        data->cam.ry += 0.087266463;
    if (keycode == 108)
        data->cam.ry -= 0.087266463;
    if (keycode == 117)
        data->cam.rz += 0.087266463;
    if (keycode == 111)
        data->cam.rz -= 0.087266463;
    return (1);
}

static int  key_move(int keycode, t_data *data)
{
    if (keycode == 100)
        data->cam.x += 1;
    if (keycode == 113)
        data->cam.x -= 1;
    if (keycode == 115)
        data->cam.y += 1;
    if (keycode == 122)
        data->cam.y -= 1;
    if (keycode == 102)
        data->cam.z += 1;
    if (keycode == 114)
        data->cam.z -= 1;
    return (1);
}
#include <stdio.h>
int key_hook(int keycode, t_data *data)
{
    if (keycode == 65307)
        close_win(data);
    if (keycode == 65453)
        data->cam.fov /= 2;
    if (keycode == 65451)
        data->cam.fov *= 2;
    if (keycode == 103)
        data->intensity *= 2;
    if (keycode == 116)
        data->intensity /= 2;
    key_move(keycode, data);
    key_rotation(keycode, data);
    create_img(data);
    printf("cam: x: %f, y: %f, z: %f\nrx: %f, ry: %f, rz: %f\nfov: %d intensity: %f\n", data->cam.x, data->cam.y, data->cam.z, data->cam.rx, data->cam.ry, data->cam.rz, data->cam.fov, data->intensity);
    printf("%d\n", keycode);
    return (1);
}