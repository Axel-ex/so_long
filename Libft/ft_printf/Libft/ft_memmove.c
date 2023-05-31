/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelc <achabrer@student.42porto.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:31:52 by axelc             #+#    #+#             */
/*   Updated: 2023/04/23 12:19:02 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*origin;

	if (!dest && !src)
		return (NULL);
	origin = dest;
	if (dest > src)
	{
		while (n--)
			*((char *)dest + n) = *((char *)src + n);
	}
	else
	{
		while (n--)
			*((char *)dest++) = *((char *)src++);
	}
	return (origin);
}
