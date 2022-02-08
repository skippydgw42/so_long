/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:16:14 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/08 16:45:32 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_frame(t_data *data)
{
	if (data->loop == 3000)
	{
		step_enn(data);
		update_enn(data, data->card, data->map);
		anime_rabbit(data->vars, data->tiles);
		put_imgs(data->tiles, data->vars, data->map);
		data->loop = 0;
	}
	else
		data->loop++;
	return (1);
}