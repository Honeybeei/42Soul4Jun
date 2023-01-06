/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_variable_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:48:02 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 19:38:02 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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