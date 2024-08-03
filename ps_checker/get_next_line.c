/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:39:04 by tgmelin           #+#    #+#             */
/*   Updated: 2024/03/16 16:00:46 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_bool	extend_buffer(char **_buffer, ssize_t *_size, int _fd)
{
	char	*out;

	if (_fd > 1024 || _fd < 0)
		return (FALSE);
	if (*_size > *_size * 2)
		return (free(*_buffer), FALSE);
	if (!*_size)
	{
		*_size = 1024;
		if (BUFFER_SIZE > 1024)
			*_size = BUFFER_SIZE * 2;
		*_buffer = (char *)malloc(*_size);
		return (!!*_buffer);
	}
	out = (char *)malloc(*_size * 2);
	if (!out)
	{
		free(*_buffer);
		return (FALSE);
	}
	ft_memcpy(out, *_buffer, *_size);
	_size[0] *= 2;
	free(*_buffer);
	return (*_buffer = out, TRUE);
}

static char	*shrink_and_terminate(char *_buffer, size_t _strlen)
{
	char	*out;

	out = (char *)malloc(_strlen + 1);
	if (!out)
	{
		free(_buffer);
		return (NULL);
	}
	ft_memcpy(out, _buffer, _strlen);
	out[_strlen] = 0;
	free(_buffer);
	return (out);
}

static t_bool	line_ended( t_gnl_vars *_v)
{
	ssize_t	i;

	if (!_v->bytes_newly_read && !_v->init)
		return (_v->endl = 0, TRUE);
	i = 0;
	while (i < _v->bytes_newly_read)
	{
		if (_v->out[_v->bytes_read + i++] == '\n')
			return (_v->endl = i, TRUE);
	}
	if (_v->bytes_newly_read < BUFFER_SIZE && !_v->init)
		return (_v->endl = _v->bytes_newly_read, TRUE);
	if (_v->init)
		_v->init = 0;
	return (FALSE);
}

char	*get_next_line(int _fd)
{
	static t_gnl_buffer	perm;
	t_gnl_vars			v;

	v.out_size = 0;
	v.bytes_read = 0;
	v.init = 1;
	if (!extend_buffer(&v.out, &v.out_size, _fd))
		return (NULL);
	ft_memcpy(v.out, perm.buffer[_fd], perm.len[_fd]);
	v.bytes_newly_read = perm.len[_fd];
	while (!line_ended(&v))
	{
		v.bytes_read += v.bytes_newly_read;
		if (v.out_size < v.bytes_read + BUFFER_SIZE)
			if (!extend_buffer(&v.out, &v.out_size, _fd))
				return (NULL);
		v.bytes_newly_read = read(_fd, &v.out[v.bytes_read], BUFFER_SIZE);
		if (v.bytes_newly_read == -1 || (!v.bytes_newly_read && !v.bytes_read))
			return (free(v.out), perm.len[_fd] = 0,
				ft_memclr(&perm.buffer[_fd][0], BUFFER_SIZE), (NULL));
	}
	ft_memcpy(perm.buffer[_fd], &v.out[v.bytes_read + v.endl],
		v.bytes_newly_read - v.endl);
	perm.len[_fd] = v.bytes_newly_read - v.endl;
	return (shrink_and_terminate(v.out, v.bytes_read + v.endl));
}
