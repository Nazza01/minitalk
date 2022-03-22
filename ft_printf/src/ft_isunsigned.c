/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nervin <nervin@student.42adel.org.au >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:59:12 by nervin            #+#    #+#             */
/*   Updated: 2021/11/29 13:38:08 by nervin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
ft_nlen
	Get length of the number by dividing by 10 when we encounter the next digit
*/
static int	ft_nlen(unsigned int num)
{
	int	len;

	len = 1;
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

/*
itoa
	Because libft's ft_itoa uses it's own ft_strlen, we need to make our own (above)
	Otherwise the implementation is the same.
*/
static char	*itoa(unsigned int num)
{
	int		len;
	char	*str;

	len = ft_nlen(num);
	str = malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		--len;
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

/*
ft_isunsigned
	Takes in argcount and uses itoa (above implementation) and outputs the string
	to standard output. Increments the argcount total by the length of the string
	Frees the string.
*/
void	ft_isunsigned(t_print *argcount)
{
	char			*str;
	unsigned int	res;

	res = va_arg(argcount->args, unsigned int);
	str = itoa(res);
	ft_putstr_fd(str, 1);
	argcount->total += ft_strlen(str);
	free(str);
}
