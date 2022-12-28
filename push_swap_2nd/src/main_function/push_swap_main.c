/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:37:18 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/27 20:21:51 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

#include <stdio.h>  // TEST

int	main(int argc, char **argv)
{
	int			*arg_arr;
	t_stacks	stacks;

	if (argc < 2)
		return (EXIT_FAILURE);
	arg_arr = atoi_arguments(argc, argv);
	if (arg_arr == NULL)
		print_error_and_exit();
	if (check_duplication(argc, arg_arr) == invalid_)
	{
		free(arg_arr);
		print_error_and_exit();
	}
	push_swap_init(&stacks);
	push_args_to_stack(&stacks, arg_arr, argc);
	free(arg_arr);
	// sort(stacks);
	push_swap_termination(&stacks);
	return (0);
}
