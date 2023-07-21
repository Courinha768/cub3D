#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "./structs.h"

void			cub3D(char **map);

int				free_map(char **map);
char			**define_map(char *file_path);

bool			print_error(int error_nbr);
bool			verify_map_path(int ac, char **av);
bool			verify_map_construction(char **map);


t_map_info		define_map_info(char **map);
t_player_info	define_player_info(t_map_info map);
t_hitbox		define_player_hitbox(t_position	player_position);
t_key_events	init_keys_pressed(void);
t_mlx			define_minimap_mlx_vars(t_map_info	map_info);

t_position		find_ray_colision(t_position starting_position, float starting_angle, float angle, char** map);

int				close_game(t_data *data);

int				key_pressed_hook(int keycode, t_data *data);
int				key_release_hook(int keycode, t_data *data);

void			*create_squareimg(void	*mlx_ptr, int color, float size);
int				create_trgb(int t, int r, int g, int b);
void			draw_line(t_data *data, t_position starting_position, t_position end_position);
void			put_img(t_data *data, void *img, int y, int x);

void			update_position(t_data *data);

void			move_front(t_data *data);
void			move_right(t_data *data);
void			move_back(t_data *data);
void			move_left(t_data *data);

void			look_right(t_data *data);
void			look_left(t_data *data);

int				loop_hook(t_data *data);

bool			check_colision(t_hitbox hitbox, t_map_info map_info);


//minimap fucntions

void			place_player(t_data *data, t_position position, int img);
void			paint_path(t_data *data);
void			draw_minimap(t_data *data);
#endif