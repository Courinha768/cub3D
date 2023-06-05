#ifndef CUB3D_H
# define CUB3D_H

# include "cub3D_structs.h"
# include "cub3D_libraries.h"
# include "cub3D_functions.h"

# define MP_SSIZE 32
# define RGB_LIGHT_GREY create_trgb(0, 180, 180, 180)
# define RGB_BLACK create_trgb(0, 0, 0, 0)
# define RGB_RED create_trgb(0, 255, 0, 0)
# define GAME_NAME "cub3D"

# define PLAYER_SPEED 20
# define CAMERA_SPEED 0.1
# define PLAYER_PROPORTION 0.40625

enum {
	ESCAPE = 65307,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361,
	Z = 122,
	Q = 113,
	S = 115,
	D = 100,
	W = 119,
	A = 97,
};

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define ERROR_ARGUMENTS_MSG "wrong number of arguments"
# define ERROR_EXTENSION_MSG "file extension should be .ber"
# define ERROR_EXIST_MSG "given file doesn't exist"
# define ERROR_CONTRUCTION_MSG "map not correctly contructed"

enum {
	ERROR_ARGUMENTS = 1,
	ERROR_EXTENSION = 2,
	ERROR_EXIST = 3,
	ERROR_CONTRUCTION = 4,
};

#endif