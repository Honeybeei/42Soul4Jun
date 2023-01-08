/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_token_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:14:15 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 18:35:27 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_tkn_nd	*create_tkn_nd(void);
static void		terminate_tkn_nd(t_tkn_nd *del_nd);

/* ************************************************************************** */

/**
 * @brief Initialize token list. 
 * 
 * @param tkn_lst 
 */
void	initialize_tkn_lst(t_tkn_lst *tkn_lst)
{
	if (tkn_lst == NULL)
		return ;
	tkn_lst->head_ = NULL;
	tkn_lst->tail_ = NULL;
	tkn_lst->tkn_cnt_ = 0;
}

/* ************************************************************************** */

/**
 * @brief Clear token tkn_lst by terminating all malloced token nodes. 
 * 
 * @param tkn_lst 
 */
void	clear_tkn_lst(t_tkn_lst *tkn_lst)
{
	t_tkn_nd	*del_nd;

	if (tkn_lst == NULL)
		return ;
	while (tkn_lst->head_ != NULL)
	{
		del_nd = tkn_lst->head_;
		tkn_lst->head_ = tkn_lst->head_->next_;
		terminate_tkn_nd(del_nd);
	}
	tkn_lst->tkn_cnt_ = 0;
}

/* ************************************************************************** */

static t_tkn_nd	*create_tkn_nd(void)
{
	t_tkn_nd	*new_node;

	new_node = my_calloc(1, sizeof(t_tkn_nd));
	new_node->type_ = none_;
	return (new_node);
}

/* ************************************************************************** */

static void	terminate_tkn_nd(t_tkn_nd *del_nd)
{
	if (del_nd == NULL)
		return ;
	free(del_nd->val_);
	del_nd->val_ = NULL;
	free(del_nd);
	del_nd = NULL;
}

/* ************************************************************************** */

/**
 * @brief Push new token node to the tail of the token tkn_lst(param 1).
 * 
 * @note str(param2) will be duplicated(ft_strdup) to the token node. Therefore,
 *  if str(param2) is malloced str, it should be freed before the process ends.
 * 
 * @param tkn_lst 
 * @param str 
 * @param type 
 * @return size_t 
 */
size_t	push_tkn_nd_to_lst(t_tkn_lst *tkn_lst, const char *str, t_t_type type)
{
	t_tkn_nd	*new_node;

	new_node = create_tkn_nd();
	new_node->val_ = ft_strdup(str);
	new_node->type_ = type;
	if (tkn_lst->tkn_cnt_ == 0)
	{
		tkn_lst->head_ = new_node;
		tkn_lst->tail_ = new_node;
	}
	else
	{
		tkn_lst->tail_->next_ = new_node;
		new_node->prev_ = tkn_lst->tail_;
		tkn_lst->tail_ = new_node;
	}
	tkn_lst->tkn_cnt_++;
	return (ft_strlen(str));
}

/* ************************************************************************** */
