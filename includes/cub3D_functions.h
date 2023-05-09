#ifndef CUB3D_FUNCTIONS_H
# define CUB3D_FUNCTIONS_H

void	start_game(char *mapPath, int draw_mm);
int		exit_game(t_all *all);

void	init_map(t_mapInfo *map, char **charMap);
char	**define_map(char *file_name);

void	start_playerinfo(t_all *all);

void	*create_squareimg(void	*mlx_ptr, int color, float size);

void	init_mm_mlxvars(t_mlx *mlxVars, int width, int height);
/*=====================================================*/


int		print_error(int value);



int		same_position(t_position p1, t_position p2);

/*	Image Utils*/

void	put_img(t_all *all, void *img, int y, int x);
int		create_trgb(int t, int r, int g, int b);
void	place_player(t_all *all);


/*	Hooks	*/

int		loop_hook(t_all *all);
int		key_hook(int keycode, t_all *all);

/*	Initiate Variables	*/




/*	Map functions	*/

int		free_map(char **map);

void	draw_minimap(t_all *all);

/*	Verify functions	*/

int		verify(int ac, char **av);
int		samesizelines(char **map);
int		not_token(char c);
int		exists_player(char **map);
int		correct_char(char **map);

/*	Movement Functions	*/

void	move_front(t_all *all);
void	move_back(t_all *all);
void	move_left(t_all *all);
void	move_right(t_all *all);

/*	Camera Functions	*/

void	look_up(t_all *all);
void	look_down(t_all *all);
void	look_left(t_all *all);
void	look_right(t_all *all);

#endif
