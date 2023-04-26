#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct	s_mapInfo {
	char			**map;
	unsigned int	height;
	unsigned int	width;
}	t_mapInfo;

typedef struct	s_mlx {
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_position {
	float	x;
	float	y;
}	t_position;

typedef struct	s_playerInfo {
	t_position	pos;
	void		*img;
	float		dirX;
}	t_playerInfo;

typedef struct	s_all {
	t_mapInfo		map;
	t_mlx			mlx;
	t_playerInfo	player;
	void			*whiteSquareImg;
	void			*whiteSquareImg2;
}	t_all;

typedef struct	s_img_info {
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_img_info;

#endif