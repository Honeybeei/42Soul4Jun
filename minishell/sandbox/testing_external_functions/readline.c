/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:22:19 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/08 16:22:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

// IMPORTANT : must use -lreadline flag in compile command.
int main(void)
{
    char *input_str;

    for (size_t i = 0; i < 5; i++)
    {
        input_str = readline("type : ");
        add_history(input_str);
        printf("User just typed : %s\n", input_str);
        free(input_str);
    }
    return (0);
}