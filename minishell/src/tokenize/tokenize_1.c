/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:26:22 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 11:39:43 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	is_white_space(unsigned char c);
static bool	is_meta_char(unsigned char c);

/* ************************************************************************** */

void	tokenize_input(t_tkn_lst *lst)
{
	char	*user_input;

	user_input = readline(PROMPT_STR);
	if (user_input != NULL)
	{
		printf("user input : [%s]\n", user_input);  // TEST
		// split_input_to_tokens(user_input, lst);
	}
	else
	{
		printf("user input : NULL -> EOF\n");  // TEST
	}
	free(user_input);


	// (void)lst;  // TEST
}

/* ************************************************************************** */

// split string by using meta-character as an delimeter. 
void	split_input_to_tokens(char *user_input, t_tkn_lst *lst)
{
	size_t	i;
	
	i = 0;
	while (user_input[i] != '\0')
	{
		if (is_white_space(user_input[i]) == true)
			i++;
		else if (is_meta_char(user_input[i] == true))
			i += push_meta_char(&user_input[i]);	//	TODO!!
		else
			i += push_word(&user_input[i]);		// TODO!!
	}
	
}

/* ************************************************************************** */

static bool	is_white_space(unsigned char c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

/* ************************************************************************** */

static bool	is_meta_char(unsigned char c)
{
	if (ft_strchr(META_CHAR, c) == NULL)
		return (false);
	return (true);
}

/* ************************************************************************** */