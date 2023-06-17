/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_anim_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:34:59 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/17 15:20:08 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_death_anim(t_game *game)
{
	game->p->anim_dead = ft_calloc(4, sizeof(t_sprite));
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
