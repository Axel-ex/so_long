/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:26:48 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/01 10:33:38 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*get_map(char *str)
{
	t_map	*map;

	if (!check_ber(str))
	{
		ft_printf("the name of the file doesn't contain .ber extension");
		return (NULL);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_check(map);
	get_dimension(map, str);
	matrix_generator(map, str);
	return (map);
}

void	get_dimension(t_map *map, char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		err_checkmap("no such file or directory", map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->width++;
	}
	close(fd);
}

void	matrix_generator(t_map *map, char *str)
{
	int		fd;
	int		i;
	char	*line;

	map->matrix = (char **)malloc(sizeof(char *) * map->width);
	if (!map->matrix)
		return ;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		err_checkmap("no such file or directory", map);
		return ;
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
		if (!map->matrix[i])
			return ;
		ft_strlcpy(map->matrix[i], line, ft_strlen(line));
		i++;
	}
}

void	check_map(t_map *map)
{
	if (map->width == 0)
		err_checkmap("the map is empty", map);
	if (!check_equal_line(map))
		err_checkmap("the lines are unequal", map);
	if (!check_accepted_char(map))
		err_checkmap("the map contains unauthorized chars", map);
	if (!check_walls(map))
		err_checkmap("The map is not surrounded by walls", map);
	check_numb_items(map);
	if (map->player > 1)
		err_checkmap("The map ccan only contain 1 player", map);
	if (map->exit != 1)
		err_checkmap("The map must contain 1 exit", map);
	if (map->collect == 0)
		err_checkmap("The map must contain at least one collectible", map);
}