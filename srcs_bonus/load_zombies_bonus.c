/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_zombies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:43:44 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/01 13:37:04 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

static void	alloc_enemies(t_game *game, int i)
{
	game->e[i] = calloc(1, sizeof(t_player));
	if (!game->e)
		err_message("failed to allocate enemies", game);
	game->e[i]->sp_front = calloc(1, sizeof(t_sprite));
	game->e[i]->sp_back = calloc(1, sizeof(t_sprite));
	game->e[i]->sp_right = calloc(1, sizeof(t_sprite));
	game->e[i]->sp_left = calloc(1, sizeof(t_sprite));
	if (!game->e[i]->sp_front || !game->e[i]->sp_back
		|| !game->e[i]->sp_right || !game->e[i]->sp_left)
		err_message("failed to allocate zombie sprites", game);
}

t_point	get_enemie_pos(t_game *game)
{
	static t_point	pos;

	pos.y = 0;
	while (pos.y < game->map->width)
	{
		pos.x = 0;
		while (pos.x < game->map->length)
		{
			if (game->map->matrix[pos.y][pos.x] == ENEMIES)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

void	load_enemies(t_game *game)
{
	int			i;

	game->e = (t_player **)malloc(sizeof(t_player *) * game->map->enemies);
	if (!game->e)
		err_message("failed allocating enemies", game);
	i = 0;
	while (i < game->map->enemies)
	{
		alloc_enemies(game, i);
		game->e[i]->sp_front[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
				ZOMBIE_FRONT, &(game->e[i]->sp_front[0].width),
				&(game->e[i]->sp_front[0].height));
		game->e[i]->sp_back[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
				ZOMBIE_BACK, &(game->e[i]->sp_back[0].width),
				&(game->e[i]->sp_back[0].height));
		game->e[i]->sp_right[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
				ZOMBIE_RIGHT, &(game->e[i]->sp_right[0].width),
				&(game->e[i]->sp_right[0].height));
		game->e[i]->sp_left[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
				ZOMBIE_LEFT, &(game->e[i]->sp_left[0].width),
				&(game->e[i]->sp_left[0].height));
		game->e[i]->pos = get_enemie_pos(game);
		i++;
	}
}
