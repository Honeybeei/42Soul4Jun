/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_object_management_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:25:28 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/15 12:22:23 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tokenizer.h"

/* ************************************************************************** */

/**
 * @brief Pops(deletes) node from the token list. 
 * 
 * @param list 
 * @param dst 
 * @return t_tkn_lst* 
 */
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