/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:26:50 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:49:04 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

size_t	ft_strlcpy_gnl(char *dst, char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	else if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_exstrchr(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	tmp = malloc((ft_strlen(s) - i) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy_gnl(tmp, s + i + 1, ft_strlen(s) - i + 1);
	free(s);
	return (tmp);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_strnldup(char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy_gnl(str, s1, i + 2);
	if (str[0] == '\0')
	{
		free (str);
		return (NULL);
	}
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
