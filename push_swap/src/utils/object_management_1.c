/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_management_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:30:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/24 20:15:01 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ************************************************************************** */

/**
 * @brief Make new t_nd.
 * 
 * @param n 
 * @return t_nd* 
 */
t_nd	*init_t_nd(int n)
{
	t_nd	*new_node;

	new_node = malloc(sizeof(t_nd));
	if (new_node == NULL)
		return (NULL);
	new_node->n_ = n;
	new_node->next_ = NULL;
	new_node->prev_ = NULL;
	return (new_node);
}

/* ************************************************************************** */

/**
 * @brief Terminate t_nd.
 * 
 * @param del_node 
 * @return void* 
 */
void	*terminate_t_nd(t_nd *del_node)
{
	if (del_node != NULL)
		free(del_node);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Make new t_stack.
 * 
 * @return t_stack* 
 */
t_stack	*init_t_stack(t_s_id stack_id)
{
	t_stack	*new_list;

	new_list = malloc(sizeof(t_stack));
	if (new_list == NULL)
		return (NULL);
	new_list->top_ = NULL;
	new_list->btm_ = NULL;
	new_list->nd_cnt_ = 0;
	new_list->id_ = stack_id;
	return (new_list);
}

/* ************************************************************************** */

/**
 * @brief Terminate t_stack.
 * 
 * @param del_stack 
 * @return void* 
 */
void	*terminate_t_stack(t_stack *del_stack)
{
	t_nd	*del_node;

	if (del_stack == NULL)
		return (NULL);
	while (del_stack->top_ != NULL)
	{
		del_node = del_stack->top_;
		del_stack->top_ = del_stack->top_->prev_;
		terminate_t_nd(del_node);
	}
	free(del_stack);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Make new t_stacks.
 * 
 * @return t_stacks* 
 */
t_stacks	*init_t_stacks(int *arg_arr, int argc)
{
	t_stacks	*new_stacks;
	int			idx;

	new_stacks = malloc(sizeof(t_stacks));
	if (new_stacks == NULL)
		return (NULL);
	new_stacks->a_ = init_t_stack(a_);
	new_stacks->b_ = init_t_stack(b_);
	idx = 0;
	while (idx < argc - 1)
	{
		push_t_nd(new_stacks->a_, init_t_nd(arg_arr[idx]), btm_);
		idx++;
	}
	return (new_stacks);
}

/* ************************************************************************** */