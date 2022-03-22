/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 02:18:52 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/17 14:51:37 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
Sends the message through binary and bit shifting with AND operator.
Iterates through the character's binary until it hits 0 and sends the message
using either SIGUSR1 or SIGUSR2.
*/
static void	send_message(int process_id, char *message, size_t length)
{
	int		to_shift;
	size_t	index;

	index = 0;
	while (index <= length)
	{
		to_shift = 0;
		while (to_shift < 7)
		{
			if ((message[index] >> to_shift) & 1)
				kill(process_id, SIGUSR2);
			else
				kill(process_id, SIGUSR1);
			to_shift++;
			usleep(1);
		}
		index++;
	}
}

/*
Processes the string and converts it for use in the send_message function.
If the program wasn't started properly, it displays an error message.
*/
int	main(int argc, char **argv)
{
	if (argc == 3)
		send_message(ft_atoi(argv[1]), argv[2], ft_strlen(argv[2]));
	else
	{
		ft_printf("\nPlease make sure you have formatted like so:\n");
		ft_printf("\n./bin/client <pid> <message>\n\n");
	}
	return (0);
}
