/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:25:15 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/27 20:32:07 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_test.h"

int	main(int argc, char **argv)
{
	int			*arg_arr;
	t_stacks	stacks;

	printf("\n\nTESTING......\n\n");
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
	print_stacks(&stacks);
	push_args_to_stack(&stacks, arg_arr, argc);
	free(arg_arr);
	print_stacks(&stacks);
	// sort(stacks);
	push_swap_termination(&stacks);
	return (0);
}
