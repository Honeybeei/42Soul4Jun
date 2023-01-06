/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:13:37 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 22:20:45 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Starting function for minishell. First, it prints banner of the 
 * minishell and initialize signals and g_ptrs(global variable). Lastly, it 
 * converts all envp to t_var and push in to t_var_lst. 
 * 
 * @param envp 
 */
void	start_shell(char **envp)
{
	size_t	i;

	printf("%s", ENTRANCE_ASCII);
	handle_signals();
	initialize_global_variable(envp);
	

}

/* ************************************************************************** */

void	handle_signals(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= (ICANON | ECHO);
	
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	// https://www.it-note.kr/209
}

/* ************************************************************************** */


/* ************************************************************************** */


/* ************************************************************************** */

/* ************************************************************************** */