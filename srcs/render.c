/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:31:09 by axelchab          #+#    #+#             */
/*   Updated: 2023/05/31 22:50:38 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

	if (game->map->matrix[p.y][p.x] == '1')
		sp = game->sp_tiles[W];
	if (game->map->matrix[p.y][p.x] == '0')
		sp = game->sp_tiles[G];
	if (game->map->matrix[p.y][p.x] == 'E')
		sp = game->sp_tiles[E];
	if (game->map->matrix[p.y][p.x] == 'C')
		sp = game->sp_torches[0];
	if (game->map->matrix[p.y][p.x] == 'P')
		sp = game->p->sp_front[0];
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
		sp.img, p.x * sp.width, p.y * sp.height);
}
