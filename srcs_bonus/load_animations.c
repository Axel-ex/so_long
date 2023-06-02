/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:05:23 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/02 10:11:07 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_death_anim(t_game *game)
{
	game->p->sp_front[1].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH1, &(game->p->sp_front[1].width),
			&(game->p->sp_front[1].height));
	game->p->sp_front[2].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH2, &(game->p->sp_front[2].width),
			&(game->p->sp_front[2].height));
	game->p->sp_front[3].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH3, &(game->p->sp_front[3].width),
			&(game->p->sp_front[3].height));
	game->p->sp_front[4].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH4, &(game->p->sp_front[4].width),
			&(game->p->sp_front[4].height));
}
