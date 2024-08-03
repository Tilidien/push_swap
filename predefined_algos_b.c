/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefined_algos_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:14:56 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/04 00:32:49 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	predef_alg_samestack_3_4(void *_data)
{
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_ra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_rra, FALSE);
}

void	predef_alg_samestack_3_5(void *_data)
{
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_ra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
}

void	predef_alg_samestack_rev_2_0(void *_data)
{
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
}

void	predef_alg_samestack_rev_2_1(void *_data)
{
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
}

void	predef_alg_samestack_rev_3_0(void *_data)
{
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_rra, FALSE);
}
