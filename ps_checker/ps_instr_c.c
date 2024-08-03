/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instr_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:44:24 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 22:34:27 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

/// @brief rrr : rra and rrb at the same time.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool	ps_rrr(void *_data)
{
	if (lstcount(&((t_ps_data *)_data)->stack_a) < 2
		|| lstcount(&((t_ps_data *)_data)->stack_b) < 2)
		return (FALSE);
	((t_ps_data *)_data)->stack_a = ((t_ps_data *)_data)->stack_a->prev;
	((t_ps_data *)_data)->stack_b = ((t_ps_data *)_data)->stack_b->prev;
	return (TRUE);
}

void	ft_ferror(t_ps_data *_data_to_clear, char *_str, int _errno)
{
	static t_ps_data	*data_to_clear;

	if (_data_to_clear)
	{
		data_to_clear = _data_to_clear;
		return ;
	}
	if (data_to_clear->lst_obj_pool)
		free(data_to_clear->lst_obj_pool);
	if (data_to_clear->numbers)
		free(data_to_clear->numbers);
	if (data_to_clear->instr)
		free(data_to_clear->instr);
	while (*_str)
		write(2, _str++, 1);
	exit(_errno);
}
