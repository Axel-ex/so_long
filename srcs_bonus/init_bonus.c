/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:31:39 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/18 10:32:37 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_check(t_map *map)
{
	map->matrix = NULL;
	map->width = 0;
	map->length = 0;
	map->exit = 0;
	map->player = 0;
	map->collect = 0;
}

void	game_init(t_map *map)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		err_checkmap("failed to allocate memory for the game", map);
	game->map = map;
	game->torche = 0;
	graphic_init(game);
	load_sprites(game);
	render_map(game);
	mlx_hook(game->graph.mlx_win, ON_KEYPRESS, KEYPRESS_MASK, listen_key, game);
	mlx_hook(game->graph.mlx_win, ON_DESTROY, DESTROY_MASK, quit_window, game);
	mlx_loop_hook(game->graph.mlx_ptr, render_frame, game);
	mlx_loop(game->graph.mlx_ptr);
}

void	graphic_init(t_game *game)
{
	game->graph.mlx_ptr = mlx_init();
	if (!game->graph.mlx_ptr)
		err_message("failed to init graphics", game);
	game->graph.mlx_win = mlx_new_window(game->graph.mlx_ptr,
			45 * game->map->length, 48 * game->map->width, "so_long");
	if (!game->graph.mlx_win)
		err_message("failed to init window", game);
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
