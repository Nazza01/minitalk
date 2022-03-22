/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:42:44 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/17 14:16:53 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
Handles communciations using bits. Uses bit shifting to go through the string.
Iterates through the binary code and output's the character using ASCII.
On the last bit it uses ft_printf to output the character it has received.
When index equals 7 this is the last bit to be printed so it output's it.
If the current character is null term char for a string then we print a newline.
*/
static void	handle_coms(int com_bit)
{
	int	index;

	index = 0;
	g_coms.character += ((com_bit & 1) << g_coms.index);
	g_coms.index++;
	if (g_coms.index == 7)
	{
		ft_printf("%c", g_coms.character);
		if (g_coms.character == '\0')
			ft_printf("\n");
		g_coms.character = 0;
		g_coms.index = 0;
	}
}

/*
Outputs the server PID and handles communication using SIGUSR1 and SIGUSR2
Putting signal and pause in while loop helps with waiting for another message 
to be received.
*/
int	main(void)
{
	ft_printf("Server started! PID: %i\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handle_coms);
		signal(SIGUSR2, handle_coms);
		pause();
	}
	return (0);
}
