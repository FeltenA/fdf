
t_pos rotate_point(t_pos point, double *z, t_cam cam)
{
    t_pos result;

    result.x = cos(cam.ry) * (sin(cam.rz) * point.y + cos(cam.rz) * point.x) - sin(cam.ry) * *z;
    result.y = sin(cam.rx) * (cos(cam.ry) * *z + sin(cam.ry) * (sin(cam.rz) * point.y + cos(cam.rz) * point.x)) + cos(cam.rx) * (cos(cam.rz) * point.y - sin(cam.rx) * point.x);
    *z = cos(cam.rx) * (cos(cam.ry) * *z + sin(cam.ry) * (sin(cam.rz) * point.y + cos(cam.rz) * point.x)) - sin(cam.rx) * (cos(cam.rz) * point.y - sin(cam.rx) * point.x);
    return (result);
}

t_pos calculate_pos(t_point *point, t_data *data)
{
    t_pos   result;
    double  z;

    result.x = (double) point->x - data->cam.x;
    result.y = (double) point->y - data->cam.y;
    z = (double) point->z - data->cam.z;
    result = rotate_point(result, &z, data->cam);
    result.x = data->cam.fov / z * result.x;
    result.y = data->cam.fov / z * result.y;
    return (result);
}