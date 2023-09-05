NAME		=	cub3D

SRCS		=	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				srcs/map/parsing_utils.c \
				srcs/map/parsing.c \
				srcs/map/define_map.c \
				srcs/map/check_map_construction.c \
				srcs/map/check_map_construction2.c \
				srcs/map/define_player_info.c \
				srcs/map/free_map.c \
				srcs/map/parsing_utils2.c \
				srcs/hooks/loop_hook.c \
				srcs/utils/create_trgb.c \
				srcs/utils/c3d_error.c \
				srcs/utils/charnbr.c \
				srcs/utils/close_game.c \
				srcs/main.c \
				srcs/cub3D.c \
				srcs/keys/key_pressed_hook.c \
				srcs/keys/key_release_hook.c \
				srcs/keys/init_keys_pressed.c \
				srcs/player_movement/camera_movement.c \
				srcs/player_movement/find_new_position.c \
				srcs/player_movement/player_movement.c \
				srcs/player_movement/update_position.c \
				srcs/player_movement/check_colision.c \
				srcs/player_movement/define_player_hitbox.c \
				srcs/render/raycast.c \
				srcs/render/render_3d_scene.c \
				srcs/render/render_minimap.c \
				srcs/render/put_img.c \
				srcs/render/render_utils.c


OBJS		=	${SRCS:.c=.o}

LD_FLAGS	=	-L libft -L mlx
MLX_FLAGS	=	-lm -lmlx -lXext -lX11
HEAD		=	-I includes -I libft -I mlx
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o		:
	@${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)		:	${OBJS}
	@make -s -C libft
	@make -si -C mlx
	@echo "\e[1mcub3D: binary file created\033[0m"
	@${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all			:	${NAME}

clean		:
	@make -s clean $@ -C libft
	@make -si clean $@ -C mlx
	@rm -rf ${OBJS}
	@echo "\e[1mcub3D: Object files deleted\033[0m"

fclean		:	clean
	@make -s fclean $@ -C libft
	@rm -rf ${NAME}
	@echo "\e[1mcub3D: binary file deleted\033[0m"

re			:	fclean all

val			:	all
	@valgrind \
	--leak-check=full --tool=memcheck \
	--show-reachable=yes \
	--track-fds=yes \
	--errors-for-leak-kinds=all \
	--show-leak-kinds=all ./cub3D maps/map2.cub

r			: all
	./cub3D maps/basic_map.cub

			

.PHONY		:	all clean fclean re