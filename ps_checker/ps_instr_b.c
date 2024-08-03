/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instr_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:44:24 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 22:25:00 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

/// @brief ra (rotate a): Shift up all elements of stack a by 1.
/// The first element becomes the last one.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_ra(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_a) < 2)
		return (FALSE);
	((t_ps_data *)_data)->stack_a = ((t_ps_data *)_data)->stack_a->next;
	return (TRUE);
}

/// @brief rb (rotate b): Shift up all elements of stack b by 1.
/// The first element becomes the last one.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_rb(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_b) < 2)
		return (FALSE);
	((t_ps_data *)_data)->stack_b = ((t_ps_data *)_data)->stack_b->next;
	return (TRUE);
}

/// @brief ra and rb at the same time.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_rr(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_a) < 2
		|| lstcount(&((t_ps_data *)_data)->stack_b) < 2)
		return (FALSE);
	((t_ps_data *)_data)->stack_a = ((t_ps_data *)_data)->stack_a->next;
	((t_ps_data *)_data)->stack_b = ((t_ps_data *)_data)->stack_b->next;
	return (TRUE);
}

/// @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_rra(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_a) < 2)
		return (FALSE);
	((t_ps_data *)_data)->stack_a = ((t_ps_data *)_data)->stack_a->prev;
	return (TRUE);
}

/// @brief rrb (reverse rotate b): Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_rrb(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_b) < 2)
		return (FALSE);
	((t_ps_data *)_data)->stack_b = ((t_ps_data *)_data)->stack_b->prev;
	return (TRUE);
}
