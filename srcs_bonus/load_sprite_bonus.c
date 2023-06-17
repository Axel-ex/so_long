/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:06:44 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/17 15:22:07 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void	load_sprites(t_game *game)
{
	load_tiles(game);
	load_torches(game);
	load_player(game);
	load_enemies(game);
	load_exit_sprites(game);
	load_death_anim(game);
}

void	load_tiles(t_game *game)
{
	game->sp_tiles = ft_calloc(3, sizeof(t_sprite));
	if (!game->sp_tiles)
		return ;
	game->sp_tiles[G].img = mlx_xpm_file_to_image(game->graph.mlx_ptr, GR,
			&(game->sp_tiles[G].width), &(game->sp_tiles[G].height));
	game->sp_tiles[W].img = mlx_xpm_file_to_image(game->graph.mlx_ptr, WA,
			&(game->sp_tiles[W].width), &(game->sp_tiles[W].height));
	game->sp_tiles[E].img = mlx_xpm_file_to_image(game->graph.mlx_ptr, EX,
			&(game->sp_tiles[E].width), &(game->sp_tiles[E].height));
}

void	load_torches(t_game *game)
{
	game->sp_torches = ft_calloc(6, sizeof(t_sprite));
	game->sp_torches[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			TORCHE1, &(game->sp_torches[0].width),
			&(game->sp_torches[0].height));
	game->sp_torches[1].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			TORCHE2, &(game->sp_torches[1].width),
			&(game->sp_torches[1].height));
	game->sp_torches[2].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			TORCHE3, &(game->sp_torches[2].width),
			&(game->sp_torches[2].height));
	game->sp_torches[3].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			TORCHE4, &(game->sp_torches[3].width),
			&(game->sp_torches[3].height));
	game->sp_torches[4].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			TORCHE5, &(game->sp_torches[4].width),
			&(game->sp_torches[4].height));
	game->sp_torches[5].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			TORCHE6, &(game->sp_torches[5].width),
			&(game->sp_torches[5].height));
}

void	load_player(t_game *game)
{
	game->p = ft_calloc(1, sizeof(t_player));
	if (!game->p)
		return ;
	game->p->sp_front = ft_calloc(1, sizeof(t_sprite));
	game->p->sp_back = ft_calloc(1, sizeof(t_sprite));
	game->p->sp_right = ft_calloc(1, sizeof(t_sprite));
	game->p->sp_left = ft_calloc(1, sizeof(t_sprite));
	game->p->sp_front->img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PLAYER_FRONT1, &(game->p->sp_front->width),
			&(game->p->sp_front->height));
	game->p->sp_back->img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PLAYER_BACK1, &(game->p->sp_back->width),
			&(game->p->sp_back->height));
	game->p->sp_right->img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PLAYER_RIGHT1, &(game->p->sp_right->width),
			&(game->p->sp_right->height));
	game->p->sp_left->img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PLAYER_LEFT1, &(game->p->sp_left->width),
			&(game->p->sp_left->height));
	game->p->pos = get_position(game->map);
	game->p->flag_exit = 0;
	game->p->moves = 0;
}

void	load_exit_sprites(t_game *game)
{
	game->p->sp_exit = ft_calloc(4, sizeof(t_sprite));
	if (!game->p->sp_exit)
		return ;
	game->p->sp_exit[FRONT].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PF_EXIT, &(game->p->sp_exit[FRONT].width),
			&(game->p->sp_exit[FRONT].height));
	game->p->sp_exit[BACK].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PB_EXIT, &(game->p->sp_exit[BACK].width),
			&(game->p->sp_exit[BACK].height));
	game->p->sp_exit[RIGHT].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PR_EXIT, &(game->p->sp_exit[RIGHT].width),
			&(game->p->sp_exit[RIGHT].height));
	game->p->sp_exit[LEFT].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			PL_EXIT, &(game->p->sp_exit[LEFT].width),
			&(game->p->sp_exit[LEFT].height));
}
