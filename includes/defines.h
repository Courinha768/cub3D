/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:38:29 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:44:10 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define GAME_NAME	"cub3D"

# define PLAYER_SPEED 4
# define CAMERA_SPEED 5
# define REFRESH_RATE 120

# define SCREENW 1280
# define SCREENH 720

# define TEXW 64
# define TEXH 64

# define FILE_DOESNT_EXIST "Given file doesn't exist"
# define MAP_NOT_CONSTRUCTED_CORRECTLY "Map not constructed correctly"
# define NBR_ARGS "Incorrect number of arguments"
# define INVALID_COLORS "Given color for floor/ceiling doesn't exist"
# define INVALID_FILE_EXTENSION "Invalid file extension"

# define MINIMAP_SCALE 16

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
	M = 109,
};

#endif