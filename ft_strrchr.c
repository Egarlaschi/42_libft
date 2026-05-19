/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:20:13 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/19 18:27:30 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int	i;
	char *res;

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
		res = (char *)&s[i];
	return(NULL);
}
