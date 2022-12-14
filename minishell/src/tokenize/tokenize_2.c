/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:22:28 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 22:12:08 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static size_t	skip_quoted_part(char *str_ptr, size_t i);
static size_t	convert_if_dollar_sign(t_tkn_nd *nd_ptr, size_t i);

/* ************************************************************************** */

size_t	push_operator(t_tkn_lst *lst, char *str_ptr)
{
	if (ft_strncmp(OP_PIPE_, str_ptr, ft_strlen(OP_PIPE_)) == 0)
		return (push_tkn_nd_to_lst(lst, OP_PIPE_, op_pipe_));
	else if (ft_strncmp(OP_REDIR_IN_2_, str_ptr, ft_strlen(OP_REDIR_IN_2_))
		== 0)
		return (push_tkn_nd_to_lst(lst, OP_REDIR_IN_2_, op_redirect_in_2_));
	else if (ft_strncmp(OP_REDIR_IN_1_, str_ptr, ft_strlen(OP_REDIR_IN_1_))
		== 0)
		return (push_tkn_nd_to_lst(lst, OP_REDIR_IN_1_, op_redirect_in_1_));
	else if (ft_strncmp(OP_REDIR_OUT_2_, str_ptr, ft_strlen(OP_REDIR_OUT_2_))
		== 0)
		return (push_tkn_nd_to_lst(lst, OP_REDIR_OUT_2_, op_redirect_out_2_));
	else if (ft_strncmp(OP_REDIR_OUT_1_, str_ptr, ft_strlen(OP_REDIR_OUT_1_))
		== 0)
		return (push_tkn_nd_to_lst(lst, OP_REDIR_OUT_1_, op_redirect_out_1_));
	error_handler(errno_tokenize_no_matching_operator_, true);
	return (1);
}

/* ************************************************************************** */

size_t	push_word(t_tkn_lst *lst, char *str_ptr)
{
	size_t	i;
	char	*temp_str;

	i = 0;
	while (is_white_space(str_ptr[i]) == false && is_operator(str_ptr[i])
		== false && str_ptr[i] != '\0')
	{
		if (str_ptr[i] == '\'' || str_ptr[i] == '\"')
			i = skip_quoted_part(str_ptr, i);
		else
			i++;
	}
	temp_str = my_calloc(i + 1, sizeof(char));
	ft_strlcpy(temp_str, str_ptr, i + 1);
	push_tkn_nd_to_lst(lst, temp_str, wd_);
	free(temp_str);
	return (i);
}

/* ************************************************************************** */

static size_t	skip_quoted_part(char *str_ptr, size_t i)
{
	if (str_ptr[i] == '\'')
	{
		i++;
		while (str_ptr[i] != '\'' && str_ptr[i] != '\0')
			i++;
	}
	else
	{
		i++;
		while (str_ptr[i] != '\"' && str_ptr[i] != '\0')
			i++;
	}
	if (str_ptr[i] != '\0')
		i++;
	return (i);
}

/* ************************************************************************** */

void	convert_variables(t_tkn_lst *lst)
{
	t_tkn_nd	*nd_ptr;
	size_t		i;

	nd_ptr = lst->head_;
	while (nd_ptr != NULL)
	{
		if (nd_ptr->type_ == wd_)
		{
			i = 0;
			while (nd_ptr->val_[i] != '\0')
			{
				if (nd_ptr->val_[i] == '\'')
					i = skip_quoted_part(nd_ptr->val_, i);
				else
					i = convert_if_dollar_sign(nd_ptr, i);
			}
		}
		nd_ptr = nd_ptr->next_;
	}
}

/* ************************************************************************** */

static size_t	convert_if_dollar_sign(t_tkn_nd *nd_ptr, size_t i)
{
	size_t		j;
	char		*var_name_to_search;
	t_var_nd	*search_result;
	char		*converted_str;

	if (nd_ptr->val_[i] == '$' && is_meta_char(nd_ptr->val_[i + 1])
		== false && nd_ptr->val_[i + 1] != '\0')
	{
		j = i + 1;
		while (is_meta_char(nd_ptr->val_[j]) == false && nd_ptr->val_[j]
			!= '\0')
			j++;
		var_name_to_search = my_strndup(nd_ptr->val_ + i + 1, j - i - 1);
		search_result = search_var(&g_ptrs.var_lst_, var_name_to_search);
		free(var_name_to_search);
		if (search_result == NULL)
			converted_str = my_strtransplant(nd_ptr->val_, i, j - 1, NULL);
		else
			converted_str = my_strtransplant(nd_ptr->val_, i, j - 1,
					search_result->val_);
		free(nd_ptr->val_);
		nd_ptr->val_ = converted_str;
		return (j);
	}
	return (i + 1);
}

/* ************************************************************************** */