/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:06:22 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/19 18:16:02 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int	i;

	i = 0;
	cc = (char )c;
	while(s[i])
	{
		if (s[i] == cc)
		{
			return((char *)&s[i]);
		}
	i++;
	}
	if(s[i] == cc)
		return((char *)&s[i]);
	return(NULL);
}
