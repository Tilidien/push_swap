/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:00:13 by tgmelin           #+#    #+#             */
/*   Updated: 2024/03/16 14:44:33 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_memcpy(char *_dst, char *_src, size_t _size)
{
	size_t	i;

	if (_size == SIZE_MAX)
	{
		_dst++[0] = _src++[0];
		_size--;
	}
	i = 0;
	while (i < _size)
	{
		_dst[i] = _src[i];
		i++;
	}
}

ssize_t	ft_memchr(char *_buffer, char _c, ssize_t _size)
{
	ssize_t	i;

	i = 0;
	while (i < _size && _buffer[i] != _c)
	{
		i++;
	}
	if (_buffer[i] == _c)
		return (i);
	return (-1);
}

void	ft_memclr(char *_mem, size_t _size)
{
	while (_size)
	{
		*_mem++ = 0;
		_size--;
	}
}
