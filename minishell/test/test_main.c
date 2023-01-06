/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:11:42 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 19:44:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	printf("\n\nEntered Testing area\n\n");

	t_var_lst lst;

	initialize_var_lst(&lst);
	push_var_to_lst(&lst, "Hello", "world");
	push_var_to_lst(&lst, "Helloa", "worlda");
	push_var_to_lst(&lst, "Hello", "world");
	push_var_to_lst(&lst, "Hello", "world");
	printf("%s : %s, %zu", lst.head_->name_, lst.head_->val_, lst.var_cnt_);
	return (0);
}
