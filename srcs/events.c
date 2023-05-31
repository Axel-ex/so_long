/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:33:13 by axelchab          #+#    #+#             */
/*   Updated: 2023/05/31 13:14:04 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_move(t_game *game)
{
	if (game->map->matrix[game->p->next_pos.y][game->p->next_pos.x] == '1')
		return (0);
	if (game->map->matrix[game->p->next_pos.y][game->p->next_pos.x] == 'C')
		game->torche++;
	return (1);
}

void	move_player(t_game *game)
{
	t_sprite	*sp;

	if (game->p->flag_pos == DOWN)
		sp = game->p->sp_front;
	if (game->p->flag_pos == UP)
		sp = game->p->sp_back;
	if (game->p->flag_pos == RIGHT)
		sp = game->p->sp_right;
	if (game->p->flag_pos == LEFT)
		sp = game->p->sp_left;
	if (check_move(game))
	{
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
			sp->img, game->p->next_pos.x * sp->width,
			game->p->next_pos.y * sp->height);
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
			game->sp_tiles[G].img, game->p->pos.x * game->sp_tiles[G].width,
			game->p->pos.y * game->sp_tiles[G].height);
		game->p->pos = game->p->next_pos;
	}
	game->moves++;
}

int	listen_key(int keycode, t_game *game)
{
	if (keycode == ESC)
		destroy_game(game);
	if (keycode == KEY_UP)
	{
		game->p->next_pos = (t_point){game->p->pos.x, game->p->pos.y - 1};
		game->p->flag_pos = UP;
	}
	if (keycode == KEY_DOWN)
	{
		game->p->next_pos = (t_point){game->p->pos.x, game->p->pos.y + 1};
		game->p->flag_pos = DOWN;
	}
	if (keycode == KEY_LEFT)
	{
		game->p->next_pos = (t_point){game->p->pos.x - 1, game->p->pos.y};
		game->p->flag_pos = LEFT;
	}
	if (keycode == KEY_RIGHT)
	{
		game->p->next_pos = (t_point){game->p->pos.x + 1, game->p->pos.y};
		game->p->flag_pos = RIGHT;
	}
	move_player(game);
	return (keycode);
}
