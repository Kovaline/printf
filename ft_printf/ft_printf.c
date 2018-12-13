/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:02:59 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/26 13:03:00 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	settozero(t_fl *ft, t_flag *fl)
{
	fl->zero = 0;
	fl->sharp = 0;
	fl->minus = 0;
	fl->plus = 0;
	fl->space = 0;
	fl->width = 0;
	ft->h = 0;
	ft->hh = 0;
	ft->l = 0;
	ft->bigl = 0;
	ft->ll = 0;
	fl->type = 0;
	fl->dot = 0;
	fl->count = 0;
	fl->isdot = 0;
	fl->iszero = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list var;
	int		i;
	t_fl	ft;
	t_flag	fl;

	i = 0;
	settozero(&ft, &fl);
	va_start(var, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			i = checkflags((char *)format, i, &ft, &fl);
			printit(var, &ft, &fl);
		}
		else
		{
			ft_putchar(format[i]);
			fl.count++;
		}
		i++;
	}
	//printf("width is: %i\n sharp is: %i\nminus is :%i\n slapce is :%i\nzero is:%i\nplus is:%i\nh is:%i\nconv is:%c\ndot is:%i\n", 
	//	fl.width, fl.sharp, fl.minus, fl.space, fl.zero, fl.plus, ft.l, fl.type, fl.dot);
	va_end(var);
	return (fl.count);
}

/*int main()
{
	ft_printf("%-10s is a string\n", "this");
	printf("%-10s is a string\n", "this");
}*/