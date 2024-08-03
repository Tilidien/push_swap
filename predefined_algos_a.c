/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predefined_algos_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:14:56 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 20:36:54 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	predef_alg_samestack_2_1(void *_data)
{
	do_and_print(_data, ps_sa, FALSE);
}

void	predef_alg_samestack_3_0(void *_data)
{
	_data = NULL;
}

void	predef_alg_samestack_3_1(void *_data)
{
	do_and_print(_data, ps_ra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_rra, FALSE);
}

void	predef_alg_samestack_3_2(void *_data)
{
	do_and_print(_data, ps_sa, FALSE);
}

void	predef_alg_samestack_3_3(void *_data)
{
	do_and_print(_data, ps_ra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
	do_and_print(_data, ps_rra, FALSE);
	do_and_print(_data, ps_sa, FALSE);
}
