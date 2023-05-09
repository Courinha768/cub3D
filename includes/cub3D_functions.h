#ifndef CUB3D_FUNCTIONS_H
# define CUB3D_FUNCTIONS_H

void	start_game(char *mapPath, int draw_mm);
int		exit_game(t_data *data);

void	init_map(t_mapInfo *map, char **charMap);
char	**define_map(char *file_name);

void	start_playerinfo(t_data *data);

void	*create_squareimg(void	*mlx_ptr, int color, float size);

void	init_mm_mlxvars(t_mlx *mlxVars, int width, int height);

void	create_minimap(t_data *data);

int		print_error(int value);

int		same_position(t_position p1, t_position p2);
t_position	create_position(float x, float y);

void	put_img(t_data *data, void *img, int y, int x);
int		create_trgb(int t, int r, int g, int b);
void	place_player(t_data *data);

int		loop_hook(t_data *data);

int		free_map(char **map);

void	draw_minimap(t_data *data);

int		verify(int ac, char **av);
int		samesizelines(char **map);
int		not_token(char c);
int		exists_player(char **map);
int		correct_char(char **map);

void	move_front(t_data *data);
void	move_back(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

void	look_up(t_data *data);
void	look_down(t_data *data);
void	look_left(t_data *data);
void	look_right(t_data *data);

int	key_press_hook(int keycode, t_data *data);
int	key_release_hook(int keycode, t_data *data);

#endif
