/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:51:01 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/19 12:45:54 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr;
	unsigned char *src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while(n > 0)
	{
		*dest_ptr = *src_ptr;
		n--;
		dest_ptr++;
		src_ptr++;
	}
	return (dest);
}
/*
int	main()
{
	char dest[] = "............";
	char src[] = "ciaonenenene";

	printf("dest prima di memcpy: %s\n", dest);
	ft_memcpy(dest, src, 5);
	printf("dest dopo memcpy: %s\n", dest);
	return (0);
}
*/
