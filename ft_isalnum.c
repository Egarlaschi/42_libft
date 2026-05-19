/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:47:07 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/18 14:11:49 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	else if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

/*
int main()
{
	char c =  '7';

	printf("isalpha = %d\n", c);
	printf("ft_isalpha = %d\n", c);
}
*/
