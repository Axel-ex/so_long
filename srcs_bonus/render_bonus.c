/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:31:09 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/07 14:45:57 by axelchab         ###   ########.fr       */
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

void	display_move(t_game *game)
{
	char	*str;
	char	*str2;

	str = ft_itoa(game->p->moves);
	str2 = ft_itoa(game->p->moves - 1);
	mlx_string_put(game->graph.mlx_ptr, game->graph.mlx_win,
		45, 11 * 51, 0xffffff, "Number of moves:");
	mlx_string_put(game->graph.mlx_ptr, game->graph.mlx_win,
		4 * 45, 11 * 51, 0x000000, str2);
	mlx_string_put(game->graph.mlx_ptr, game->graph.mlx_win,
		4 * 45, 11 * 51, 0xFFFFFF, str);
	free(str);
	free(str2);
}

int	render_frame(t_game *game)
{
	animate_torche(game);
	move_zombies(game);
	display_move(game);
	return (0);
}
