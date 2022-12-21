/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:44:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/21 15:03:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries for external functions
#include <stdio.h>

#include "../my_lib/inc/libft.h"

typedef enum e_my_booleans
{
	valid_ = 0,
	invalid_
}	t_bool;

//	utils
//		makefile_test.c
void	say_hello(int n);

//		error_management.c
int		print_error(void);

//		atoi_arguments.c
int	*atoi_arguments(int argc, char **argv);


#endif