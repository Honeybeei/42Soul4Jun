/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:29:31 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/15 20:01:29 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <stddef.h>	// size_t
# include <stdbool.h>	// true, false
# include <stdlib.h>	// malloc(), free()

# include "libft_functions.h"
# include "my_booleans.h"

# define META_DELIMITER	":)"

typedef struct s_token_node
{
	char				*str_;
	struct s_token_node	*prev_;
	struct s_token_node	*next_;
}	t_tkn_nd;

typedef	struct s_token_list
{
	t_tkn_nd	*head_;
	t_tkn_nd	*tail_;
	size_t		tkn_cnt_;
}	t_tkn_lst;

// token_object_management_1.c
t_tkn_lst	*init_token_list(void);
void		*terminate_token_list(t_tkn_lst *list);
t_tkn_nd	*init_token_node(const char *str);
t_tkn_lst	*add_token_node(t_tkn_lst *list, t_tkn_nd *node, t_tkn_bool dst);
t_tkn_nd	*pick_token_node(t_tkn_lst *list, t_tkn_bool dst);

// token_object_management_2.c
t_tkn_lst	*pop_token_node(t_tkn_lst *list, t_tkn_bool dst);

#endif