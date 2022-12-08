/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:27:16 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/08 14:58:32 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char *input_str;

    while (true)
    {
        input_str = readline(input_str);
        printf("User just typed : %s", input_str);
        free(input_str);
    }
    return (0);
}