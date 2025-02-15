/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:54:54 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/04 00:32:37 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_block(t_split_block_input *_in)
{
	int		i;
	int		pivot;
	int		elem;
	t_bool	rev;

	rev = _in->block->rotate_instr == ps_rra
		|| _in->block->rotate_instr == ps_rrb;
	pivot = _in->block->min + (_in->block->max - _in->block->min) / 2;
	i = -1;
	while (++i + _in->block->min <= _in->block->max)
	{
		elem = *(int *)(_in->src_stack[0]->content);
		if (rev)
			elem = *(int *)(_in->src_stack[0]->prev->content);
		if (elem > pivot)
			do_and_print(_in->ps_data, _in->greatereq_instr, rev);
		else
			do_and_print(_in->ps_data, _in->smaller_instr, rev);
	}
	lstadd_front(_in->dst_blocklist,
		lst_new_elem_freeonfail(new_block_from_block(_in)));
}

static void	split_block_stub(t_ps_data *_data, t_qs_block *_block)
{
	t_split_block_input	in;

	if (_block->rotate_instr == ps_rrb || _block->rotate_instr == ps_rb)
	{
		in.smaller_instr = _block->rotate_instr;
		in.greatereq_instr = ps_pa;
		in.src_stack = &_data->stack_b;
		in.dst_blocklist = &_data->blocklist_a;
	}
	else
	{
		in.smaller_instr = ps_pb;
		in.greatereq_instr = _block->rotate_instr;
		in.src_stack = &_data->stack_a;
		in.dst_blocklist = &_data->blocklist_b;
	}
	in.block = _block;
	in.ps_data = _data;
	split_block(&in);
}

static t_qs_block	*split_next_block(t_ps_data *_data)
{
	t_qs_block	*current;

	current = (t_qs_block *)_data->blocklist_a->content;
	if (current->sorted)
		current = (t_qs_block *)_data->blocklist_b->content;
	if (current->max - current->min < PREDEFINED_ALGOS_LEN)
		return (current);
	return (split_block_stub(_data, current), NULL);
}

static t_bool	unsorted_blocks_remain(t_ps_data *_data)
{
	t_list	*current;

	current = _data->blocklist_a;
	while (current)
	{
		if (!((t_qs_block *)current->content)->sorted)
			return (TRUE);
		current = current->next;
		if (current == _data->blocklist_a)
			break ;
	}
	current = _data->blocklist_b;
	while (current)
	{
		if (!((t_qs_block *)current->content)->sorted)
			return (TRUE);
		current = current->next;
		if (current == _data->blocklist_b)
			break ;
	}
	return (FALSE);
}

void	quicksort(t_ps_data *_data)
{
	t_qs_block	*current;
	t_qs_block	*block;

	block = (t_qs_block *)malloc(sizeof(t_qs_block));
	if (!block)
		ft_ferror(NULL, "qicksort couldnt malloc", -1);
	block->min = 1;
	block->max = lstcount(&_data->stack_a);
	block->rotate_instr = ps_ra;
	block->sorted = FALSE;
	lstadd_front(&_data->blocklist_a, lst_new_elem(block));
	while (unsorted_blocks_remain(_data))
	{
		current = NULL;
		while (!current)
			current = split_next_block(_data);
		do_algo_for_block(_data, current);
		if (current->rotate_instr == ps_rb || current->rotate_instr == ps_rrb)
			lstdelone(lstpop(&_data->blocklist_b), free);
	}
}
