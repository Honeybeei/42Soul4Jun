/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:19:36 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/21 20:23:23 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


// ctrl + "some key" should be handled during get_user_input. 
char	*get_input_from_user(void)
{
	char    *read_line_result;
	
	read_line_result = readline(PROMPT_STR);
	
	// TEST
	printf("\nTEST PRINTING : [%s]\n\n", read_line_result);
	// TEST

	if (read_line_result != NULL && read_line_result[0] != '\0') 
		add_history(read_line_result);
	return (read_line_result);
}