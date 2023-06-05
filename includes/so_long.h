/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:47:28 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/05 13:42:57 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include "so_long_utils.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_map
{
	char	**matrix;
	int		length;
	int		width;
	int		player;
	int		exit;
	int		collect;
	int		enemies;
}	t_map;

typedef struct t_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}	t_sprite;

typedef struct s_player
{
	t_point		pos;
	t_point		next_pos;
	t_sprite	*sp_front;
	t_sprite	*sp_back;
	t_sprite	*sp_right;
	t_sprite	*sp_left;
	t_sprite	*sp_exit;
	t_sprite	*anim_dead;
	int			flag_pos;
	int			flag_exit;
	int			moves;
}	t_player;

typedef struct s_game
{
	t_map			*map;
	t_mlx			graph;
	t_sprite		*sp_tiles;
	t_sprite		*sp_torches;
	t_player		*p;
	t_player		**e;
	int				torche;
}	t_game;

//MAP
t_map		*get_map(char *str);
void		get_dimension(t_map *map, char *str);
void		matrix_generator(t_map *map, char *str);
void		check_map(t_map *map);

//CHECKS
int			check_numb_items(t_map *map);
int			check_ber(char *str);
int			check_equal_line(t_map *map);
int			check_accepted_char(t_map *map);
int			check_walls(t_map *map);

//INIT
void		init_check(t_map *check);
void		game_init(t_map *map);
void		graphic_init(t_game *game);
void		get_position(t_game *game);

//SPRITES
void		load_sprites(t_game *game);
void		load_tiles(t_game *game);
void		load_torches(t_game *game);
void		load_player(t_game *game);
void		load_exit_sprites(t_game *game);

//RENDER
void		render_map(t_game *game);
void		render_sprites(t_game *game, t_point p);
void		render_zombies(t_game *game, int i);
void		display_move(t_game *game);
int			render_frame(t_game *game);

//ANIMATION
int			animate_torche(t_game *game);
void		animate_death(t_game *game);
void		animate_out(t_game *game);
void		animate_in(t_game *game);

//LOAD_ANIM
void		load_death_anim(t_game *game);
void		load_anim_out(t_game *game);
void		load_anim_in(t_game *game);

//MOVES
int			listen_key(int keycode, t_game *game);
char		next_move(t_game *game);
t_sprite	*sprite_match(t_game *game);
void		move_player(t_game *game);
void		move_exit(t_game *game);

//CLOSE
void		destroy_game(t_game *game);
void		destroy_map(t_map *map);
void		destroy_sprites(t_game *game, t_sprite *sprite, int nb_sprite);
void		destroy_player(t_game *game);
void		err_checkmap(char *str, t_map *map);

//UTILS
int			quit_window(t_game *game);
int			err_message(char *str, t_game *game);
void		put_image(t_game *game, t_sprite *sp, t_point pos);

//BONUS
//Load zombies
void		load_enemies(t_game *game);
void		destroy_enemies(t_game *game);
void		get_enemie_pos(t_game *game);
int			move_zombies(t_game *game);

#endif
