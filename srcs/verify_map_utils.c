#include "../includes/cub3D.h"

int	correct_char(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j + 1])
		{
			if (!not_token(map[i][j]))
				return (1);
		}
	}
	return (0);
}

int	exists_player(char **map)
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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				if (flag1)
					flag2 = 1;
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				flag1 = 1;
		}
	}
	if (!flag1 || flag2)
		return (1);
	return (0);
}

int	not_token(char c)
{
	return (c == 48 || c == 49 || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	sameSizeLines(char **map)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(map[i]);
	while (map[i + 1])
	{
		if (len != (int)ft_strlen(map[i]))
			return (1);
		len = ft_strlen(map[i]);
		i++;
	}
	return (0);
}
