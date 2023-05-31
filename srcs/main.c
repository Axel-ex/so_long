/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:13:34 by axelchab          #+#    #+#             */
/*   Updated: 2023/05/29 17:10:08 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		return (0);
	}
	map = get_map(argv[1]);
	if (!map)
		return (0);
	int i = 0;
	while (i < map->width)
	{
		ft_printf("%s\n", map->matrix[i]);
		i++;
	}
	check_map(map);
	game_init(map);
	return (0);
}
