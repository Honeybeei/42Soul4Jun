/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:01:02 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/21 15:37:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	*atoi_arguments(int argc, char **argv)
{
	int		*num_arr;
	int		idx;

	num_arr = malloc(sizeof(int) * (argc - 1));
	if (num_arr == NULL)
		return (NULL);
	idx = 1;
	while (idx < argc)
	{
		if (check_is_num(argv[idx]) == invalid_)
		{
			free(num_arr);
			return (NULL);
		}
		num_arr[idx - 1] = ft_atoi(argv[idx]);
		idx++;
	}
	
}

check_is_num