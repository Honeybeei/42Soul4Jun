/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_test_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:11:42 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/01 18:38:22 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_var_list(t_var_lst *list)
{
	t_var_nd	*ptr;

	ptr = list->head_;
	while (ptr != NULL)
	{
		printf("%s = %s\n", ptr->name_, ptr->val_);
		ptr = ptr->next_;
	}
}

int main(int argc, char **argv, char **envp)
{
	printf("\n\nEntered Testing area\n\n");

	(void)argc;
	(void)argv;
	init_ptrs(&g_ptrs, envp);
	print_var_list(&g_ptrs.variable_list_);
	
	return (0);
}