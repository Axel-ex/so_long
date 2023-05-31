/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:28:36 by axelchab          #+#    #+#             */
/*   Updated: 2023/05/19 14:43:36 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 2)
	{
		printf("enter an argument for printf");
		return (0);
	}
	printf("original: \n");
	i = printf("output of an int: %d\n", atoi(argv[1]));
	printf("mine: \n");
	j = ft_printf("output of an int: %d\n", atoi(argv[1]));
	printf("\nmine: %d\noriginal: %d\n", j, i);
	printf("\n\n\n");
	//char
	printf("original: \n");
	i = printf("output of an char: %c%c%c\n", '0', 0, '1');
	printf("mine: \n");
	j = ft_printf("output of an char: %c%c%c\n", '0', 0, '1');
	printf("\nmine: %d\noriginal: %d\n", j, i);
	return (0);
}
