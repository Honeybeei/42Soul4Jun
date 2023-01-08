/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_variable_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:48:02 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 18:35:35 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	**split_envp_str(char *envp_str, char **splitted_envp);

/* ************************************************************************** */

/**
 * @brief Initialize variable var_lst. 
 * 
 * @param var_lst 
 */
void	initialize_var_lst(t_var_lst *var_lst)
{
	if (var_lst == NULL)
		return ;
	var_lst->head_ = NULL;
	var_lst->tail_ = NULL;
	var_lst->var_cnt_ = 0;
}

/* ************************************************************************** */

/**
 * @brief Clear variable var_lst. Terminate all variables and set var_cnt_ to 0.
 * 
 * @param var_lst 
 */
void	clear_var_lst(t_var_lst *var_lst)
{
	t_var_nd	*del_nd;

	if (var_lst == NULL)
		return ;
	while (var_lst->head_ != NULL)
	{
		del_nd = var_lst->head_;
		var_lst->head_ = var_lst->head_->next_;
		terminate_var_nd(del_nd);
	}
	var_lst->var_cnt_ = 0;
}

/* ************************************************************************** */

/**
 * @brief Push envp to variable list. 
 * 
 * @param envp 
 * @param var_list 
 */
void	push_envp_to_var_lst(char **envp, t_var_lst *var_list)
{
	size_t	i;
	char	*splitted_envp[2];

	i = 0;
	while (envp[i] != NULL)
	{
		split_envp_str(envp[i], splitted_envp);
		push_var_to_lst(var_list, splitted_envp[0], splitted_envp[1]);
		free(splitted_envp[0]);
		free(splitted_envp[1]);
		i++;
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
			splitted_envp[0] = my_calloc(idx + 1, sizeof(char));
			ft_strlcpy(splitted_envp[0], envp_str, idx + 1);
			val_str_start = envp_str + idx + 1;
			val_str_len = ft_strlen(val_str_start);
			splitted_envp[1] = my_calloc(val_str_len + 1, sizeof(char));
			ft_strlcpy(splitted_envp[1], val_str_start, val_str_len + 1);
			return (splitted_envp);
		}
		idx++;
	}
	return (NULL);
}

/* ************************************************************************** */