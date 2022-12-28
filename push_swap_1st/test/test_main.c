/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:25:15 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/25 15:04:29 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_test.h"

int main(int argc, char **argv)
{
	int			*arg_arr;
	t_stacks	*stacks;

    printf("TESTING....\n");
	if (argc < 2)
		return (EXIT_FAILURE);
	arg_arr = atoi_arguments(argc, argv);	
	if (arg_arr == NULL)
		return (print_error());
	if (check_duplication(argc, arg_arr) == invalid_)
	{
		free(arg_arr);
		return (print_error());
	}
	stacks = init_t_stacks(arg_arr, argc);


	push_t_nd(stacks->b_, init_t_nd(10), top_);
	push_t_nd(stacks->b_, init_t_nd(14), top_);
	push_t_nd(stacks->b_, init_t_nd(12), top_);
	push_t_nd(stacks->b_, init_t_nd(13), top_);
	print_stacks(stacks);
	if (check_is_sorted(stacks->b_, asc_) == true)
		printf("Stack b is sorted in ascending order\n");
	sort_top3(stacks, b_, asc_);
	print_stacks(stacks);
	if (check_is_sorted(stacks->b_, asc_) == true)
		printf("Stack b is sorted in ascending order\n");
}