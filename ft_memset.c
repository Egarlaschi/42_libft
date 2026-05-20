/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:44:02 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/20 12:37:32 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}

/*
int	main()
{
	char s[] = ".....";
	int c = 'a';

	printf("before memset : %s\n", s);
	ft_memset(s, c, 7);
	printf("after memset : %s\n", s);
	return (0);
}
*/
