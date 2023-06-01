/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_destroy_zombies_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:53:02 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/01 12:58:02 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->enemies)
	{
		destroy_sprites(game, game->e[i]->sp_front, 1);
		destroy_sprites(game, game->e[i]->sp_back, 1);
		destroy_sprites(game, game->e[i]->sp_right, 1);
		destroy_sprites(game, game->e[i]->sp_left, 1);
		free(game->e[i]);
	}
	free(game->e);
}
