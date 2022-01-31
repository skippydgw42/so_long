/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:07:01 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/01/31 16:47:18 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_init(int fd)
{
	char	*str;
	char	*to_free;
	char	*buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		to_free = str;
		str = ft_strjoin(str, buffer);
		if (to_free)
			free(to_free);
		if (buffer)
			free(buffer);
		buffer = get_next_line(fd);
	}
	return (ft_split(str, '\n'));
}