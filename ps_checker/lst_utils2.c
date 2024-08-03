/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:02:31 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 22:40:13 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

t_list	*lstpop(t_list **_lst)
{
	t_list	*out;

	out = *_lst;
	if (!out)
		return (NULL);
	if (out->next == out)
	{
		*_lst = NULL;
		out->next = NULL;
		out->prev = NULL;
		return (out);
	}
	out->next->prev = out->prev;
	out->prev->next = out->next;
	*_lst = out->next;
	out->next = NULL;
	out->prev = NULL;
	return (out);
}
