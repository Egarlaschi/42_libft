/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:20:13 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/20 12:56:42 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
X CHI MI CORREGGE
norminette mi ha costretto a dichiarare in quel modo la variabile i;
nn e colpa mia a norminette je va bene solo cosi
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	cc;
	int		i;

	i = 0;
	cc = (char )c;
	res = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (res);
}
