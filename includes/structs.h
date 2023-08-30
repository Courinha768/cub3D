#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_mlx {
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct	s_position {
	float	x;
	float	y;
}	t_position;

typedef struct s_step {
	int x;
	int	y;
}	t_step;

typedef struct	s_hitbox {
	t_position	tl_corner;
	t_position	tr_corner;
	t_position	bl_corner;
	t_position	br_corner;
}	t_hitbox;

typedef struct	s_player_info {
	t_position	position;
	t_hitbox	hitbox;
	void		*img;
	float		dirX;
	t_position	view_dir;
	t_position	plane;
	int			map_posX;
	int			map_posY;
}	t_player_info;

typedef struct	s_map_info {
	char			**map;
	unsigned int	height;
	unsigned int	width;
	char			*NO_texture_path;
	char			*SO_texture_path;
	char			*WE_texture_path;
	char			*EA_texture_path;
	int				floor_color;
	int				ceiling_color;
}	t_map_info;

typedef struct	s_map_info_bool {
	bool	NO_texture_path;
	bool	SO_texture_path;
	bool	WE_texture_path;
	bool	EA_texture_path;
	bool	floor_color;
	bool	ceiling_color;
}	t_map_info_bool;

typedef struct	s_key_events {
	int		general;
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
}	t_key_events;


typedef struct s_ray {
	t_position	ray_dir;
	t_step		step;
	t_position	delta;
	t_position	side_dist;
	int			wall_side;
}	t_ray;

typedef struct s_draw{
	int	start;
	int	end;
}	t_draw;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}	t_img;

typedef struct	s_data {
	t_map_info		map;
	t_player_info	player;
	t_mlx			mlx;
	t_key_events	keys_pressed;
	t_ray			ray;
	t_img			img;
	t_draw			draw;
} t_data;

#endif