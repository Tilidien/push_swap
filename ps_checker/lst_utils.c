/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:58:03 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 22:51:11 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

void	lstadd_front(t_list **_lst, t_list *_new)
{
	_new->next = *_lst;
	if (*_lst)
	{
		_new->prev = (*_lst)->prev;
		(*_lst)->prev = _new;
		_new->prev->next = _new;
	}
	else
	{
		_new->next = _new;
		_new->prev = _new;
	}
	*_lst = _new;
}

void	lstadd_back(t_list **_lst, t_list *_new)
{
	_new->next = *_lst;
	if (*_lst)
	{
		_new->prev = (*_lst)->prev;
		(*_lst)->prev = _new;
		_new->prev->next = _new;
	}
	else
	{
		_new->next = _new;
		_new->prev = _new;
		*_lst = _new;
	}
}

void	lstclear(t_list **_lst, void (*_del)(void *))
{
	t_list	*next;
	t_list	*first;

	next = (void *)0;
	first = *_lst;
	while (*_lst && (*_lst != first || next == 0))
	{
		next = _lst[0]->next;
		lstdelone(*_lst, _del);
		*_lst = next;
	}
	*_lst = 0;
}

size_t	lstcount(t_list **_lst)
{
	t_list	*first;
	t_list	*current;
	size_t	count;

	count = 0;
	first = *_lst;
	current = first;
	while (current && (current != first || count == 0))
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	lstdelone(t_list *_lst, void (*_del)(void *))
{
	if (_lst)
	{
		if (_del && _lst->content)
			_del(_lst->content);
		free(_lst);
	}
}
