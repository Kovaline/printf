/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:50:42 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/28 12:50:44 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printchar(va_list var, t_fl *ft, t_flag *fl)
{
	char	*str;
	char	c;
	int		len;

	c = va_arg(var, int);
	str = ft_strnew(0);
	fl->dot = 0;
	if (fl->minus == 1)
	{
		write (1, &c, 1);
	}
	str = applyflagsint(str, ft, fl);
	len = ft_strlen(str) - 1;
	str[len] = '\0';
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	fl->count++;
	if (fl->minus == 0)
		write (1, &c, 1);
}

void	printstr(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	unsigned int	i;
	char			*tmp;

	i = 0;
	str = va_arg(var, char *);
	if (str == NULL)
		str = "(null)";
	if (fl->isdot == 1 && fl->dot < ft_strlen(tmp))
	{	
		tmp = ft_strnew(fl->dot);
		while (i < fl->dot)
		{
			tmp[i] = str[i];
			i++;
		}
		fl->dot = 0;
		printf("%s\n", "we are here");
		tmp = applyflagsint(tmp, ft, fl);
		fl->count = fl->count + ft_strlen(tmp);
		ft_putstr(tmp);
	}
	else if (fl->dot > ft_strlen(tmp) || fl->isdot == 0)
	{
		fl->dot = 0;
		str = applyflagsint(str, ft, fl);
		fl->count = fl->count + ft_strlen(str);
		ft_putstr(str);
	}
}

void	printit(va_list var, t_fl *ft, t_flag *fl)
{
	if (fl->type == 'i' || fl->type == 'd')
		printint(var, ft, fl);
	else if (fl->type == 'u')
		printu(var, ft, fl);
	if (fl->type == 'c')
		printchar(var, ft, fl);
	if (fl->type == 's')
		printstr(var, ft, fl);
	/*if (ft->type == 'p')
		printpoint(var, &ft, &fl);*/
	if (fl->type == 'x' || fl->type == 'X')
		printhexa(var, ft, fl);
	if (fl->type == 'o')
		printocta(var, ft, fl);
	/*if (ft->type == 'f')
		printdouble(var, &ft, &fl);
	if (ft->type == '%')
		printperc(&ft, &fl);*/
}
