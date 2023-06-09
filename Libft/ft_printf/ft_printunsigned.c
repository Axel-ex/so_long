/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 08:52:21 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/09 17:32:17 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbsize(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		size;

	size = ft_nbsize(nb);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb > 0)
	{
		str[size] = (nb % 10) + 48;
		nb /= 10;
		size--;
	}
	return (str);
}

int	ft_printunsigned(unsigned int nb)
{
	int		size;
	char	*n;

	n = ft_uitoa(nb);
	size = ft_strlen(n);
	ft_putstr_fd(n, 1);
	free(n);
	return (size);
}
