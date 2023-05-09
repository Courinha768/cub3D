#include "../../includes/cub3D.h"

int	same_position(t_position p1, t_position p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return (1);
	return (0);
}

t_position	create_position(float x, float y)
{
	t_position	temp_position;

	temp_position.x = x;
	temp_position.y = y;

	return (temp_position);
}