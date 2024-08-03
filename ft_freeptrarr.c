/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeptrarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:03:50 by tgmelin           #+#    #+#             */
/*   Updated: 2024/07/29 14:47:01 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freeptrarr(char **_arr)
{
	int	i;

	i = 1;
	while (_arr[i])
		free(_arr[i++]);
	free(_arr);
}
