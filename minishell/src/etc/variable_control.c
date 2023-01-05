/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:18:10 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/01 18:22:23 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	**split_envp_str(char *envp_str, char **splitted_envp);

/* ************************************************************************** */

void	push_envp_to_var_lst(char **envp, t_var_lst *var_list)
{
	size_t	idx;
	char	*splitted_envp[2];

	idx = 0;
	while (envp[idx] != NULL)
	{
		split_envp_str(envp[idx], splitted_envp);
		push_var_nd_to_list(var_list, splitted_envp[0], splitted_envp[1]);
		free(splitted_envp[0]);
		free(splitted_envp[1]);
		idx++;
	}
}

/* ************************************************************************** */

static char	**split_envp_str(char *envp_str, char **splitted_envp)
{
	size_t	idx;
	char	*val_str_start;
	size_t	val_str_len;

	idx = 0;
	while (envp_str[idx] != '\0')
	{
		if (envp_str[idx] == '=')
		{
			splitted_envp[0] = calloc_safe(idx + 1, sizeof(char));
			ft_strncpy(splitted_envp[0], envp_str, idx);
			val_str_start = envp_str + idx + 1;
			val_str_len = ft_strlen(val_str_start);
			splitted_envp[1] = calloc_safe(val_str_len, sizeof(char));
			ft_strncpy(splitted_envp[1], val_str_start, val_str_len);
			return (splitted_envp);
		}
		idx++;
	}
	return (NULL);
}

/* ************************************************************************** */



/* ************************************************************************** */