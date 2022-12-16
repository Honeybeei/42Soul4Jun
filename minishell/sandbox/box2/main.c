/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:47:13 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/16 17:04:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "libft_functions.h"

#define CONTROL_OPERATOR_COUNT		10
#define CONTROL_OPERATOR_MAX_LEN	10

void	init_control_operator(void *control_operator_arr_)
{
	char **control_operator_arr;

	control_operator_arr = (char **)control_operator_arr_;
	ft_strcpy(control_operator_arr[0], "||");
	ft_strcpy(control_operator_arr[1], "&&");
	ft_strcpy(control_operator_arr[2], "&");
	ft_strcpy(control_operator_arr[3], ";");
	ft_strcpy(control_operator_arr[4], ";;");
	ft_strcpy(control_operator_arr[5], ";&");
	ft_strcpy(control_operator_arr[6], ";;&");
	ft_strcpy(control_operator_arr[7], "|");
	ft_strcpy(control_operator_arr[8], "|&");
	ft_strcpy(control_operator_arr[9], "(");
	ft_strcpy(control_operator_arr[10], ")");
	control_operator_arr[CONTROL_OPERATOR_COUNT] = NULL;
}

int main(void)
{
	char control_operator_arr[CONTROL_OPERATOR_COUNT + 1][CONTROL_OPERATOR_MAX_LEN + 1];

	init_control_operator(control_operator_arr);
	for (int i = 0; control_operator_arr[i] != NULL; i++)
	{
		printf("%d : [%s]\n", i, control_operator_arr[i]);
	}
	
	return 0; 
}