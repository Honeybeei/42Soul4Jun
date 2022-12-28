/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:44:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/28 14:46:16 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */

// Libraries for external functions
# include <stddef.h>  				// size_t
# include <stdbool.h>				// true, false
# include "../my_lib/inc/libft.h"

/* ************************************************************************** */

# define ERR_MSG_ "Error\n"

typedef enum e_my_booleans
{
	valid_ = 0,
	invalid_,
	success_ = 0,
	fail_,
	sorted_ = 0,
	not_sorted_
}	t_bool;

typedef enum e_directions
{
	btm_ = -1,
	top_ = 1,
	head_ = -1,
	tail_ = 1
}	t_dir;

typedef	enum e_sorting_order
{
	asc_ = -1,
	desc_ = 1
}	t_order;

typedef enum e_stack_id
{
	a_ = -1,
	both_,
	b_
}	t_s_id;

/* ************************************************************************** */

// head == btm | node -> node -> .... -> node | tail == top
typedef struct s_node
{
	int				n_;
	struct s_node	*next_;
	struct s_node	*prev_;
}	t_nd;

typedef struct s_chunk
{
	t_nd			*head_;
	t_nd			*tail_;
	size_t			nd_cnt_;
	struct s_chunk	*next_;
	struct s_chunk	*prev_;
}	t_chunk;

// head is bottom of the stack and tail is top of the stack
typedef struct s_chunk_list
{
	t_chunk	*head_;
	t_chunk	*tail_;
	size_t	ch_cnt_;
}	t_ch_lst;

typedef struct s_stacks
{
	t_ch_lst	b_;
	t_ch_lst	a_;
}	t_stacks;

/* ************************************************************************** */

//	operations
//		swap.c
t_bool		op_swap(t_stacks *stacks, t_s_id s_id);

/* ************************************************************************** */

//	sorting
//		sort_main.c
void		push_args_to_stack(t_stacks *stacks, int *arg_arr, int argc);
void		sort(t_stacks *stacks);

/* ************************************************************************** */

//	utils
//		error_management.c
void		print_error_and_exit(void);

//		get_objects.c
t_ch_lst	*get_stack(t_stacks *stacks, t_s_id s_id);
t_chunk		*get_chunk(t_stacks *stacks, t_s_id s_id, t_dir top_or_btm);
size_t		get_nd_cnt(t_stacks *stacks, t_s_id s_id);

//		object_management_1.c
t_nd		*make_node(int n);
void		*terminate_node(t_nd *del_node);
t_chunk		*make_chunk(void);
void		*terminate_chunk(t_chunk *del_chunk);
void		clear_chunk_list(t_ch_lst *list);

//		object_management_2.c
void		push_swap_init(t_stacks *stacks);
void		push_swap_termination(t_stacks *stacks);
void		push_chunk(t_chunk *chunk, t_ch_lst *list, t_dir dst);
t_chunk		*pick_chunk(t_ch_lst *list, t_dir src);

//		object_management_3.c
void		pop_chunk(t_ch_lst *list, t_dir src);
void		push_node(t_nd *node, t_chunk *chunk, t_dir dst);
t_nd		*pick_node(t_chunk *chunk, t_dir src);
void		pop_node(t_chunk *chunk, t_dir src);

//		parse_arguments.c
int			*atoi_arguments(int argc, char **argv);
t_bool		check_duplication(int argc, int *arg_arr);

/* ************************************************************************** */

#endif