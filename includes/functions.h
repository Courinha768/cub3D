#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "./structs.h"

void			cub3D(char **map);

int				free_map(char **map);
char			**define_map(char *file_path);

bool			print_error(int error_nbr);
bool			verify_map_path(int ac, char **av);
bool			verify_map_construction(char **map);


int				close_game(t_data *data);

int				create_trgb(int t, int r, int g, int b);
void			put_img(t_data *data, void *img, int y, int x);

int				loop_hook(t_data *data);
t_key_events	init_keys_pressed(void);
int				key_pressed_hook(int keycode, t_data *data);
int				key_release_hook(int keycode, t_data *data);

t_map_info		define_map_info(char **map);
t_player_info	define_player_info(t_map_info map);
t_hitbox		define_player_hitbox(t_position	player_position);
void			update_position(t_data *data);
bool			check_colision(t_hitbox hitbox, t_map_info map_info);
t_position		find_new_position(t_position wanted_position, t_position old_position, t_map_info map);

//Movement Functions

void			move_front(t_data *data);
void			move_right(t_data *data);
void			move_back(t_data *data);
void			move_left(t_data *data);

void			look_right(t_data *data);
void			look_left(t_data *data);

//3D functions

void    draw_scene(t_data *data, int pixel_w);
void    calc_wall_height(t_data *data);
void    find_wall(t_data *data);
void    calc_step_and_side(t_data *data);
void	render_3d_scene(t_data *data);
void    create_3dwin(t_data *data);

void	my_pixel_put(t_data *data, int x, int y, int color);

#endif