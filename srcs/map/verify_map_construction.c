#include "../../cub3D.h"

static int	valid_token(char c)
{
	return (c == 48 || c == 49 || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	verify_characters(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j + 1])
		{
			if (!valid_token(map[i][j]))
				return (false);
		}
	}
	return (true);
}

static bool	verify_player_existence(char **map)
{
	int		i;
	int		j;
	int		flag1;
	int		flag2;

	i = -1;
	flag1 = 0;
	flag2 = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				if (flag1)
					flag2 = 1;
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				flag1 = 1;
		}
	}
	if (!flag1 || flag2)
		return (false);
	return (true);
}

static bool	verify_line_lenght(char	**map)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(map[i]);
	while (map[i + 1])
	{
		if (len != (int)ft_strlen(map[i]))
			return (false);
		len = ft_strlen(map[i]);
		i++;
	}
	return (true);
}

/*	verifies if the map is well constructed and doesn't have any mistake	*/
bool	verify_map_construction(char **map)
{
	if (!verify_characters(map))
		return (print_error(ERROR_CONTRUCTION));
	if (!verify_player_existence(map))
		return (print_error(ERROR_CONTRUCTION));
	if (!verify_line_lenght(map))
		return (print_error(ERROR_CONTRUCTION));
	return (true);
}