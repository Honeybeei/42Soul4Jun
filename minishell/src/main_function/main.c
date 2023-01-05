/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:28:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/05 14:51:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	start_shell();  // TODO : signal handler should be managed here. 
	init_ptrs(&g_ptrs, envp);	// Finished -> but I think it should be moved to start_shell. All the initial process will be done at start_shell function. 
	while (true)
	{
		g_ptrs.user_input_ = get_input_from_user();  // Finished
		tokenize_user_input(&g_ptrs.token_list_, g_ptrs.user_input_);  // TODO
		if (convert_tkn_lst_to_cmd_arr(&g_ptrs.token_list_, &g_ptrs.cmd_arr_) == success_)  // TODO
			execute_commands(&g_ptrs.cmd_arr_);  // TODO
		clear_loop(&g_ptrs);
	}
	termination_ptcl(&g_ptrs);  // Finished -> reallY?
	return (0);
}

/* ************************************************************************** */