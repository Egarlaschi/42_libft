/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:35:01 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/27 15:46:27 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
}
