/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:26:27 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 22:55:32 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	ft_strncmp(const char *_stra, const char *_strb, size_t _size)
{
	size_t	i;

	i = 0;
	while (i < _size && _stra[i] && _stra[i] == _strb[i])
		i++;
	if (i == _size)
		return (0);
	return ((unsigned char)_stra[i] - (unsigned char)_strb[i]);
}

void	bubblesort(t_list **_stack, int _len)
{
	int		i;
	int		j;
	void	*buff;
	t_list	*current;

	j = -1;
	if (_len == -1)
		_len = lstcount(_stack);
	while (++j < _len - 1)
	{
		current = *_stack;
		i = -1;
		while (++i < _len - 1 - j)
		{
			if (*((int *)current->content) > *((int *)current->next->content))
			{
				buff = current->content;
				current->content = current->next->content;
				current->next->content = buff;
			}
			current = current->next;
		}
	}
}

t_bool	set_to_indexes(t_list *_list, int _len)
{
	int		i;
	t_list	*temp_arr;
	t_list	*temp_list;

	if (_len == -1)
		_len = lstcount(&_list);
	temp_arr = (t_list *)malloc(_len * sizeof(t_list));
	if (!temp_arr)
		return (FALSE);
	i = -1;
	temp_list = NULL;
	while (++i < _len)
	{
		temp_arr[i].content = _list->content;
		lstadd_back(&temp_list, &temp_arr[i]);
		_list = _list->next;
	}
	bubblesort(&temp_list, _len);
	i = -1;
	while (++i < _len)
	{
		*((int *)temp_list->content) = i + 1;
		temp_list = temp_list->next;
	}
	return (free(temp_arr), TRUE);
}

unsigned char	*extend_buffer(unsigned char *_buff, int *_len)
{
	unsigned char	*out;
	int				i;

	out = (unsigned char *)malloc(*_len + 2048);
	if (!out)
		return (free(out), ft_ferror(NULL, "couldnt malloc!", -1), NULL);
	i = -1;
	while (++i < *_len)
		out[i] = _buff[i];
	*_len = *_len + 2048;
	out[*_len - 1] = 0;
	free(_buff);
	return (out);
}

t_bool	is_int32(char *_str)
{
	long long	num;
	int			i;
	int			is_negative;

	is_negative = 0;
	i = 0;
	if (_str[0] == '-')
	{
		is_negative = 1;
		i = 1;
	}
	num = 0;
	while (_str[i])
	{
		if (_str[i] > '9' || _str[i] < '0')
			return (FALSE);
		num = num * 10 + (_str[i++] - '0');
		if ((is_negative && - num < INT32_MIN)
			|| (!is_negative && num > INT32_MAX))
			return (FALSE);
	}
	return (TRUE);
}
