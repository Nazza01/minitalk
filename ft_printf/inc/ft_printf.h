/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nervin <nervin@student.42adel.org.au >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:45:03 by nervin            #+#    #+#             */
/*   Updated: 2021/11/12 17:48:51 by nervin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	"../libft/libft.h"
# include	<stdarg.h>

typedef struct s_printf
{
	va_list	args;
	int		total;
}	t_print;

int		ft_printf(const char *formatting, ...);
char	*ft_numlen(unsigned long num, int *len);
void	ft_check(const char c, t_print *argcount);
void	ft_ischaracter(t_print *argcount);
void	ft_isstring(t_print *argcount);
void	ft_ispointer(t_print *argcount);
void	ft_isint(t_print *argcount);
void	ft_isunsigned(t_print *argcount);
void	ft_ishex(t_print *argcount, char c);
void	ft_isperc(t_print *argcount);

#endif