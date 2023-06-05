/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:49:24 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/05 13:50:39 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	quit_window(t_game *game)
{
	destroy_game(game);
	exit(0);
}

int	err_message(char *str, t_game *game)
{
	ft_printf("Error\n%s", str);
	destroy_game(game);
	return (0);
}

void	err_checkmap(char *str, t_map *map)
{
	ft_printf("Error\n%s", str);
	destroy_map(map);
	exit(0);
}

void	put_image(t_game *game, t_sprite *sp, t_point pos)
{
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
		sp->img, pos.x * sp->width,
		pos.y * sp->height);
}
