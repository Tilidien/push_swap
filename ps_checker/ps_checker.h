/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:55:20 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 22:55:47 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# include <unistd.h>
# include "get_next_line.h"

typedef char	t_bool;
# define FALSE 0
# define TRUE 1

typedef t_bool	(*t_hate)(void *);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_ps_data
{
	t_list			*stack_a;
	t_list			*stack_b;
	t_list			*lst_obj_pool;
	unsigned char	*instr;
	int				*numbers;
}	t_ps_data;

typedef struct s_atoi_vars
{
	int		out;
	char	sign;
	size_t	mul;
	int		i;
}	t_atoi_vars;

/// @brief sa (swap a): Swap the first 2 elements at the top of stack a.
/// Do nothing if there is only one or no elements.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_sa(void *_data);

/// @brief sb (swap b): Swap the first 2 elements at the top of stack b.
/// Do nothing if there is only one or no elements.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_sb(void *_data);

/// @brief ss : sa and sb at the same time.
/// @param _data pointer to a t_ps_data struct 
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_ss(void *_data);

/// @brief pa (push a): Take the first element 
/// at the top of b and put it at the top of a.
/// Do nothing if b is empty.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_pa(void *_data);

/// @brief pb (push b): Take the first element 
/// at the top of a and put it at the top of b.
/// Do nothing if a is empty.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_pb(void *_data);

/// @brief ra (rotate a): Shift up all elements of stack a by 1.
/// The first element becomes the last one.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_ra(void *_data);

/// @brief rb (rotate b): Shift up all elements of stack b by 1.
/// The first element becomes the last one.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_rb(void *_data);

/// @brief ra and rb at the same time.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_rr(void *_data);

/// @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_rra(void *_data);

/// @brief rrb (reverse rotate b): Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_rrb(void *_data);

/// @brief rrr : rra and rrb at the same time.
/// @param _data pointer to a t_ps_data struct
/// @return FALSE if the function cannot operate. TRUE if it operated.
t_bool				ps_rrr(void *_data);

void				ft_ferror(t_ps_data *_data_to_clear,
						char *_str, int _errno);

t_bool				set_to_indexes(t_list *_list, int _len);

void				lstdelone(t_list *_lst, void (*_del)(void *));
void				lstadd_back(t_list **_lst, t_list *_new);
/// @brief Adds element as first element to a linked list
/// @param _lst 
/// @param _new 
void				lstadd_front(t_list **_lst, t_list *_new);

/// @brief Clears an entire list and calls the function _del on its content
/// @param _lst pointer to the list
/// @param _del function to call on content.
void				lstclear(t_list **_lst, void (*_del)(void *));

/// @brief Counts the elements of a linked list
/// @param _lst 
/// @return Num of elements in list. 
size_t				lstcount(t_list **_lst);

/// @brief Removes first element from a given list.
/// @param _lst 
/// @return Returns a pointer to the element.
t_list				*lstpop(t_list **_lst);

int					ft_strncmp(const char *_stra,
						const char *_strb, size_t _size);

int					ft_atoi(const char *_str);
unsigned char		*extend_buffer(unsigned char *_buff, int *_len);
unsigned char		id_instruction(char *_instr);
t_hate				get_instr_from_id(unsigned char _id);
unsigned char		*get_instructions(void);
void				exec_instr(t_ps_data *_data);
t_bool				is_int32(char *_str);

#endif