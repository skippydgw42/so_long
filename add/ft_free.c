#include "../includes/so_long.h"

void    ft_free(t_data *data)
{
    int i;

    i = 0;
    while (data->map[i])
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    free(data->items);
    free(data->vars);
    free(data->tiles);
    free(data->player);
    free(data->card);
    free(data);
}