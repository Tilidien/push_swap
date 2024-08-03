/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:42:34 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/04 00:22:16 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_bool	parse_input(int _argc, char *_argv[], int *_numbers, t_list *_stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < _argc - 1)
	{
		_stack[i].content = _numbers + i;
		if (!is_int32(_argv[i + 1]))
			return (FALSE);
		_numbers[i] = ft_atoi(_argv[i + 1]);
		j = 0;
		while (j < i)
		{
			if (_numbers[i] == _numbers[j++])
				return (FALSE);
		}
	}
	return (TRUE);
}

static void	ft_memset(void *_mem, int _len, unsigned char _toset)
{
	unsigned char	*mem;

	mem = (unsigned char *)_mem;
	while (--_len >= 0)
	{
		mem[_len] = _toset;
	}
}

int	main(int _argc, char *_argv[])
{
	t_ps_data	stacks;

	ft_memset(&stacks, sizeof(t_ps_data), 0);
	ft_ferror(&stacks, NULL, 0);
	if (_argc < 2)
		return (write(2, "Error\n", 6), -1);
	stacks.numbers = (int *)malloc(sizeof(int) * _argc - sizeof(int));
	if (!stacks.numbers)
		return (write(2, "Error\n", 6), -1);
	stacks.lst_obj_pool = (t_list *)malloc(sizeof(t_list)
			* _argc - sizeof(t_list));
	if (!stacks.lst_obj_pool)
		return (free(stacks.numbers), write(2, "Error\n", 6), -1);
	if (!parse_input(_argc, _argv, stacks.numbers, stacks.lst_obj_pool))
		return (free(stacks.numbers), free(stacks.lst_obj_pool),
			write(2, "Error\n", 6), -1);
	while (--_argc > 0)
		lstadd_front(&stacks.stack_a, &stacks.lst_obj_pool[_argc - 1]);
	set_to_indexes(stacks.stack_a, -1);
	quicksort(&stacks);
	ft_ferror(NULL, "", 0);
	return (0);
}
