/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:26:27 by axelchab          #+#    #+#             */
/*   Updated: 2023/10/30 17:06:29 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

# ifndef MACOS
#  define MACOS 0
# endif

# define WALL '1'
# define GROUND '0'
# define EXIT 'E'
# define PLAYER 'P'
# define TORCHE 'C'
# define ENEMIES 'Z'

# define WA "assets/tiles/Wall.xpm"
# define GR "assets/tiles/Ground.xpm"
# define EX "assets/tiles/Exit.xpm"

# define TORCHE1 "assets/tiles/torche1.xpm"
# define TORCHE2 "assets/tiles/torche2.xpm"
# define TORCHE3 "assets/tiles/torche3.xpm"
# define TORCHE4 "assets/tiles/torche4.xpm"
# define TORCHE5 "assets/tiles/torche5.xpm"
# define TORCHE6 "assets/tiles/torche6.xpm"

# define PLAYER_FRONT1 "assets/player_front.xpm"
# define PLAYER_BACK1 "assets/Back.xpm"
# define PLAYER_RIGHT1 "assets/Right.xpm"
# define PLAYER_LEFT1 "assets/Left.xpm"

# define PF_EXIT "assets/player_front_exit.xpm"
# define PB_EXIT "assets/player_back_exit.xpm"
# define PR_EXIT "assets/player_right_exit.xpm"
# define PL_EXIT "assets/player_left_exit.xpm"

# define ZOMBIE_FRONT "assets/zombie_front.xpm"
# define ZOMBIE_BACK "assets/zombie_back.xpm"
# define ZOMBIE_RIGHT "assets/zombie_right.xpm"
# define ZOMBIE_LEFT "assets/zombie_left.xpm"

# define FRONT_DEATH1 "assets/anim/front_death1.xpm"
# define FRONT_DEATH2 "assets/anim/front_death2.xpm"
# define FRONT_DEATH3 "assets/anim/front_death3.xpm"
# define FRONT_DEATH4 "assets/anim/front_death4.xpm"

# if MACOS

#  define FREQ_MOVE 3000
#  define FREQ_ANIM	1000
#  define KEY_UP	126
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
#  define KEY_DOWN	125
#  define ESC		53

# else
#  define FREQ_ANIM 2500
#  define FREQ_MOVE 400
#  define KEY_UP	65362
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_DOWN	65364
#  define ESC		65307

# endif

typedef enum e_keys
{
	ON_KEYPRESS = 2,
	ON_DESTROY = 17,
}	t_keys;

typedef enum e_mask
{
	KEYPRESS_MASK = (1L << 0),
	DESTROY_MASK = (1L << 17),
}	t_mask;

typedef enum e_tiles_index
{
	W,
	G,
	E,
}	t_tiles_index;

typedef enum s_posflag
{
	FRONT,
	BACK,
	RIGHT,
	LEFT,
}	t_posflag;

//tiles index, player_index
#endif
