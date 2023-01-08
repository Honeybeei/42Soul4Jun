/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_variable_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:48:02 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 18:35:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_var_nd	*create_var_nd(void);

/* ************************************************************************** */

static t_var_nd	*create_var_nd(void)
{
	return (my_calloc(1, sizeof(t_var_nd)));
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
		if (my_strcmp(nd_ptr->name_, name) != 0)
			nd_ptr = nd_ptr->next_;
		else
			return (nd_ptr);
	}
	return (NULL);
}

/* ************************************************************************** */

t_bool	update_var(t_var_lst *lst, char *target_name, char *new_val)
{
	t_var_nd	*var_to_update;

	if (lst == NULL || target_name == NULL || new_val == NULL)
		return (fail_);
	var_to_update = search_var(lst, target_name);
	if (var_to_update == NULL)
		return (fail_);
	free(var_to_update->val_);
	var_to_update->val_ = ft_strdup(new_val);
	return (success_);
}

/* ************************************************************************** */

/**
 * @brief Add variable 
 * 
 * @param lst 
 * @param name 
 * @param val 
 */
void	push_var_to_lst(t_var_lst *lst, char *name, char *val)
{
	t_var_nd	*new_node;

	new_node = create_var_nd();
	new_node->name_ = ft_strdup(name);
	new_node->val_ = ft_strdup(val);
	if (lst->var_cnt_ == 0)
	{
		lst->head_ = new_node;
		lst->tail_ = new_node;
	}
	else
	{
		if (update_var(lst, name, val) == success_)
			return ;
		lst->tail_->next_ = new_node;
		new_node->prev_ = lst->tail_;
		lst->tail_ = new_node;
	}
	lst->var_cnt_++;
}

/* ************************************************************************** */