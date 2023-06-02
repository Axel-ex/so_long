/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:31:09 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/02 09:42:41 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animate_torche(t_game *game)
{
	t_point		pos;
	static int	i;

	if (!i || i == 5)
		i = 0;
	pos.y = 0;
	while (pos.y < game->map->width)
	{
		pos.x = 0;
		while (pos.x < game->map->length)
		{
			if (game->map->matrix[pos.y][pos.x] == TORCHE)
			{
				mlx_put_image_to_window(game->graph.mlx_ptr,
					game->graph.mlx_win, game->sp_torches[i].img,
					game->sp_torches[i].width * pos.x,
					game->sp_torches[i].height * pos.y);
			}
			pos.x++;
		}
		pos.y++;
	}
	usleep(500);
	i++;
	return (i);
}

void	render_map(t_game *game)
{
	t_point	pos;

	pos.y = 0;
	while (pos.y < game->map->width)
	{
		pos.x = 0;
		while (pos.x < game->map->length)
		{
			render_sprites(game, pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	render_sprites(t_game *game, t_point p)
{
	t_sprite	sp;

	if (game->map->matrix[p.y][p.x] == WALL)
		sp = game->sp_tiles[W];
	if (game->map->matrix[p.y][p.x] == GROUND)
		sp = game->sp_tiles[G];
	if (game->map->matrix[p.y][p.x] == EXIT)
		sp = game->sp_tiles[E];
	if (game->map->matrix[p.y][p.x] == TORCHE)
		sp = game->sp_torches[0];
	if (game->map->matrix[p.y][p.x] == PLAYER)
		sp = game->p->sp_front[0];
	if (game->map->matrix[p.y][p.x] == ENEMIES)
		sp = game->e[0]->sp_front[0];
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
		sp.img, p.x * sp.width, p.y * sp.height);
}

void	render_zombies(t_game *game, int i)
{
	t_sprite	sp;

	if (game->e[i]->flag_pos == FRONT)
		sp = game->e[i]->sp_front[0];
	if (game->e[i]->flag_pos == BACK)
		sp = game->e[i]->sp_back[0];
	if (game->e[i]->flag_pos == RIGHT)
		sp = game->e[i]->sp_right[0];
	if (game->e[i]->flag_pos == LEFT)
		sp = game->e[i]->sp_left[0];
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
		sp.img, game->e[i]->next_pos.x * sp.width,
		game->e[i]->next_pos.y * sp.height);
}
