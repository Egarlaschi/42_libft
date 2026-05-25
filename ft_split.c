/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:39:40 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/25 11:53:16 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// a quanto pare ft_split e una ammazzata ora sono le 11:40 vediamo
// quando finisco.

static size_t	word_count(const char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if(str[i] == '\0')
			break;
		wn++;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count)
}
