/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:06:44 by axelchab          #+#    #+#             */
/*   Updated: 2023/05/31 13:15:53 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void	load_sprites(t_game *game)
{
	load_tiles(game);
	load_torches(game);
	load_player(game);
}

void	load_tiles(t_game *game)
{
	game->sp_tiles = malloc(sizeof(t_sprite) * 3);
	if (!game->sp_tiles)
		return ;
	game->sp_tiles[G].img = mlx_xpm_file_to_image(game->graph.mlx_ptr, GROUND,
			&(game->sp_tiles[G].width), &(game->sp_tiles[G].height));
	game->sp_tiles[W].img = mlx_xpm_file_to_image(game->graph.mlx_ptr, WALL,
			&(game->sp_tiles[W].width), &(game->sp_tiles[W].height));
	game->sp_tiles[E].img = mlx_xpm_file_to_image(game->graph.mlx_ptr, EXIT,
			&(game->sp_tiles[E].width), &(game->sp_tiles[E].height));
}

void	load_torches(t_game *game)
{
	game->sp_torches = ft_calloc(1, sizeof(t_sprite));
	game->sp_torches[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			TORCHE1, &(game->sp_torches->width), &(game->sp_torches->height));
}

void	load_player(t_game *game)
{
	game->p = calloc(1, sizeof(t_player));
	if (!game->p)
		return ;
	game->p->sp_front = ft_calloc(1, sizeof(t_sprite));
	game->p->sp_back = ft_calloc(1, sizeof(t_sprite));
	game->p->sp_right = ft_calloc(1, sizeof(t_sprite));
	game->p->sp_left = ft_calloc(1, sizeof(t_sprite));
	game->p->sp_front[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PLAYER_FRONT1, &(game->p->sp_front[0].width),
			&(game->p->sp_front[0].height));
	game->p->sp_back[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PLAYER_BACK1, &(game->p->sp_back[0].width),
			&(game->p->sp_back[0].height));
	game->p->sp_right[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PLAYER_RIGHT1, &(game->p->sp_right[0].width),
			&(game->p->sp_right[0].height));
	game->p->sp_left[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PLAYER_LEFT1, &(game->p->sp_left[0].width),
			&(game->p->sp_left[0].height));
	get_position(game);
}

void	get_position(t_game *game)
{
	t_point	pos;

	pos = (t_point){0, 0};
	while (pos.y < game->map->width)
	{
		pos.x = 0;
		while (pos.x < game->map->length)
		{
			if (game->map->matrix[pos.y][pos.x] == 'P')
			{
				game->p->pos = pos;
				return ;
			}
			pos.x++;
		}
		pos.y++;
	}
}
