/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:06:26 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 16:54:09 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	fac(unsigned int _n)
{
	if (_n <= 1)
		return (_n);
	return (_n * fac(_n -1));
}

static int	get_smaller_elemets(t_list *_lst, int _len)
{
	t_list	*current_j;
	int		i;
	int		smaller_elements;

	i = -1;
	smaller_elements = 0;
	current_j = _lst;
	while (++i < _len)
	{
		if (*((int *)current_j->content) < *((int *)_lst->prev->content))
			smaller_elements++;
		current_j = current_j->next;
	}
	return (smaller_elements);
}


static int	get_permutation_rank(t_list *_perm, int _len)
{
	int		rank;
	int		i;
	t_list	*current_i;

	rank = 0;
	i = -1;
	if (_len == -1)
		_len = lstcount(&_perm);
	current_i = _perm;
	while (++i < _len)
	{
		rank += get_smaller_elemets(current_i->next,
				_len - i - 1) * fac(_len - 1 - i);
		current_i = current_i->next;
	}
	return (rank);
}

t_bool	set_to_indexes(t_list *_list, int _len)
{
	int		i;
	t_list	*temp_arr;
	t_list	*temp_list;

	if (_len == -1)
		_len = lstcount(&_list);
	temp_arr = (t_list *)malloc(_len * sizeof(t_list));
	if (!temp_arr)
		return (FALSE);
	i = -1;
	temp_list = NULL;
	while (++i < _len)
	{
		temp_arr[i].content = _list->content;
		lstadd_back(&temp_list, &temp_arr[i]);
		_list = _list->next;
	}
	bubblesort(&temp_list, _len);
	i = -1;
	while (++i < _len)
	{
		*((int *)temp_list->content) = i + 1;
		temp_list = temp_list->next;
	}
	return (free(temp_arr), TRUE);
}

unsigned int	find_permutation_rank(t_list *_lst, int _len, t_bool _rev)
{
	int	i;

	i = -1;
	if (_rev)
		while (++i < _len)
			_lst = _lst->prev;
	if (!set_to_indexes(_lst, _len))
		return (ft_ferror(NULL, "set_to_indexes could not allocate", -1), 0);
	return (get_permutation_rank(_lst, _len));
}
