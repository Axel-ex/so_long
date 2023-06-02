/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_zombies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:53:02 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/02 10:55:30 by axelchab         ###   ########.fr       */
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

char	next_move_zombie(t_game *game, int i)
{
	if (game->map->matrix[game->e[i]->next_pos.y][game->e[i]->next_pos.x]
		== WALL)
		return (WALL);
	if (game->map->matrix[game->e[i]->next_pos.y][game->e[i]->next_pos.x]
		== EXIT)
		return (EXIT);
	if (game->map->matrix[game->e[i]->next_pos.y][game->e[i]->next_pos.x]
		== TORCHE)
		return (TORCHE);
	if (game->e[i]->next_pos.x == game->p->pos.x
		&& game->e[i]->next_pos.y == game->p->pos.y)
	{
		animate_death(game);
		destroy_game(game);
	}
	return (GROUND);
}

/*randomly select next_pos */
void	pick_move(t_game *game, int i)
{
	int		random;
	t_point	pos;

	random = rand() % 4 + 0;
	if (random == 0)
	{
		pos = (t_point){game->e[i]->pos.x, game->e[i]->pos.y + 1};
		game->e[i]->flag_pos = FRONT;
	}
	if (random == 1)
	{
		pos = (t_point){game->e[i]->pos.x, game->e[i]->pos.y - 1};
		game->e[i]->flag_pos = BACK;
	}
	if (random == 2)
	{
		pos = (t_point){game->e[i]->pos.x + 1, game->e[i]->pos.y};
		game->e[i]->flag_pos = RIGHT;
	}
	if (random == 3)
	{
		pos = (t_point){game->e[i]->pos.x - 1, game->e[i]->pos.y};
		game->e[i]->flag_pos = LEFT;
	}
	game->e[i]->next_pos = pos;
}

int	move_zombies(t_game *game)
{
	int	i;
	int	freq_move;

	animate_torche(game);
	freq_move = 45;
	if (game->torche == game->map->collect)
		freq_move = 150;
	i = 0;
	while (i < game->map->enemies)
	{
		pick_move(game, i);
		if (next_move_zombie(game, i) == GROUND
			&& game->e[0]->moves % freq_move == 0)
		{
			game->map->matrix[game->e[i]->pos.y][game->e[i]->pos.x] = GROUND;
			game->map->matrix[game->e[i]->next_pos.y]
			[game->e[i]->next_pos.x] = ENEMIES;
			render_sprites(game, game->e[i]->pos);
			render_zombies(game, i);
			game->e[i]->pos = game->e[i]->next_pos;
		}
		i++;
	}
	game->e[0]->moves++;
	return (i);
}
