/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:00:38 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/19 13:25:35 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		while(n > 0)
		{
			*d = *s;
			n--;
			d++;
			s++;
		}
	}
	else if (d > s)
	{
		while(0 <= n)
		{
			n--;
			d[n] = s[n]
		}
	}
}
