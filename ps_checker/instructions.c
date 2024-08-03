/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:52:37 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 22:54:08 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

unsigned char	id_instruction(char *_instr)
{
	if (!ft_strncmp(_instr, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(_instr, "sb\n", 3))
		return (2);
	else if (!ft_strncmp(_instr, "ss\n", 3))
		return (3);
	else if (!ft_strncmp(_instr, "pa\n", 3))
		return (4);
	else if (!ft_strncmp(_instr, "pb\n", 3))
		return (5);
	else if (!ft_strncmp(_instr, "ra\n", 3))
		return (6);
	else if (!ft_strncmp(_instr, "rb\n", 3))
		return (7);
	else if (!ft_strncmp(_instr, "rr\n", 3))
		return (8);
	else if (!ft_strncmp(_instr, "rra\n", 3))
		return (9);
	else if (!ft_strncmp(_instr, "rrb\n", 3))
		return (10);
	else if (!ft_strncmp(_instr, "rrr\n", 3))
		return (11);
	else
		return (0);
}

t_hate	get_instr_from_id(unsigned char _id)
{
	if (_id == 1)
		return (ps_sa);
	else if (_id == 2)
		return (ps_sb);
	else if (_id == 3)
		return (ps_ss);
	else if (_id == 4)
		return (ps_pa);
	else if (_id == 5)
		return (ps_pb);
	else if (_id == 6)
		return (ps_ra);
	else if (_id == 7)
		return (ps_rb);
	else if (_id == 8)
		return (ps_rr);
	else if (_id == 9)
		return (ps_rra);
	else if (_id == 10)
		return (ps_rrb);
	else if (_id == 11)
		return (ps_rrr);
	else
		return (NULL);
}

unsigned char	*get_instructions(void)
{
	char			*current;
	int				len;
	int				i;
	unsigned char	*instructions;

	i = 0;
	len = 0;
	current = get_next_line(STDIN_FILENO);
	instructions = NULL;
	while (current)
	{
		if (i >= len - 1)
			instructions = extend_buffer(instructions, &len);
		instructions[i] = id_instruction(current);
		if (!instructions[i])
			return (free(current), free(instructions),
				ft_ferror(NULL, "Error\n", -1), NULL);
		free(current);
		current = get_next_line(STDIN_FILENO);
		i++;
	}
	instructions[i] = 0;
	return (instructions);
}

void	exec_instr(t_ps_data *_data)
{
	int		i;

	t_bool (*instr)(void *);
	i = -1;
	while (_data->instr[++i])
	{
		instr = get_instr_from_id(_data->instr[i]);
		if (!instr)
			ft_ferror(NULL, "ERROR UNKNOWN INSTRUCTION IN ARRAY?!?\n", -404);
		instr(_data);
	}
}
