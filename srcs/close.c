/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:19:23 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/01 10:36:19 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_game(t_game *game)
{
	if (game->sp_torches)
		destroy_sprites(game, game->sp_torches, 1);
	if (game->sp_tiles)
		destroy_sprites(game, game->sp_tiles, 3);
	if (game->p)
		destroy_player(game);
	if (game->graph.img)
		mlx_destroy_image(game->graph.mlx_ptr, game->graph.img);
	if (game->graph.mlx_win)
		mlx_destroy_window(game->graph.mlx_ptr, game->graph.mlx_win);
	if (game->torche == game->map->collect)
		ft_printf("YOU WON THE GAME");
	if (game->map)
		destroy_map(game->map);
	free(game);
	exit(0);
}

void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->matrix)
	{
		while (i < map->width)
			free(map->matrix[i++]);
		free(map->matrix);
	}
	free(map);
}

void	destroy_sprites(t_game *game, t_sprite *sprite, int nb_sprite)
{
	int	i;

	i = 0;
	while (i < nb_sprite)
	{
		if (sprite->img)
			mlx_destroy_image(game->graph.mlx_ptr, sprite[i].img);
		i++;
	}
	free(sprite);
}

void	destroy_player(t_game *game)
{
	destroy_sprites(game, game->p->sp_front, 1);
	destroy_sprites(game, game->p->sp_back, 1);
	destroy_sprites(game, game->p->sp_right, 1);
	destroy_sprites(game, game->p->sp_left, 1);
	destroy_sprites(game, game->p->sp_exit, 4);
	free(game->p);
}

void	err_checkmap(char *str, t_map *map)
{
	ft_printf("Error\n%s", str);
	destroy_map(map);
	exit(0);
}
