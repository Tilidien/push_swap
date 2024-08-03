/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:02:31 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 15:05:11 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstpop(t_list **_lst)
{
	t_list	*out;

	out = *_lst;
	if (!out)
		return (NULL);
	if (out->next == out)
	{
		*_lst = NULL;
		out->next = NULL;
		out->prev = NULL;
		return (out);
	}
	out->next->prev = out->prev;
	out->prev->next = out->next;
	*_lst = out->next;
	out->next = NULL;
	out->prev = NULL;
	return (out);
}

t_list	*lst_new_elem(void *_content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (ft_ferror(NULL,
				"lst_new_elem: malloc returned 0!\n", -1), NULL);
	elem->content = _content;
	elem->next = 0;
	elem->prev = 0;
	return (elem);
}

t_list	*lst_new_elem_freeonfail(void *_content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (free(_content),
			ft_ferror(NULL,
				"lst_new_elem_freeonfail: malloc returned 0!\n", -1),
			NULL);
	elem->content = _content;
	elem->next = 0;
	elem->prev = 0;
	return (elem);
}

void	ft_nop(void *_sth)
{
	_sth = 0;
}
