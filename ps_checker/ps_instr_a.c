/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instr_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:42:48 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 22:24:57 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

/// @brief sa (swap a): Swap the first 2 elements at the top of stack a.
/// Do nothing if there is only one or no elements.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_sa(void *_data)
{
	t_ps_data	*data;
	t_list		*first;
	t_list		*second;

	data = (t_ps_data *)_data;
	if (lstcount(&data->stack_a) < 2)
		return (FALSE);
	first = data->stack_a;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	first->next->prev = first;
	second->prev->next = second;
	data->stack_a = second;
	return (TRUE);
}

/// @brief sb (swap b): Swap the first 2 elements at the top of stack b.
/// Do nothing if there is only one or no elements.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_sb(void *_data)
{
	t_ps_data	*data;
	t_list		*first;
	t_list		*second;

	data = (t_ps_data *)_data;
	if (lstcount(&data->stack_b) < 2)
		return (FALSE);
	first = data->stack_b;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	first->next->prev = first;
	second->prev->next = second;
	data->stack_b = second;
	return (TRUE);
}

/// @brief ss : sa and sb at the same time.
/// @param _data pointer to a t_ps_data struct 
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_ss(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_a) < 2
		|| lstcount(&((t_ps_data *)_data)->stack_b) < 2)
		return (FALSE);
	return (ps_sa(_data) && ps_sb(_data));
}

/// @brief pa (push a): Take the first element 
/// at the top of b and put it at the top of a.
/// Do nothing if b is empty.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_pa(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_b) == 0)
		return (FALSE);
	lstadd_front(&((t_ps_data *)_data)->stack_a,
		lstpop(&((t_ps_data *)_data)->stack_b));
	return (TRUE);
}

/// @brief pb (push b): Take the first element 
/// at the top of a and put it at the top of b.
/// Do nothing if a is empty.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_pb(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_a) == 0)
		return (FALSE);
	lstadd_front(&((t_ps_data *)_data)->stack_b,
		lstpop(&((t_ps_data *)_data)->stack_a));
	return (TRUE);
}
