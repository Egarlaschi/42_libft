/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:39:40 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/25 13:50:55 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// a quanto pare ft_split e una ammazzata ora sono le 11:40 vediamo
// quando finisco.

static int	is_sep(char c, char sep)
{
	return(c == sep);
}

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
		if(s[i] == '\0')
			break;
		count++;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

static void	*free_all(char **res, int i)
{
	while(i >= 0)
		free(res[i--]);
	free(res);
	return (NULL);
}

static char	*alloc_word(const char *str, char sep)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while(str[len] && !is_sep(str[len], sep))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return(NULL);
	while(i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return(word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = alloc_word(s, c);
			if (!res[i])
				return (free_all(res, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
