/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:28:55 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/13 14:45:45 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_input	*get_input_from_user(void)
{
	t_input	*user_input;
	char	*
	
	
}

int	main(void)
{
	t_input	*user_input;

	enter_shell();
	while (true)
	{
		t_input = get_input_from_user();
		read_line_result = readline("Type : ");
		if (read_line_result == NULL)
			break ;
		printf("User typed -> [%s]\n", read_line_result);
		if (read_line_result != NULL && read_line_result[0] != '\0') 
			add_history(read_line_result);
		rl_on_new_line();
		free(read_line_result); // must free this malloced string from readline()
	}
	
	return (0);
}