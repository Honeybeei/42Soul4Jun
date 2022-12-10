/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:43:19 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/09 22:44:38 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	say_hello(int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		printf("Hello world!\n");
		idx++;
	}
	return ;
}