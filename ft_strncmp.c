/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:44:25 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/21 13:56:24 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return (((unsigned char) s1[i]) - ((unsigned char) s2[i]));
}
/*
int	main(int argc, char **argv)
{
	size_t	n;
	int	res;

	
	if (argc != 4)
	{
		printf("errore\n");
		return (1);
	}
	n = (int) atoi(argv[3]);
	res = ft_strncmp(argv[1], argv[2], n);
	printf("s1 = %s\n", argv[1]);
	printf("s2 = %s\n", argv[2]);
	printf("n = %d\n", (int) n);
	printf("--------------\n");
	printf("ft_strncmp = %d", res);
	return (0);
}
*/
