/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelc <achabrer@student.42porto.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:09:31 by axelc             #+#    #+#             */
/*   Updated: 2023/04/19 10:53:04 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n)
	{
		if (*s1 != *s2)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
		n--;
	}
	if (n)
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	return (0);
}
