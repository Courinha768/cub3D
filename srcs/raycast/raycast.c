#include "../../includes/cub3D.h"

void    calc_step_and_side(t_data *data)
{
    if (data->ray.ray_dir.x < 0)
    {
        data->ray.step.x = -1;
        data->ray.side_dist.x = (data->player.position.x - data->player.map_posX) * data->ray.delta.x;
    }
    else
    {
        data->ray.step.x = 1;
        data->ray.side_dist.x = (data->player.map_posX + 1 - data->player.position.x) * data->ray.delta.x;
    }
    if (data->ray.ray_dir.y < 0)
    {
        data->ray.step.y = -1;
        data->ray.side_dist.y = (data->player.position.y - data->player.map_posY) * data->ray.delta.y;
    }
    else
    {
        data->ray.step.y = 1;
        data->ray.side_dist.y = (data->player.map_posY + 1 - data->player.position.y) * data->ray.delta.y;
    }
}

void    find_wall(t_data *data)
{
    int hit;

    hit = 0;
    while (hit == 0)
    {
        if (data->ray.side_dist.x < data->ray.side_dist.y)
        {
            data->ray.side_dist.x += data->ray.delta.x;
            data->player.map_posX += data->ray.step.x;
            data->ray.wall_side = 0;
        }
        else
        {
            data->ray.side_dist.y += data->ray.delta.y;
            data->player.map_posY += data->ray.step.y;
            data->ray.wall_side = 1;
        }
        if (data->map.map[data->player.map_posY][data->player.map_posX] == '1')
            hit = 1;
    }
}

void    calc_wall_height(t_data *data)
{
    int		line_h;
    float	prep_wall_dist;

    line_h = 0;
    prep_wall_dist = 0;
    if (data->ray.wall_side == 0)
        prep_wall_dist = fabs((data->player.map_posX - data->player.position.x + (1 - data->ray.step.x) / 2) / data->ray.ray_dir.x);
    else
        prep_wall_dist = fabs((data->player.map_posY - data->player.position.y + (1 - data->ray.step.y) / 2) / data->ray.ray_dir.y);
    line_h = (int)(SCREENH / prep_wall_dist);
    data->draw.start = -line_h / 2 + SCREENH / 2;
    if (data->draw.start < 0)
        data->draw.start = 0;
    data->draw.end = line_h / 2 + SCREENH / 2;
    if (data->draw.end >= SCREENH)
        data->draw.end = SCREENH - 1;
}
