/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:48:02 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/03 14:19:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_var_nd	*create_variable_node(void);

/* ************************************************************************** */

void	init_variable_list(t_var_lst *var_list)
{
	if (var_list == NULL)
		return ;
	var_list->head_ = NULL;
	var_list->tail_ = NULL;
	var_list->var_cnt_ = 0;
}

/* ************************************************************************** */

void	clear_variable_list(t_var_lst *var_list)
{
	t_var_nd	*del_nd;

	if (var_list == NULL)
		return ;
	while (var_list->head_ != NULL)
	{
		del_nd = var_list->head_;
		var_list->head_ = var_list->head_->next_;
		terminate_variable_node(del_nd);
	}
	var_list->var_cnt_ = 0;
}

/* ************************************************************************** */

static t_var_nd	*create_variable_node(void)
{
	return  (calloc_safe(1, sizeof(t_var_nd)));
}

/* ************************************************************************** */

void	terminate_variable_node(t_var_nd *del_nd)
{
	if (del_nd != NULL)
		return ;
	free(del_nd->name_);
	free(del_nd->val_);
}

/* ************************************************************************** */

void	push_var_nd_to_list(t_var_lst *list, const char *name, const char *value)
{
	t_var_nd	*new_node;

	new_node = create_variable_node();
	new_node->name_ = ft_strdup(name);
	new_node->val_ = ft_strdup(value);
	if (list->var_cnt_ == 0)
	{
		list->head_ = new_node;
		list->tail_ = new_node;
	}
	else
	{
		list->tail_->next_ = new_node;
		new_node->prev_ = list->tail_;
		list->tail_ = new_node;
	}
	list->var_cnt_++;
}

/* ************************************************************************** */

t_var_nd	*search_matching_var(t_var_lst *list, const char *name)
{
	t_var_nd	*nd_ptr;

	if (list == NULL || name == NULL)
		return (NULL);
	nd_ptr = list->head_;
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

void	update_var_val_(t_var_lst *list, const char *target_name, const char *update_val)
{
	t_var_nd	*var_to_update;

	if (list == NULL || target_name == NULL || update_val == NULL)
		return ;
	var_to_update = search_matching_var(list, target_name);
	if (var_to_update == NULL)
		return ;
	free(var_to_update->val_);
	var_to_update->val_ = ft_strdup(update_val);
}

/* ************************************************************************** */