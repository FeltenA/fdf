
void rotate_point(double *x, double *y, double *z, t_cam cam)
{
    double  result_x;
    double  result_y;

    result_x = cos(cam.ry) * (sin(cam.rz) * *y + cos(cam.rz) * *x) - sin(cam.ry) * *z;
    result_y = sin(cam.rx) * (cos(cam.ry) * *z + sin(cam.ry) * (sin(cam.rz) * *y + cos(cam.rz) * *x)) + cos(cam.rx) * (cos(cam.rz) * *y - sin(cam.rx) * *x);
    *z = cos(cam.rx) * (cos(cam.ry) * *z + sin(cam.ry) * (sin(cam.rz) * *y + cos(cam.rz) * *x)) - sin(cam.rx) * (cos(cam.rz) * *y - sin(cam.rx) * *x);
    *x = result_x;
    *y = result_y;
}

t_pos calculate_pos(t_point *point, t_data *data)
{
    t_pos   result;
    double  x;
    double  y;
    double  z;

    x = (double) point->x - data->cam.x;
    y = (double) point->y - data->cam.y;
    z = (double) point->z - data->cam.z;
    result = rotate_point(&x, &y, &z, data->cam);
    x = data->cam.fov / z * x;
    y = data->cam.fov / z * y;
    result.x = round(x);
    result.y = round(y);
    result.color = calculate_color(point->z, data);
    return (result);
}