/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:01:07 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/01/31 16:59:54 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char	*ft_read_last_line(char **str)
{
	char	*first_nl;
	char	*last_line;
	char	*buffer;

	if (ft_strlen(*str) == 0)
	{
		free(*str);
		return (0);
	}
	first_nl = ft_strchr(*str, '\n');
	last_line = ft_substr(*str, 0, first_nl - *str + 1);
	buffer = *str;
	*str = ft_substr(*str, first_nl - *str + 1, ft_strlen(*str));
	free(buffer);
	return (last_line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*to_free;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0)
		return (0);
	if (ft_strchr(str, '\n'))
		return (ft_read_last_line(&str));
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		to_free = str;
		str = ft_strjoin(str, buffer);
		if (to_free)
			free(to_free);
		if (ft_strchr(str, '\n'))
		{
			return (ft_read_last_line(&str));
		}
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_read_last_line(&str));
}