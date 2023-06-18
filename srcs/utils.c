/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:49:24 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/18 10:31:35 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

int	quit_window(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
}

bool	flood_fill(t_map *map, char **matrix, t_point pos)
{
	static bool	found_exit = false;
	static int	torches = 0;

	if (matrix[pos.y][pos.x] == WALL)
		return (false);
	if (matrix[pos.y][pos.x] == TORCHE)
		torches++;
	if (matrix[pos.y][pos.x] == EXIT)
		found_exit = true;
	matrix[pos.y][pos.x] = WALL;
	flood_fill(map, matrix, (t_point){pos.x + 1, pos.y});
	flood_fill(map, matrix, (t_point){pos.x - 1, pos.y});
	flood_fill(map, matrix, (t_point){pos.x, pos.y + 1});
	flood_fill(map, matrix, (t_point){pos.x, pos.y - 1});
	return (torches == map->collect && found_exit);
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

void	err_checkmap(char *str, t_map *map)
{
	ft_printf("Error\n%s", str);
	destroy_map(map);
	exit(EXIT_SUCCESS);
}

void	err_message(char *str, t_game *game)
{
	ft_printf("Error\n%s", str);
	destroy_game(game);
}
