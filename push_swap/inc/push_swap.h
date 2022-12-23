/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:44:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/23 14:29:02 by seoyoo           ###   ########.fr       */
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
	invalid_
}	t_bool;

typedef struct s_node
{
	int				n_;
	struct s_node	*next_;
	struct s_node	*prev_;
}	t_nd;

typedef struct s_list
{
	t_nd	*head_;
	t_nd	*tail_;
	size_t	nd_cnt_;
}	t_list;

typedef struct s_stacks
{
	t_list	a_;
	t_list	b_;
}	t_stacks;



//	utils
//		makefile_test.c
void	say_hello(int n);

//		error_management.c
int		print_error(void);

//		atoi_arguments.c
int		*atoi_arguments(int argc, char **argv);
t_bool	check_duplication(int argc, int *arg_arr);

#endif