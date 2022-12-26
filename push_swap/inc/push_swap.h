/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:44:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/26 22:31:45 by seoyoo           ###   ########.fr       */
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

# define INIT_CHUNK_SIZE

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
	top_ = 1,
	btm_ = -1,
	up_ = 1,
	down_ = -1,
	asc_ = 1,
	desc_ = -1
}	t_dir;

typedef enum e_stack_id
{
	a_ = -1,
	both_,
	b_
}	t_s_id;

/* ************************************************************************** */

typedef struct s_node
{
	int				n_;
	struct s_node	*next_;
	struct s_node	*prev_;
}	t_nd;

typedef struct s_chunk
{
	t_nd			*btm_;
	t_nd			*top_;
	size_t			nd_cnt_;
	struct s_chunk	*next_;
	struct s_chunk	*prev_;
}	t_chunk;

typedef struct s_chunk_list
{
	t_chunk	*btm_;
	t_chunk	*top_;
	size_t	chunk_cnt_;
}	t_ch_list;

typedef struct s_stack
{
	t_nd		*top_;
	t_nd		*btm_;
	size_t		nd_cnt_;
	t_s_id		id_;
	t_ch_list	*ch_lst_;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a_;
	t_stack	*b_;
}	t_stacks;

/* ************************************************************************** */

//	operations
//		push_rules.c
void		op_push(t_stacks *stacks, t_s_id target_stack);
void		op_push_n(t_stacks *stacks, t_s_id target_stack, int n);

//		rotate_rules.c
void		op_rotate(t_stacks *stacks, t_s_id target_stack, t_dir shift_dir);

//		swap_rules.c
void		op_swap(t_stacks *stacks, t_s_id target_stack);

/* ************************************************************************** */

//	sorting

//		check_order.c
bool		check_is_sorted(t_stack *stack, t_dir order);

//		sort.c
void		sort(t_stacks *stacks);
void		sort_top2(t_stacks *stacks, t_s_id target_stack, t_dir order);
void		sort_top3(t_stacks *stacks, t_s_id target_stack, t_dir order);

//		

/* ************************************************************************** */

//	utils
//		error_management.c
int			print_error(void);

//		get_arguments.c
int			*atoi_arguments(int argc, char **argv);
t_bool		check_duplication(int argc, int *arg_arr);

//		object_management_1.c
t_nd		*init_t_nd(int n);
void		*terminate_t_nd(t_nd *del_node);
t_stack		*init_t_stack(t_s_id stack_id);
void		*terminate_t_stack(t_stack *del_list);
t_stacks	*init_t_stacks(int *arg_arr, int argc);

//		object_management_2.c
void		*terminate_t_stacks(t_stacks *stacks);
t_nd		*pick_t_nd(t_stack *stack, t_dir from);
t_stack		*push_t_nd(t_stack *stack, t_nd *node, t_dir to);

//		object_management_3.c
t_stack		*get_stack(t_stacks *stacks, t_s_id stack_id);
t_chunk		*init_t_chunk(void);
void		*terminate_t_chunk(t_chunk *del_chunk);
t_ch_list	*init_t_ch_list(void);
void		*terminate_t_ch_list(t_ch_list *del_list);

/* ************************************************************************** */

#endif