/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:37:49 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/05 14:35:21 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

/* ************************************************************************** */

/**
 * In this box, we will check if its true that exit() function frees all 
 * malloced memory. 
*/

/* ************************************************************************** */

// SINGLY LINKED LIST

typedef	enum e_direction
{
	head_ = 0,
	tail_
}	t_dir;

typedef struct s_node
{
	int				val_;
	struct s_node	*next_;
}	t_node;

typedef struct s_list
{
	t_node	*head_;
	t_node	*tail_;
	size_t	nd_cnt_;
}	t_list;

void	add_node_to_list(t_list *list, int val)
{
	t_node	*new_node;

	new_node = calloc(1, sizeof(t_node));
	new_node->val_ = val;
	if (list->nd_cnt_ == 0)
	{
		list->head_ = new_node;
		list->tail_ = new_node;
	}
	else
	{
		list->tail_->next_ = new_node;
		list->tail_ = list->tail_->next_;
	}
	list->nd_cnt_++;
}

t_list	*make_list(void)
{
	t_list	*new_list;

	new_list = calloc(1, sizeof(t_list));
	new_list->nd_cnt_ = 0;
	return (new_list);
}

void	pop_node(t_list *list, t_dir target)
{
	t_node	*del_nd;

	if (list->nd_cnt_ == 0)
		return ;
	else if (list->nd_cnt_ == 1)
	{
		free(list->head_);
		list->head_ = NULL;
		list->tail_ = NULL;
	}
	else if (target == head_)
	{
		del_nd = list->head_;
		list->head_ = list->head_->next_;
		free(del_nd);
	}
	else if (target == tail_)
	{
		del_nd = list->tail_;
		list->tail_ = list->head_;
		while (list->tail_->next_->next_ != NULL)
			list->tail_ = list->tail_->next_;
		free(del_nd);
	}
	else
		return ;
	list->nd_cnt_--;
}

void	terminate_list(t_list *list)
{
	while (list->nd_cnt_ != 0)
		pop_node(list, head_);
	free(list);
}

void	print_list(t_list *list)
{
	t_node	*nd_ptr;

	printf("Node count : %3zu", list->nd_cnt_);
	nd_ptr = list->head_;
	printf(" | ");
	while (nd_ptr != NULL)
	{
		printf("[%2d] ", nd_ptr->val_);
		nd_ptr = nd_ptr->next_;
	}
	printf(" |\n");
}

/* ************************************************************************** */

int main(void)
{
	t_list	*list;
	
	list = make_list();
	for (size_t i = 0; i < 10; i++)
	{
		add_node_to_list(list, i);
	}
	print_list(list);
	terminate_list(list);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return 0;
}