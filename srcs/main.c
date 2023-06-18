/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:13:34 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/18 10:35:28 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\nYou must enter a map file as argument");
		return (0);
	}
	map = get_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	check_map(map);
	game_init(map);
	return (EXIT_SUCCESS);
}
