/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:51:08 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/05 13:46:25 by axelchab         ###   ########.fr       */
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

void	animate_death(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
			game->p->anim_dead[i].img, game->p->anim_dead[i].width
			* game->p->pos.x, game->p->anim_dead[i].height * game->p->pos.y);
		usleep(10000);
		i++;
	}
	ft_printf("YOU'RE DEAD");
}

void	animate_out(t_game *game)
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
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
		sp[1].img, sp[1].width * game->p->pos.x,
		sp[1].height * game->p->pos.y);
	usleep(1000);
}

void	animate_in(t_game *game)
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
	mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
		sp[2].img, sp[2].width * game->p->next_pos.x,
		sp[2].height * game->p->next_pos.y);
	usleep(1000);
}
