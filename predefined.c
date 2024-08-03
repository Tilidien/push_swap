/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefined.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:34:38 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 21:07:18 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_predefined_samestack_algo(int _len, int _rank, void *_data)
{
	if (_len == 1)
		return ;
	else if (_len == 2)
	{
		if (_rank == 1)
			predef_alg_samestack_2_1(_data);
	}
	else if (_len == 3)
	{
		if (_rank == 0)
			predef_alg_samestack_3_0(_data);
		else if (_rank == 1)
			predef_alg_samestack_3_1(_data);
		else if (_rank == 2)
			predef_alg_samestack_3_2(_data);
		else if (_rank == 3)
			predef_alg_samestack_3_3(_data);
		else if (_rank == 4)
			predef_alg_samestack_3_4(_data);
		else if (_rank == 5)
			predef_alg_samestack_3_5(_data);
	}
}

void	do_predefined_samestack_rev_algo(int _len, int _rank, void *_data)
{
	if (_len == 1)
		do_and_print(_data, ps_rra, FALSE);
	else if (_len == 2)
	{
		if (_rank == 0)
			predef_alg_samestack_rev_2_0(_data);
		if (_rank == 1)
			predef_alg_samestack_rev_2_1(_data);
	}
	else if (_len == 3)
	{
		if (_rank == 0)
			predef_alg_samestack_rev_3_0(_data);
		else if (_rank == 1)
			predef_alg_samestack_rev_3_1(_data);
		else if (_rank == 2)
			predef_alg_samestack_rev_3_2(_data);
		else if (_rank == 3)
			predef_alg_samestack_rev_3_3(_data);
		else if (_rank == 4)
			predef_alg_samestack_rev_3_4(_data);
		else if (_rank == 5)
			predef_alg_samestack_rev_3_5(_data);
	}
}

void	do_predefined_diffstack_algo(int _len, int _rank, void *_data)
{
	if (_len == 1)
		do_and_print(_data, ps_pa, FALSE);
	else if (_len == 2)
	{
		if (_rank == 0)
			predef_alg_diffstack_2_0(_data);
		if (_rank == 1)
			predef_alg_diffstack_2_1(_data);
	}
	else if (_len == 3)
	{
		if (_rank == 0)
			predef_alg_diffstack_3_0(_data);
		else if (_rank == 1)
			predef_alg_diffstack_3_1(_data);
		else if (_rank == 2)
			predef_alg_diffstack_3_2(_data);
		else if (_rank == 3)
			predef_alg_diffstack_3_3(_data);
		else if (_rank == 4)
			predef_alg_diffstack_3_4(_data);
		else if (_rank == 5)
			predef_alg_diffstack_3_5(_data);
	}
}

void	do_predefined_diffstack_rev_algo(int _len, int _rank, void *_data)
{
	if (_len == 1)
		diffstack_solo(_data);
	else if (_len == 2)
	{
		if (_rank == 0)
			predef_alg_diffstack_rev_2_0(_data);
		if (_rank == 1)
			predef_alg_diffstack_rev_2_1(_data);
	}
	else if (_len == 3)
	{
		if (_rank == 0)
			predef_alg_diffstack_rev_3_0(_data);
		else if (_rank == 1)
			predef_alg_diffstack_rev_3_1(_data);
		else if (_rank == 2)
			predef_alg_diffstack_rev_3_2(_data);
		else if (_rank == 3)
			predef_alg_diffstack_rev_3_3(_data);
		else if (_rank == 4)
			predef_alg_diffstack_rev_3_4(_data);
		else if (_rank == 5)
			predef_alg_diffstack_rev_3_5(_data);
	}
}

void	do_algo_for_block(t_ps_data *_data, t_qs_block *_block)
{
	int	len;

	len = _block->max - _block->min + 1;
	if (_block->rotate_instr == ps_ra)
		do_predefined_samestack_algo(len,
			find_permutation_rank(_data->stack_a, len, FALSE), _data);
	else if (_block->rotate_instr == ps_rra)
		do_predefined_samestack_rev_algo(len,
			find_permutation_rank(_data->stack_a, len, TRUE), _data);
	else if (_block->rotate_instr == ps_rb)
		do_predefined_diffstack_algo(len,
			find_permutation_rank(_data->stack_b, len, FALSE), _data);
	else if (_block->rotate_instr == ps_rrb)
		do_predefined_diffstack_rev_algo(len,
			find_permutation_rank(_data->stack_b, len, TRUE), _data);
	_block->sorted = TRUE;
}
