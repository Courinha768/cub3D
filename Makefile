NAME		=	cub3D

SRCS		=	$(shell find srcs/ -name '*.c') get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
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
	--show-leak-kinds=all ./cub3D maps/subject_map.cub

r			: all
	./cub3D maps/basic_map.cub

			

.PHONY		:	all clean fclean re