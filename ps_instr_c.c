/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instr_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:44:24 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 23:00:19 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	reverse_push(void *_data, t_bool (*_instr)(void *_data))
{
	if (_instr == ps_pa)
	{
		do_and_print(_data, ps_rrb, FALSE);
		do_and_print(_data, ps_pa, FALSE);
	}
	else if (_instr == ps_pb)
	{
		do_and_print(_data, ps_rra, FALSE);
		do_and_print(_data, ps_pb, FALSE);
	}
}

t_bool	do_and_print(void *_data, t_bool (*_instr)(void *_data), t_bool _rev)
{
	if (_rev && (_instr == ps_pa || _instr == ps_pb))
		return (reverse_push(_data, _instr), TRUE);
	if (_instr == ps_sa)
		return (write(1, "sa\n", 3), ps_sa(_data));
	if (_instr == ps_sb)
		return (write(1, "sb\n", 3), ps_sb(_data));
	if (_instr == ps_ss)
		return (write(1, "ss\n", 3), ps_ss(_data));
	if (_instr == ps_pa)
		return (write(1, "pa\n", 3), ps_pa(_data));
	if (_instr == ps_pb)
		return (write(1, "pb\n", 3), ps_pb(_data));
	if (_instr == ps_ra)
		return (write(1, "ra\n", 3), ps_ra(_data));
	if (_instr == ps_rb)
		return (write(1, "rb\n", 3), ps_rb(_data));
	if (_instr == ps_rr)
		return (write(1, "rr\n", 3), ps_rr(_data));
	if (_instr == ps_rra)
		return (write(1, "rra\n", 4), ps_rra(_data));
	if (_instr == ps_rrb)
		return (write(1, "rrb\n", 4), ps_rrb(_data));
	if (_instr == ps_rrr)
		return (write(1, "rrr\n", 4), ps_rrr(_data));
	return (FALSE);
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
	lstclear(&data_to_clear->blocklist_a, free);
	lstclear(&data_to_clear->blocklist_b, free);
	while (*_str)
		write(2, _str++, 1);
	exit(_errno);
}
