/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:49:24 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/07 13:32:31 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	quit_window(t_game *game)
{
	destroy_game(game);
	exit(0);
}

int	err_message(char *str, t_game *game)
{
	ft_printf("Error\n%s", str);
	destroy_game(game);
	return (0);
}

void	err_checkmap(char *str, t_map *map)
{
	ft_printf("Error\n%s", str);
	destroy_map(map);
	exit(0);
}

t_point	get_position(t_map *map)
{
	t_point	pos;

	pos = (t_point){0, 0};
	while (pos.y < map->width)
	{
		pos.x = 0;
		while (pos.x < map->length)
		{
			if (map->matrix[pos.y][pos.x] == PLAYER)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

void	destroy_matrix(t_map *map, char **matrix)
{
	int	i;

	i = 0;
	while (i < map->width)
		free(matrix[i++]);
	free(matrix);
}
