/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:51:08 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/02 15:36:45 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_death_anim(t_game *game)
{
	game->p->anim_dead = calloc(4, sizeof(t_sprite));
	if (!game->p->anim_dead)
		err_message("failed allocating animations", game);
	game->p->anim_dead[0].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH1, &(game->p->anim_dead[0].width),
			&(game->p->anim_dead[0].height));
	game->p->anim_dead[1].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH2, &(game->p->anim_dead[1].width),
			&(game->p->anim_dead[1].height));
	game->p->anim_dead[2].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH3, &(game->p->anim_dead[2].width),
			&(game->p->anim_dead[2].height));
	game->p->anim_dead[3].img = mlx_xpm_file_to_image(game->graph.mlx_ptr,
			FRONT_DEATH4, &(game->p->anim_dead[3].width),
			&(game->p->anim_dead[3].height));
}

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
