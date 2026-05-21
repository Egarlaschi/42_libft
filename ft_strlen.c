/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:21:33 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/18 15:12:08 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_strlen = %d", ft_strlen(argv[1]));
	return (0);
}
*/
