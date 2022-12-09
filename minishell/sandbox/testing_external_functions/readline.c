/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:22:19 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/09 19:05:45 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief This function reads a line from the terminal and returns it. The line 
 * returned is malloced. Therefore it SHOULD BE FREED when finished. If EOF 
 * encountered in reading process there should be two possible cases. First, if 
 * EOF encountered and the line is empty, NULL will be returned. If the line is 
 * not empty, It will be treaded as a new line. 
 * 
 * IMPORTANT : must use -lreadline flag in compile command.
 */

int main(void)
{
    char *input_str;

    for (size_t i = 0; i < 5; i++)
    {
        input_str = readline("type : ");
        add_history(input_str);
        printf("User just typed [%zu]: %s\n", i, input_str);
        free(input_str);
    }
    return (0);
}