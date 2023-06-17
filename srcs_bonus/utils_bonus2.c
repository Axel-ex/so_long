/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:33:59 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/17 14:15:54 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
