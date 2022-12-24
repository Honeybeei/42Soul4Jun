/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:44:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/24 19:32:59 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries for external functions
# include <stddef.h>  				// size_t
# include "../my_lib/inc/libft.h"

typedef enum e_my_booleans
{
	valid_ = 0,
	invalid_,
	success_ = 0,
	fail_
}	t_bool;

typedef enum e_directions
{
	top_ = 1,
	btm_ = -1,
	up_ = 1,
	down_ = -1
}	t_dir;

typedef enum e_stack_id
{
	a_ = -1,
	both_,
	b_
}	t_s_id;

typedef struct s_node
{
	int				n_;
	struct s_node	*next_;
	struct s_node	*prev_;
}	t_nd;

typedef struct s_stack
{
	t_nd	*top_;
	t_nd	*btm_;
	size_t	nd_cnt_;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a_;
	t_stack	*b_;
}	t_stacks;

//	utils
//		error_management.c
int			print_error(void);

//		get_arguments.c
int			*atoi_arguments(int argc, char **argv);
t_bool		check_duplication(int argc, int *arg_arr);

//		object_management_1.c
t_nd		*init_t_nd(int n);
void		*terminate_t_nd(t_nd *del_node);
t_stack		*init_t_stack(void);
void		*terminate_t_stack(t_stack *del_list);
t_stacks	*init_t_stacks(int *arg_arr, int argc);

//		object_management_2.c
void		*terminate_t_stacks(t_stacks *stacks);
t_nd		*pick_t_nd(t_stack *stack, t_dir from);
t_stack		*push_t_nd(t_stack *stack, t_nd *node, t_dir to);

//	operations
//		push_rules.c
void		op_push(t_stacks *stacks, t_s_id target_stack);

//		rotate_rules.c
void		op_rotate(t_stacks *stacks, t_s_id target_stack, t_dir shift_dir);

//		swap_rules.c
void		op_swap(t_stacks *stacks, t_s_id target_stack);
#endif