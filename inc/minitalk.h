/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:49:31 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/11 12:53:29 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

/*
Establish a struct to store the character and index for the message.
*/
typedef struct s_coms
{
	char	character;
	size_t	index;
}	t_coms;

/*
Global struct to store the contents of the message.
*/
t_coms	g_coms;

#endif