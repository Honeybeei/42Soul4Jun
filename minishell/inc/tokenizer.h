/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:29:31 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/14 16:23:57 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <stddef.h>	// size_t
# include <stdbool.h>	// true, false
# include <stdlib.h>	// malloc(), free()

# define META_DELIMITER	":)"

typedef enum e_tokenizer_boolean
{
	head_ = -1,
	tail_ = 1
}	t_tkn_bool;

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

#endif