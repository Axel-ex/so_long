/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:51:08 by axelchab          #+#    #+#             */
/*   Updated: 2023/10/30 17:06:37 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animate_torche(t_game *game)
{
	t_point		pos;
	static int	i = 0;

	if (i == 5)
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

void	animate_death(t_game *game)
{
	int			freq;
	static int	i = 0;
	static int	counter = 0;

	freq = FREQ_ANIM;
	if (++counter % freq != 0)
		return ;
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
		game->p->anim_dead[i].img, game->p->anim_dead[i].width
		* game->p->pos.x, game->p->anim_dead[i].height
		* game->p->pos.y);
	i++;
	if (i == 4)
	{
		ft_printf("YOU'RE DEAD");
		destroy_game(game);
	}
}

void	put_image(t_game *game, t_sprite *sp, t_point pos)
{
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
		sp->img, pos.x * sp->width,
		pos.y * sp->height);
}
