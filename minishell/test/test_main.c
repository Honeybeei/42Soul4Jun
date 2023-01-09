/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:11:42 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/09 17:33:52 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	// (void)envp;
	printf("\n\nEntered Testing area\n\n");

	initialize_global_variable(envp);
	char *user_input = " < > ||| << >> \"\" \"\'\"";
	split_input_to_tokens(user_input, &g_ptrs.tkn_lst_);
	print_token_list(&g_ptrs.tkn_lst_);
	// printf("\n\n\n\n\n\n\n");
	convert_variables(&g_ptrs.tkn_lst_);
	print_token_list(&g_ptrs.tkn_lst_);
	convert_quoted_strings(&g_ptrs.tkn_lst_);	//	TODO
	print_token_list(&g_ptrs.tkn_lst_);
}
