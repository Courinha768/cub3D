#ifndef CUB3D_FUNCTIONS_H
# define CUB3D_FUNCTIONS_H


int		print_error(int value);

int		create_trgb(int t, int r, int g, int b);
void	put_img(t_all *all, void *img, int y, int x);
void	*create_colorImage(t_all *all, int color);
void	*create_colorImage2(t_all *all, int color);

void	draw_miniMap(t_all *all);

void	define_playerInfo(t_all *all);

int		loopHook(t_all *all);

void	place_player(t_all *all);
int		same_position(t_position p1, t_position p2);

/*Map functions*/
int		free_map(char **map);
char	**define_map(char *file_name);

/*Verify functions*/
int		verify(int ac, char **av);

int		sameSizeLines(char **map);
int		not_token(char c);
int		exists_player(char **map);
int		correct_char(char **map);

/*Movement Functions*/
void	move_front(t_all *all);
void	move_back(t_all *all);
void	move_left(t_all *all);
void	move_right(t_all *all);


#endif
