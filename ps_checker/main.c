/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:53:31 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/04 00:32:01 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

t_bool	completion_test(t_ps_data *_data)
{
	int		last_int;
	int		cur_int;
	t_list	*current;

	if (lstcount(&_data->stack_b))
		return (FALSE);
	last_int = -1;
	current = _data->stack_a;
	while (current)
	{
		cur_int = *(int *)current->content;
		if (cur_int <= last_int)
			return (FALSE);
		current = current->next;
		if (current == _data->stack_a)
			break ;
		last_int = cur_int;
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

t_bool	check(t_ps_data	*_data)
{
	_data->instr = get_instructions();
	if (!_data->instr || !_data->instr[0])
		return (FALSE);
	exec_instr(_data);
	return (completion_test(_data));
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
	if (check(&stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_ferror(NULL, "", 0);
	return (0);
}
