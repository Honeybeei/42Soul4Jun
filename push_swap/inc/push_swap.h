/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:44:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/23 16:18:44 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries for external functions
#include <stdio.h>  // TEST

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
	btm_ = -1
}	t_dir;

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

//		makefile_test.c
void		say_hello(int n);

//		object_management_1.c
t_nd		*init_t_nd(int n);
void		*terminate_t_nd(t_nd *del_node);
t_stack		*init_t_stack(void);
void		*terminate_t_stack(t_stack *del_list);
t_stacks	*init_t_stacks(void);

//		object_management_2.c
void		*terminate_t_stacks(t_stacks *stacks);
t_nd		*pick_t_nd(t_stack *stack, t_dir from);
t_stack		*push_t_nd(t_stack *stack, t_nd *node, t_dir to);

#endif