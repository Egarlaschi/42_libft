/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:36:46 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/19 17:09:17 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	i = size;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if(size <= len_dst)
	{
		return(size + len_src);
	}
	dst = dst + len_dst;
	while (*src && (i - len_dst > 1))
	{
		*dst = *src;
		dst++;
		src++;
		i--;
	}
	*dst = '\0';
	return (len_dst + len_src);
}
