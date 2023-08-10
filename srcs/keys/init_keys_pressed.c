#include "../../includes/cub3D.h"

t_key_events	init_keys_pressed(void)
{
	t_key_events	temp_key_pressed;

	temp_key_pressed.general = 1;
	temp_key_pressed.a = false;
	temp_key_pressed.d = false;
	temp_key_pressed.left = false;
	temp_key_pressed.right = false;
	temp_key_pressed.s = false;
	temp_key_pressed.w = false;
	return (temp_key_pressed);
}