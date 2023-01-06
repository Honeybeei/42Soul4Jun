/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_variable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:48:02 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 16:31:38 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_var_nd	*create_var_nd(void);

/* ************************************************************************** */

static t_var_nd	*create_var_nd(void)
{
	return (calloc_safe(1, sizeof(t_var_nd)));
}

/* ************************************************************************** */

/**
 * @brief Terminate variable node.
 * 
 * @param del_nd 
 */
void	terminate_var_nd(t_var_nd *del_nd)
{
	if (del_nd != NULL)
		return ;
	free(del_nd->name_);
	free(del_nd->val_);
}

/* ************************************************************************** */

/**
 * @brief Search matching variable. Returns the pointer of matching variable 
 * node. Otherwise, it will return NULL. 
 * 
 * @param lst 
 * @param name 
 * @return t_var_nd* 
 */
t_var_nd	*search_var(t_var_lst *lst, char *name)
{
	t_var_nd	*nd_ptr;

	if (lst == NULL || name == NULL)
		return (NULL);
	nd_ptr = lst->head_;
	while (nd_ptr != NULL)
	{
		if (ft_strcmp(nd_ptr->name_, name) != 0)
			nd_ptr = nd_ptr->next_;
		else
			return (nd_ptr);
	}
	return (NULL);
}

/* ************************************************************************** */

void	update_var_val_(t_var_lst *lst, char *target_name, char *update_val)
{
	t_var_nd	*var_to_update;

	if (lst == NULL || target_name == NULL || update_val == NULL)
		return ;
	var_to_update = search_var(lst, target_name);
	if (var_to_update == NULL)
		return ;
	free(var_to_update->val_);
	var_to_update->val_ = ft_strdup(update_val);
}

/* ************************************************************************** */

/**
 * @brief Add variable 
 * 
 * @param var_lst 
 * @param name 
 * @param val 
 */
void	push_var_to_list(t_var_lst *var_lst, char *name, char *val)
{
	t_var_nd	*new_node;

	new_node = create_var_nd();
	new_node->name_ = ft_strdup(name);
	new_node->val_ = ft_strdup(val);
	if (var_lst->var_cnt_ == 0)
	{
		var_lst->head_ = new_node;
		var_lst->tail_ = new_node;
	}
	else
	{
		var_lst->tail_->next_ = new_node;
		new_node->prev_ = var_lst->tail_;
		var_lst->tail_ = new_node;
	}
	var_lst->var_cnt_++;
}

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
