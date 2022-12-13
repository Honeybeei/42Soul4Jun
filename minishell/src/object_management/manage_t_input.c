/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_t_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:37 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/13 15:26:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_input	*init_t_input(void)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (t_input == NULL)
		return (NULL);
	input->str_arr_ = NULL;
	input->str_cnt_ = -1;
	return (input);
}

int	terminate_t_input(t_input *input)
{
	int	idx;

	if (input == NULL)
		return (yes_err_);
	idx = 0;
	while (idx < input->str_cnt_)
		free(input->str_arr_[idx++]);
	free(input);
	return (no_err_);
}