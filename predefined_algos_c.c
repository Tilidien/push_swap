/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefined_algos_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:27:17 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 20:37:45 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	predef_alg_samestack_rev_3_1(void *_data)
{
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_rra, FALSE);
}

void	predef_alg_samestack_rev_3_2(void *_data)
{
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
}

void	predef_alg_samestack_rev_3_3(void *_data)
{
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
}

void	predef_alg_samestack_rev_3_4(void *_data)
{
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_pb, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	predef_alg_samestack_rev_3_5(void *_data)
{
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_pb, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}
