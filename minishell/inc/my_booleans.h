/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_booleans.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:06:59 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/15 20:02:52 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_BOOLEANS_H
# define MY_BOOLEANS_H

typedef enum e_my_booleans
{
	yes_err_ = -1,
	no_err_ = 1,
	head_ = -1,
	tail_ = 1,
	down_ = -1,
	up_ = 1
}	t_bool;

#endif