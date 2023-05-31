/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:26:27 by axelchab          #+#    #+#             */
/*   Updated: 2023/05/31 16:00:35 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

# define MACOS
/* 
# define LINUX
*/

# define WALL '1'
# define GROUND '0'
# define EXIT 'E'
# define PLAYER 'P'
# define TORCHE 'C'

# define WA "assets/tiles/45x45/Wall.xpm"
# define GR "assets/tiles/45x45/Ground.xpm"
# define EX "assets/tiles/45x45/Exit.xpm"
# define TORCHE1 "assets/tiles/45x45/Collectible.xpm"

# define PLAYER_FRONT1 "assets/tiles/45x45/Player_front.xpm"
# define PLAYER_BACK1 "assets/tiles/45x45/Back.xpm"
# define PLAYER_RIGHT1 "assets/tiles/45x45/Right.xpm"
# define PLAYER_LEFT1 "assets/tiles/45x45/Left.xpm"

# define PF_EXIT "assets/tiles/45x45/player_front_exit.xpm"
# define PB_EXIT "assets/tiles/45x45/player_back_exit.xpm"
# define PR_EXIT "assets/tiles/45x45/player_right_exit.xpm"
# define PL_EXIT "assets/tiles/45x45/player_left_exit.xpm"

# ifdef MACOS

#  define KEY_UP	126
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
#  define KEY_DOWN	125
#  define ESC		53

# endif

typedef enum e_keys
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17
}	t_keys;

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
