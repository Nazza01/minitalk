/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nervin <nervin@student.42adel.org.au >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:59:10 by nervin            #+#    #+#             */
/*   Updated: 2021/11/29 13:28:14 by nervin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
ft_isstring
	If the string is null, we want to output null and add 6 for: (null)
	Otherwise we want to ge the length of the string, and output it and add the
		length to the total to make it easier.
*/
void	ft_isstring(t_print *argcount)
{
	char	*str;
	int		len;

	str = va_arg(argcount->args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		argcount->total += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		argcount->total += len;
	}
}
