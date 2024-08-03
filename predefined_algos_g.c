/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefined_algos_g.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:32:41 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 21:05:23 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	predef_alg_diffstack_rev_3_5(void *_data)
{
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}

void	diffstack_solo(void *_data)
{
	do_and_print(_data, ps_rrb, FALSE);
	do_and_print(_data, ps_pa, FALSE);
}
