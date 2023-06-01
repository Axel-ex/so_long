/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:49:24 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/01 12:07:23 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	quit_window(t_game *game)
{
	destroy_game(game);
	exit(0);
}

int	err_message(char *str, t_game *game)
{
	ft_printf("Error\n%s", str);
	destroy_game(game);
	return (0);
}
