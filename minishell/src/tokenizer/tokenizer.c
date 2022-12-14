/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:28:50 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/14 17:04:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tokenizer.h"

/* ************************************************************************** */

t_tkn_lst	token_list_generator(char *str, char *delimiter_str)
{
	t_tkn_lst	*token_list;

	token_list = init_token_list();
	
	
}

/* ************************************************************************** */

// token list management

t_tkn_lst	*init_token_list(void)
{
	t_tkn_lst	*token_list;

	token_list = malloc(sizeof(t_tkn_lst));
	if (token_list == NULL)
		return (NULL);
	token_list->head_ = NULL;
	token_list->tail_ = NULL;
	token_list->tkn_cnt_ = 0;
	return (token_list);
}


void	*terminate_token_list(t_tkn_lst *list)
{
	if (list == NULL)
		return (NULL);
	while (token_list->tkn_cnt_ > 0)
		pop_token_node(list, tail_)
	free(token_list);
	return (NULL);
}

/* ************************************************************************** */

// token node management

t_tkn_nd	*init_token_node(const char *str)
{
	t_tkn_nd	*token_node;

	token_node = malloc(sizeof(t_tkn_nd));
	if (token_node == NULL)
		return (NULL);
	token_node->next_ = NULL;
	token_node->prev_ = NULL;
	if (str == NULL)
		token_node->str_ = NULL;
	else
		token_node->str_ = ft_strdup(str);  // TODO : make ft_strdup!!
	return (token_node);
}

// WARNING : Adding node should not be connected to other node. 
t_tkn_lst	*add_token_node(t_tkn_lst *list, t_tkn_nd *node, t_tkn_bool dst)
{
	if (list == NULL || node == NULL || node->next_ != NULL || node->prev_ != NULL)
		return (NULL);
	if (list->tkn_cnt_ == 0)
	{
		list->head_ = node;
		list->tail_ = node;
	}
	else if (dst == head_)
	{
		node->next_ = list->head_;
		list->head_->prev_ = node->next_;
		list->head_ = node;
	}
	else  // dst == tail
	{
		list->tail_->next_ = node;
		node->prev_ = list->tail_;
		list->tail_ = node;
	}
	list->tkn_cnt_++;
	return (list);
}

t_tkn_nd	*pick_token_node(t_tkn_lst *list, t_tkn_bool dst)
{
	t_tkn_nd	*picked_node;
	if (list == NULL || list->tkn_cnt_ == 0)
		return (NULL);
	if (list->tkn_cnt_ == 1)
	{
		picked_node = list->head_;
		list->head_ = NULL;
		list->tail_ = NULL;
	}
	else if (dst == head)
	{
		picked_node = list->head_;
		list->head_ = list->head_->next_;
		picked_node->next_ == NULL;
		list->head_->prev_ == NULL;
	}
	else  // dst == tail
	{
		picked_node = list->tail_;
		list->tail_ = list->tail_->prev_;
		list->tail_->next_ = NULL;
		picked_node->prev_ == NULL;
	}
	list->tkn_cnt_--;
	return (picked_node);
}


// Delete picked node
t_tkn_lst	*pop_token_node(t_tkn_lst *list, t_tkn_bool dst)
{
	t_tkn_nd	*del_node;

	del_node = pick_token_node(list, dst);
	if (del_node == NULL)
		return (NULL);
	if (del_node->str_ != NULL)
		free(del_node->str_);
	free(del_node);
	return (list);
}

/* ************************************************************************** */