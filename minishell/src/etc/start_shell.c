/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:13:37 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 13:06:00 by seoyoo           ###   ########.fr       */
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
	print_banner();
	initialize_global_variable(envp);
	// handle_signals();	// TODO!!
}

/* ************************************************************************** */

/**
 * @brief Print the banner of JSH. 
 * 
 */
void	print_banner(void)
{
	char	*str;
	char	*author;
	size_t	i;
	int		color_i;

	str = BANNER_ASCII_STR;
	author = "\033[0;90m jjin & seoyoo\033[0m";
	i = 0;
	color_i = 0;
	while (str[i] != '\0')
	{
		printf("\033[0;9%dm", color_i++ % 8);
		printf("%c", str[i++]);
		printf("\033[0m");
		if (str[i] == '\n')
			color_i = 0;
	}
	i = 0;
	while (i < 80 - ft_strlen(author))
	{
		printf(" ");
		i++;
	}
	printf("%s\n", author);
}

/* ************************************************************************** */

/**
 * @brief Initialize lists and pointers in global variable. 
 * 
 * @param envp 
 */
void	initialize_global_variable(char **envp)
{
	g_ptrs.envp_ = envp;
	g_ptrs.errno_ = errno_no_errors_;
	g_ptrs.exit_status_ = 0;
	initialize_var_lst(&g_ptrs.var_lst_);
	push_envp_to_var_lst(envp, &g_ptrs.var_lst_);
	push_var_to_lst(&g_ptrs.var_lst_, "?", "0");
	initialize_tkn_lst(&g_ptrs.tkn_lst_);
	// TODO
	
}

/* ************************************************************************** */

// TODO!!
void	handle_signals(void)
{
	struct termios	term;

	(void)term;
	// signal(SIGINT, signal_handler);
	// signal(SIGQUIT, SIG_IGN);
	// tcgetattr(STDIN_FILENO, &term);
	// term.c_lflag &= (ICANON | ECHO);
	// term.c_cc[VMIN] = 1;
	// term.c_cc[VTIME] = 0;
	// tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

/* ************************************************************************** */

// TODO!!!
void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		// if (g_state.is_fork == 0)
		// {
		// 	printf("\n");
		// 	rl_on_new_line();
		// 	rl_replace_line("", 1);
		// 	rl_redisplay();
		// 	g_state.exit_code = 1;
		// }
		// else
		// {
		// 	g_state.exit_code = 130;
		// 	printf("\n");
		// }
		printf("BLABLA\n");
	}
}

/* ************************************************************************** */