/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:37:18 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/24 18:28:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

# include <stdio.h>

int main(int argc, char **argv)
{
	int			*arg_arr;
	t_stacks	*stacks;

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
	free(arg_arr);
	// sort
	// terminate all
	
}