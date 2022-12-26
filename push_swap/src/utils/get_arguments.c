/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:01:02 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/26 21:42:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static t_bool	check_is_num(char *num_str);
static ssize_t	strict_atoi(char *num_str);

/* ************************************************************************** */

/**
 * @brief Parse arguments and change them to integers. If successful, it will
 * return malloced integer array, unless it will return NULL. 
 * Error cases can be
 * 	1.	Argument is not a string with integers. Only '-' sign at the front will 
 * 		be tolerated.
 * 	2.	If argument is bigger than INT_MAX or smaller than INT_MIN
 * 
 * @param argc 
 * @param argv 
 * @return int* 
 */
int	*atoi_arguments(int argc, char **argv)
{
	ssize_t	atoi_result;
	int		*num_arr;
	int		idx;

	num_arr = malloc(sizeof(int) * (argc - 1));
	if (num_arr == NULL)
		return (NULL);
	idx = 1;
	while (idx < argc)
	{
		if (check_is_num(argv[idx]) == invalid_)
		{
			free(num_arr);
			return (NULL);
		}
		atoi_result = strict_atoi(argv[idx]);
		if (atoi_result < INT_MIN || INT_MAX < atoi_result)
		{
			free(num_arr);
			return (NULL);
		}
		num_arr[idx - 1] = (int)atoi_result;
		idx++;
	}
	return (num_arr);
}

/* ************************************************************************** */

static t_bool	check_is_num(char *num_str)
{
	int	idx;

	idx = 0;
	if (num_str[0] == '-')
	{
		if (num_str[1] == '\0' || num_str[1] == '0')
			return (invalid_);
		idx++;
	}
	while (num_str[idx] != '\0')
	{
		if (idx > 10)
			return (invalid_);
		if (num_str[idx] < '0' || '9' < num_str[idx])
			return (invalid_);
		idx++;
	}
	return (valid_);
}

/* ************************************************************************** */

static ssize_t	strict_atoi(char *num_str)
{
	ssize_t	n;
	int		minus_flag;
	int		idx;

	n = 0;
	idx = 0;
	if (num_str[0] == '-')
	{
		minus_flag = -1;
		idx++;
	}
	else
		minus_flag = 1;
	while (num_str[idx] != '\0')
	{
		n *= 10;
		n += num_str[idx] - '0';
		idx++;
	}
	n *= minus_flag;
	return (n);
}

/* ************************************************************************** */

/**
 * @brief Checks if there is any same values in array. It returns invalid_ when
 * there is any duplication. 
 * 
 * @param argc 
 * @param arg_arr 
 * @return t_bool 
 */
t_bool	check_duplication(int argc, int *arg_arr)
{
	int	idx_1;
	int	idx_2;

	idx_1 = 0;
	while (idx_1 < argc - 2)
	{
		idx_2 = idx_1 + 1;
		while (idx_2 < argc - 1)
		{
			if (arg_arr[idx_1] == arg_arr[idx_2])
				return (invalid_);
			idx_2++;
		}
		idx_1++;
	}
	return (valid_);
}

/* ************************************************************************** */