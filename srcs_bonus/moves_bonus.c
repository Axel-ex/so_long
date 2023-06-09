/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:33:13 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/07 13:55:19 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	listen_key(int keycode, t_game *game)
{
	if (keycode == ESC)
		destroy_game(game);
	if (keycode == KEY_DOWN)
	{
		game->p->next_pos = (t_point){game->p->pos.x, game->p->pos.y + 1};
		game->p->flag_pos = FRONT;
	}
	if (keycode == KEY_UP)
	{
		game->p->next_pos = (t_point){game->p->pos.x, game->p->pos.y - 1};
		game->p->flag_pos = BACK;
	}
	if (keycode == KEY_RIGHT)
	{
		game->p->next_pos = (t_point){game->p->pos.x + 1, game->p->pos.y};
		game->p->flag_pos = RIGHT;
	}
	if (keycode == KEY_LEFT)
	{
		game->p->next_pos = (t_point){game->p->pos.x - 1, game->p->pos.y};
		game->p->flag_pos = LEFT;
	}
	move_player(game);
	return (keycode);
}

char	next_move(t_game *game)
{
	if (game->map->matrix[game->p->next_pos.y][game->p->next_pos.x] == EXIT)
		return (EXIT);
	if (game->map->matrix[game->p->next_pos.y][game->p->next_pos.x] == WALL)
		return (WALL);
	if (game->map->matrix[game->p->next_pos.y][game->p->next_pos.x] == TORCHE)
	{
		game->torche++;
		game->map->matrix[game->p->next_pos.y][game->p->next_pos.x] = GROUND;
	}
	game->p->flag_exit = 0;
	return (0);
}

t_sprite	*sprite_match(t_game *game)
{
	t_sprite	*sp;

	if (game->p->flag_pos == FRONT)
		sp = game->p->sp_front;
	if (game->p->flag_pos == BACK)
		sp = game->p->sp_back;
	if (game->p->flag_pos == RIGHT)
		sp = game->p->sp_right;
	if (game->p->flag_pos == LEFT)
		sp = game->p->sp_left;
	return (sp);
}

void	move_player(t_game *game)
{
	t_sprite	*sp;
	t_sprite	prev;

	sp = sprite_match(game);
	if (game->p->flag_exit == 0)
		prev = game->sp_tiles[G];
	if (game->p->flag_exit == 1)
		prev = game->sp_tiles[E];
	if (!next_move(game))
	{
		put_image(game, &(prev), game->p->pos);
		animate_out(game);
		put_image(game, &(prev), game->p->pos);
		animate_in(game);
		put_image(game, &(prev), game->p->next_pos);
		put_image(game, sp, game->p->next_pos);
		game->p->pos = game->p->next_pos;
	}
	if (next_move(game) == EXIT)
		move_exit(game);
	game->p->moves++;
}

void	move_exit(t_game *game)
{
	t_sprite	sp;

	if (game->p->flag_pos == FRONT)
		sp = game->p->sp_exit[FRONT];
	if (game->p->flag_pos == BACK)
		sp = game->p->sp_exit[BACK];
	if (game->p->flag_pos == RIGHT)
		sp = game->p->sp_exit[RIGHT];
	if (game->p->flag_pos == LEFT)
		sp = game->p->sp_exit[LEFT];
	put_image(game, &(sp), game->p->next_pos);
	put_image(game, &(game->sp_tiles[G]), game->p->pos);
	game->p->pos = game->p->next_pos;
	game->p->flag_exit = 1;
	if (game->torche == game->map->collect)
		destroy_game(game);
}
