#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_img_info {
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_img_info;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct	s_mlx {
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct	s_position {
	float	x;
	float	y;
}	t_position;

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
}	t_player_info;

typedef struct	s_map_info {
	char			**map;
	unsigned int	height;
	unsigned int	width;
}	t_map_info;

typedef struct	s_key_events {
	int		general;
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
}	t_key_events;

typedef struct s_minimap_imgs {
	void	*map_square;
	void	*player_square;
}	t_minimap_imgs;

typedef struct	s_data {
	t_map_info		map;
	t_player_info	player;
	t_mlx			mlx;
	t_key_events	keys_pressed;
	t_minimap_imgs	minimap_imgs;
} t_data;

#endif