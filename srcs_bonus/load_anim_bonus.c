/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:34:59 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/05 11:43:06 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_death_anim(t_game *game)
{
	game->p->anim_dead = calloc(4, sizeof(t_sprite));
	if (!game->p->anim_dead)
		err_message("failed allocating animations", game);
	game->p->anim_dead[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH1, &(game->p->anim_dead[0].width),
			&(game->p->anim_dead[0].height));
	game->p->anim_dead[1].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH2, &(game->p->anim_dead[1].width),
			&(game->p->anim_dead[1].height));
	game->p->anim_dead[2].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH3, &(game->p->anim_dead[2].width),
			&(game->p->anim_dead[2].height));
	game->p->anim_dead[3].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH4, &(game->p->anim_dead[3].width),
			&(game->p->anim_dead[3].height));
}

void	load_anim_out(t_game *game)
{
	game->p->sp_front[1].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_OUT, &(game->p->sp_front[1].width),
			&(game->p->sp_front[1].height));
	game->p->sp_back[1].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			BACK_OUT, &(game->p->sp_back[1].width),
			&(game->p->sp_back[1].height));
	game->p->sp_right[1].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			RIGHT_OUT, &(game->p->sp_right[1].width),
			&(game->p->sp_right[1].height));
	game->p->sp_left[1].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			LEFT_OUT, &(game->p->sp_left[1].width),
			&(game->p->sp_left[1].height));
}

void	load_anim_in(t_game *game)
{
	game->p->sp_front[2].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_IN, &(game->p->sp_front[2].width),
			&(game->p->sp_front[2].height));
	game->p->sp_back[2].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			BACK_IN, &(game->p->sp_back[2].width),
			&(game->p->sp_back[2].height));
	game->p->sp_right[2].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			RIGHT_IN, &(game->p->sp_right[2].width),
			&(game->p->sp_right[2].height));
	game->p->sp_left[2].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			LEFT_IN, &(game->p->sp_left[2].width),
			&(game->p->sp_left[2].height));
}
