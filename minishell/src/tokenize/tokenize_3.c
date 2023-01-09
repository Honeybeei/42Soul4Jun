/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:12:54 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/09 13:27:53 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void		search_quotes_and_destroy(t_tkn_nd *nd_ptr);
static size_t	count_quotations(char *str);
static char		*partial_copy_till_quote(char *str_ptr, char **dst,
					t_q_flg *flg);

/* ************************************************************************** */

void	convert_quoted_strings(t_tkn_lst *lst)
{
	t_tkn_nd	*nd_ptr;

	nd_ptr = lst->head_;
	while (nd_ptr != NULL)
	{
		search_quotes_and_destroy(nd_ptr);
		nd_ptr = nd_ptr->next_;
	}
}

/* ************************************************************************** */

static void	search_quotes_and_destroy(t_tkn_nd *nd_ptr)
{
	char	**temp_arr;
	t_q_flg	quote_flg;
	char	*str_ptr;
	size_t	arr_idx;
	char	*result_str;

	quote_flg.single_q_ = down_;
	quote_flg.double_q_ = down_;
	temp_arr = my_calloc(count_quotations(nd_ptr->val_) + 2, sizeof(char *));
	str_ptr = nd_ptr->val_;
	arr_idx = 0;
	while (*str_ptr != '\0')
		str_ptr = partial_copy_till_quote(str_ptr, &temp_arr[arr_idx++],
				&quote_flg);
	result_str = my_strarrjoin(temp_arr, INT_MAX);
	arr_idx = 0;
	while (temp_arr[arr_idx] != NULL)
		free(temp_arr[arr_idx++]);
	free(temp_arr);
	free(nd_ptr->val_);
	nd_ptr->val_ = result_str;
}

/* ************************************************************************** */

static size_t	count_quotations(char *str)
{
	size_t	i;
	size_t	quotation_cnt;

	i = 0;
	quotation_cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			quotation_cnt++;
		i++;
	}
	return (quotation_cnt);
}

/* ************************************************************************** */

static char	*partial_copy_till_quote(char *str_ptr, char **dst, t_q_flg *flg)
{
	char	*str_end;

	str_end = str_ptr;
	while (*str_end != '\0')
	{	
		if (*str_end == '\'' && flg->double_q_ == up_)
			str_end++;
		else if (*str_end == '\"' && flg->single_q_ == up_)
			str_end++;
		else if (*str_end == '\'' || *str_end == '\"')
		{
			if (*str_end == '\'')
				flg->single_q_ *= -1;
			else
				flg->double_q_ *= -1;
			*dst = my_strndup(str_ptr, str_end - str_ptr);
			return (str_end + 1);
		}
		else
			str_end++;
	}
	*dst = my_strndup(str_ptr, str_end - str_ptr);
	return (str_end);
}

/* ************************************************************************** */
