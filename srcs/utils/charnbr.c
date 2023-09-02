/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:19:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:51:00 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	charnbr(char *line, char c)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (line[++i])
		if (line[i] == c)
			counter++;
	return (counter);
}
