/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefined_algos_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:29:09 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 21:03:32 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	predef_alg_diffstack_2_0(void *_data)
{
	do_and_print(_data, ps_sb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_diffstack_2_1(void *_data)
{
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_diffstack_3_0(void *_data)
{
	do_and_print(_data, ps_rb, FALSE);
	do_and_print(_data, ps_sb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_diffstack_3_1(void *_data)
{
	do_and_print(_data, ps_rb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_diffstack_3_2(void *_data)
{
	do_and_print(_data, ps_rb, FALSE);
	do_and_print(_data, ps_sb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}
