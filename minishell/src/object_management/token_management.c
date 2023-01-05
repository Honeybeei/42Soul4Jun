/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:43:40 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/02 13:32:34 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_tkn_nd	*create_token_node(void);
static void		terminate_token_node(t_tkn_nd *del_nd);

/* ************************************************************************** */

/**
 * @brief Initialize token list. 
 * 
 * @param token_list_ 
 */
void	init_token_list(t_tkn_lst *token_list)
{
	if (token_list == NULL)
		return ;
	token_list->head_ = NULL;
	token_list->tail_ = NULL;
	token_list->tkn_cnt_ = 0;
	token_list->pipe_cnt_ = 0;
}

/* ************************************************************************** */

/**
 * @brief Clear token list by terminating all malloced token nodes. 
 * 
 * @param token_list_ 
 */
void	clear_token_list(t_tkn_lst *token_list)
{
	t_tkn_nd	*del_nd;

	if (token_list == NULL)
		return ;
	while (token_list->head_ != NULL)
	{
		del_nd = token_list->head_;
		token_list->head_ = token_list->head_->next_;
		terminate_token_node(del_nd);
	}
	token_list->tkn_cnt_ = 0;
}

/* ************************************************************************** */

static t_tkn_nd	*create_token_node(void)
{
	t_tkn_nd	*new_node;

	new_node = calloc_safe(1, sizeof(t_tkn_nd));
	new_node->next_ = NULL;
	new_node->prev_ = NULL;
	new_node->str_ = NULL;
	new_node->type_ = none_;
	return (new_node);
}

/* ************************************************************************** */

/**
 * @brief Terminate token node. 
 * 
 * @param del_nd 
 */
static void	terminate_token_node(t_tkn_nd *del_nd)
{
	if (del_nd == NULL)
		return ;
	free(del_nd->str_);
	del_nd->str_ = NULL;
	free(del_nd);
	del_nd = NULL;
}

/* ************************************************************************** */

/**
 * @brief Push new token node to the tail of the token list(param 1).
 * 
 * @note str(param2) will be duplicated(ft_strdup) to the token node. Therefore,
 *  it should be freed before the process ends.
 * 
 * @param list 
 * @param str 
 * @param type 
 */
void	push_tkn_nd_to_list(t_tkn_lst *list, const char *str, t_t_type type)
{
	t_tkn_nd	*new_node;

	new_node = create_token_node();
	new_node->str_ = ft_strdup(str);
	new_node->type_ = type;
	if (list->tkn_cnt_ == 0)
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
	list->tkn_cnt_++;
}

/* ************************************************************************** */