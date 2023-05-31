/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:42:39 by achabrer          #+#    #+#             */
/*   Updated: 2023/05/22 09:58:30 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

int	ft_printnb(int nb)
{
	int		size;
	char	*n;

	ft_putnbr_fd(nb, 1);
	n = ft_itoa(nb);
	size = ft_strlen(n);
	free(n);
	return (size);
}
