#ifndef DEFINES_H
# define DEFINES_H

# define GAME_NAME	"cub3D"

# define SPEED 5
# define CAMERA_SPEED 5
# define REFRESH_RATE 120

# define SCREENW 1280
# define SCREENH 720

# define ERROR_ARGUMENTS_MSG "wrong number of arguments"
# define ERROR_EXTENSION_MSG "file extension should be .ber"
# define ERROR_EXIST_MSG "given file doesn't exist"
# define ERROR_CONTRUCTION_MSG "map not correctly contructed"

# define RGB_LIGHT_GREY create_trgb(0, 100, 100, 100)
# define RGB_BLACK create_trgb(0, 0, 0, 0)
# define RGB_WHITE create_trgb(0, 255, 255, 255)
# define RGB_RED create_trgb(0, 255, 0, 0)
# define RGB_GREEN create_trgb(0, 0, 255, 0)
# define RGB_BLUE create_trgb(0, 0, 0, 255)

//If u need to change the players speed, change SPEED and not the PLAYER_SPEED
# define PLAYER_SPEED (SPEED * 60 / REFRESH_RATE)

enum {
	ERROR_ARGUMENTS = 1,
	ERROR_EXTENSION = 2,
	ERROR_EXIST = 3,
	ERROR_CONTRUCTION = 4,
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

#endif