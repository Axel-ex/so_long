/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:54:04 by achabrer          #+#    #+#             */
/*   Updated: 2023/05/22 09:57:24 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	check_str(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;

	if (argc < 2)
	{
		ft_printf("Enter an argument to use in the printf");
		return (0);
	}
	if (check_str(argv[1]) == 1 && argv[2][0] == 'd')
	{
		printf("mine\n");
		i = ft_printf("this is the output of an hex: %d\n", atoi(argv[1]));
		printf("original\n");
		j = printf("this is the output of an hex: %d\n", atoi(argv[1]));
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	if (check_str(argv[1]) == 1 && argv[2][0] == 'u')
	{
		printf("mine\n");
		i = ft_printf("this is the output of an unsigned: %u\n", atoi(argv[1]));
		printf("original\n");
		j = printf("this is the output of an unsigned: %u\n", atoi(argv[1]));
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	if (check_str(argv[1]) == 1 && argv[2][0] == 'x')
	{
		printf("mine\n");
		i = ft_printf("this is the output of an hex: %x\n", atoi(argv[1]));
		printf("original\n");
		j = printf("this is the output of an hex: %x\n", atoi(argv[1]));
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	if (check_str(argv[1]) == 1 && argv[2][0] == 'X')
	{
		printf("mine\n");
		i = ft_printf("this is the output of an hex: %X\n", atoi(argv[1]));
		printf("original\n");
		j = printf("this is the output of an hex: %X\n", atoi(argv[1]));
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	if (check_str(argv[1]) == 1 && argv[2][0] == 'p')
	{
		printf("mine\n");
		i = ft_printf("this is the output of a ptr: %p\n", argv[1]);
		printf("original\n");
		j = printf("this is the output of a ptr: %p\n", argv[1]);
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	if (check_str(argv[1]) == 0 && argv[2][0] == 's')
	{
		printf("mine\n");
		i = ft_printf("this is the output of a ptr: %s\n", argv[1]);
		printf("original\n");
		j = printf("this is the output of a ptr: %s\n", argv[1]);
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	//case of null pointer
	if (check_str(argv[1]) == 0 && argv[2][0] == 'p')
	{
		void	*ptr = NULL;
		printf("original:\n");
		j = printf("this is the output of a null pointer: %p\n", ptr);
		printf("mine:\n");
		i = ft_printf("this is the output of a null pointer: %p\n", ptr);
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	if (check_str(argv[1]) == 0 && argv[2][0] == 's')
	{
		char	*ptr = NULL;
		printf("\n\n\n");
		printf("original:\n");
		j = printf("this is the output of a null pointer: %s\n", ptr);
		printf("mine:\n");
		i = ft_printf("this is the output of a null pointer: %s\n", ptr);
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	if (check_str(argv[1]) == 0 && argv[2][0] == 'x')
	{
		int	ptr = 0;
		printf("original:\n");
		j = printf("this is the output of a null pointer: %x\n", ptr);
		printf("mine:\n");
		i = ft_printf("this is the output of a null pointer: %x\n", ptr);
		printf("return value ft_printf = %d\nreturn value printf = %d\n", i, j);
	}
	return (0);
}
