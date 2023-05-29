#include "../../includes/cub3D.h"

/*
Verifies if p1 and p1 are the same
*/
int	same_position(t_position p1, t_position p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return (1);
	return (0);
}
