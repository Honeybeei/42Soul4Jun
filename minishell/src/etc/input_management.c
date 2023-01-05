/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:19:36 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/29 20:32:21 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Get string(User input) from STD_IN and saves it to the history before 
 * returns it. 
 * 
 * @return char* 
 */
char	*get_input_from_user(void)
{
	char    *read_line_result;
	
	read_line_result = readline(PROMPT_STR);
	if (read_line_result != NULL && read_line_result[0] != '\0') 
		add_history(read_line_result);
	return (read_line_result);
}

/* ************************************************************************** */