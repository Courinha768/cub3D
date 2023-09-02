/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   functions.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aappleto <aappleto@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/02 17:38:32 by aappleto		  #+#	#+#			 */
/*   Updated: 2023/09/02 17:45:18 by aappleto		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "./structs.h"

void			cub3d(t_map_info map_info);

int				free_map(char **map);
char			**define_map(char *file_path);

int				close_game(t_data *data);

int				create_trgb(int t, int r, int g, int b);
void			put_img(t_data *data, void *img, int y, int x);

int				loop_hook(t_data *data);
t_key_events	init_keys_pressed(void);
int				key_pressed_hook(int keycode, t_data *data);
int				key_release_hook(int keycode, t_data *data);

bool			parse_line_util(char *line, t_map_info *map_info,
					t_map_info_bool *info, bool *not_xpm);
void			parsing_utils(char *file_path, t_map_info *map_info);

// t_map_info		define_map_info(char **map);
t_player_info	define_player_info(t_map_info map);
t_hitbox		define_player_hitbox(t_position	player_position);
void			update_position(t_data *data);
bool			check_colision(t_hitbox hitbox, t_map_info map_info);
t_position		find_new_position(t_position wanted_position,
					t_position old_position, t_map_info map);

//Movement Functions

void			move_front(t_data *data);
void			move_right(t_data *data);
void			move_back(t_data *data);
void			move_left(t_data *data);

void			look_right(t_data *data);
void			look_left(t_data *data);

// minimap

void			render_minimap(t_data *data);
void			draw_square(t_data *data, int x, int y, int color);
void			draw_player(t_data *data, float x, float y, int color);

//3D functions

void			draw_wall(t_data *data, int pixel_w, int pixel_h);
void			draw_scene(t_data *data, int pixel_w);
void			get_tex_data(t_data *data);
void			calc_wall_height(t_data *data);
void			find_wall(t_data *data);
void			calc_step_and_side(t_data *data);
void			render_3d_scene(t_data *data);
void			create_3dwin(t_data *data);

void			my_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_color(t_img *img, int x, int y);

void			load_textures(t_data *data, t_img *wall, char *path);

int				charnbr(char *line, char c);

t_map_info		parsing(char *file_path);
t_map_info_bool	init_info_bool(void);
bool			is_complete(t_map_info_bool info);
bool			verify_file_existance(char *file_path);
void			set_map_size(t_map_info *map_info);
void			parse_vars(char *line, char **texture_path, bool *bool_var,
					bool *not_xpm);
void			c3d_error(char *error, int fd, char *line,
					t_map_info *map_info);
void			texture_files_exist(t_map_info *map_info);
t_map_info_bool	init_info_bool(void);

int				check_map_construction1(t_map_info map_info);
int				check_map_construction2(t_map_info map_info);
int				check_map_construction3(t_map_info map_info);
int				check_map_construction4(t_map_info map_info);

char			*get_next_valid_line(int fd);

#endif