/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:10:24 by tgmelin           #+#    #+#             */
/*   Updated: 2024/08/03 23:02:57 by tgmelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h> //size_t
# include <stdlib.h> // malloc, free
# include <stdio.h>
# define PREDEFINED_ALGOS_LEN 3

typedef char	t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_ps_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*blocklist_a;
	t_list	*blocklist_b;
	int		*numbers;
	t_list	*lst_obj_pool;
}	t_ps_data;

typedef struct s_atoi_vars
{
	int		out;
	char	sign;
	size_t	mul;
	int		i;
}	t_atoi_vars;

typedef struct s_qs_block
{
	unsigned int	min;
	unsigned int	max;
	t_bool			(*rotate_instr)(void *);
	t_bool			sorted;
}	t_qs_block;

typedef struct s_split_block_input
{
	t_bool		(*smaller_instr)(void *);
	t_bool		(*greatereq_instr)(void *);
	t_list		**src_stack;
	t_qs_block	*block;
	t_list		**dst_blocklist;
	t_ps_data	*ps_data;
}	t_split_block_input;

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

void				predef_alg_samestack_2_1(void *_data);
void				predef_alg_samestack_3_0(void *_data);
void				predef_alg_samestack_3_1(void *_data);
void				predef_alg_samestack_3_2(void *_data);
void				predef_alg_samestack_3_3(void *_data);
void				predef_alg_samestack_3_4(void *_data);
void				predef_alg_samestack_3_5(void *_data);
void				predef_alg_samestack_rev_2_0(void *_data);
void				predef_alg_samestack_rev_2_1(void *_data);
void				predef_alg_samestack_rev_3_0(void *_data);
void				predef_alg_samestack_rev_3_1(void *_data);
void				predef_alg_samestack_rev_3_2(void *_data);
void				predef_alg_samestack_rev_3_3(void *_data);
void				predef_alg_samestack_rev_3_4(void *_data);
void				predef_alg_samestack_rev_3_5(void *_data);
void				predef_alg_diffstack_2_0(void *_data);
void				predef_alg_diffstack_2_1(void *_data);
void				predef_alg_diffstack_3_0(void *_data);
void				predef_alg_diffstack_3_1(void *_data);
void				predef_alg_diffstack_3_2(void *_data);
void				predef_alg_diffstack_3_3(void *_data);
void				predef_alg_diffstack_3_4(void *_data);
void				predef_alg_diffstack_3_5(void *_data);
void				predef_alg_diffstack_rev_2_0(void *_data);
void				predef_alg_diffstack_rev_2_1(void *_data);
void				predef_alg_diffstack_rev_3_0(void *_data);
void				predef_alg_diffstack_rev_3_1(void *_data);
void				predef_alg_diffstack_rev_3_2(void *_data);
void				predef_alg_diffstack_rev_3_3(void *_data);
void				predef_alg_diffstack_rev_3_4(void *_data);
void				predef_alg_diffstack_rev_3_5(void *_data);
void				diffstack_solo(void *_data);
t_bool				do_and_print(void *_data,
						t_bool (*_instr)(void *_data), t_bool _rev);
int					ft_atoi(const char *_str);

/// @brief splits a string arround given delimiter. 
/// @param _s string to split
/// @param _c delimiter to split arround
/// @return returns a null terminated string array
char				**ft_split(const char *_s, char _c);

/// @brief Gets the length of a c-string
/// @param _str 
/// @return length of the string
size_t				ft_strlen(const char *_str);

/// @brief finds length of a zero terminated pointer array
/// @param _arr 
/// @return 
size_t				ft_arrlen(char *_arr[]);

/// @brief frees a zero terminated char pointer array
/// @param _arr 
void				ft_freeptrarr(char **_arr);

/// @brief copies _count bytes from _src buffer to _dst buffer
/// @param _dst Destination Buffer
/// @param _src Source Buffer
/// @param _count Size to copy
/// @return _dst
void				*ft_memcpy(void *_dst, const void *_src, size_t _count);
unsigned int		find_permutation_rank(t_list *_lst, int _len, t_bool _rev);
void				ft_ferror(t_ps_data *_data_to_clear,
						char *_str, int _errno);
t_bool				set_to_indexes(t_list *_list, int _len);
t_qs_block			*new_block_from_block(t_split_block_input *_in);
void				quicksort(t_ps_data *_data);
void				do_algo_for_block(t_ps_data *_data, t_qs_block *_block);
void				bubblesort(t_list **_stack, int _len);
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

/// @brief Creates a new lst_element with given content. next & prev set to 0;
/// @param _content 
/// @return New Element
t_list				*lst_new_elem(void *_content);

/// @brief Removes first element from a given list.
/// @param _lst 
/// @return Returns a pointer to the element.
t_list				*lstpop(t_list **_lst);
t_list				*lst_new_elem_freeonfail(void *_content);

#endif //PUSH_SWAP_H