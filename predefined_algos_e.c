/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefined_algos_e.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:30:12 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 21:05:07 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	predef_alg_diffstack_3_3(void *_data)
{
	do_and_print(_data, ps_sb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_diffstack_3_4(void *_data)
{
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_sb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_diffstack_3_5(void *_data)
{
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_diffstack_rev_2_0(void *_data)
{
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_diffstack_rev_2_1(void *_data)
{
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}
