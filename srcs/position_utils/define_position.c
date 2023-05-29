#include "../includes/cub3D.h"

/*
Creates and returns a variable of the type t_position, with x and y as the x and y of that variable
*/
t_position	define_position(float x, float y)
{
	t_position	temp_position;

	temp_position.x = x;
	temp_position.y = y;

	return (temp_position);
}