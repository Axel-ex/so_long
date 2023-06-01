/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:13:34 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/01 10:44:44 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		return (0);
	check_map(map);
	game_init(map);
	return (0);
}
