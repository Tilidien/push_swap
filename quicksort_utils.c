/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:13:35 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 18:55:06 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	revert_rotate_instr(t_ps_data *_data, t_qs_block *_block)
{
	if (lstcount(&_data->blocklist_a) == 1 && (_block->rotate_instr == ps_ra
			|| _block->rotate_instr == ps_rra))
		_block->rotate_instr = ps_ra;
	else if (lstcount(&_data->blocklist_b) == 1
		&& (_block->rotate_instr == ps_rb
			|| _block->rotate_instr == ps_rrb))
		_block->rotate_instr = ps_rb;
	else if (_block->rotate_instr == ps_ra)
		_block->rotate_instr = ps_rra;
	else if (_block->rotate_instr == ps_rra)
		_block->rotate_instr = ps_ra;
	else if (_block->rotate_instr == ps_rb)
		_block->rotate_instr = ps_rrb;
	else if (_block->rotate_instr == ps_rrb)
		_block->rotate_instr = ps_rb;
}

t_qs_block	*new_block_from_block(t_split_block_input *_in)
{
	t_qs_block	*new_block;
	t_qs_block	*old_block;

	old_block = (t_qs_block *)_in->block;
	new_block = (t_qs_block *)malloc(sizeof(t_qs_block));
	if (!new_block)
		ft_ferror(NULL, "split_block: malloc returned 0!\n", -1);
	if (_in->smaller_instr == ps_pa || _in->greatereq_instr == ps_pa)
	{
		new_block->max = old_block->max;
		old_block->max = old_block->min + (old_block->max - old_block->min) / 2;
		new_block->min = old_block->max + 1;
	}
	else
	{
		new_block->min = old_block->min;
		new_block->max = old_block->min + (old_block->max - old_block->min) / 2;
		old_block->min = new_block->max + 1;
	}
	new_block->sorted = FALSE;
	new_block->rotate_instr = ps_rb;
	if (_in->smaller_instr == ps_pa || _in->greatereq_instr == ps_pa)
		new_block->rotate_instr = ps_ra;
	revert_rotate_instr(_in->ps_data, old_block);
	return (new_block);
}

t_bool	lst_range(t_list **_lst, int min, int max)
{
	t_list *current;

	current = *_lst;
	while (current)
	{
		if (*((int *)current->content) >= min
			&& *((int *)current->content) <= max)
			return (TRUE);
		current = current->next;
		if (current == *_lst)
			break ;
	}
	return (FALSE);
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
