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
	fl->isdot = 0;
	fl->iszero = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list var;
	int		i;
	t_fl	ft;
	t_flag	fl;

	A;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = checkflags((char *)format, ++i, &ft, &fl);
			if (fl.type == 0)
				continue ;
			printit(var, &ft, &fl);
			settozero(&ft, &fl);
		}
		else
		{
			ft_putchar(format[i]);
			fl.count++;
		}
		i++;
	}
	va_end(var);
	return (fl.count);
}

/*int main()
{
	printf("%i", ft_printf("%"));
	printf("\n");
	fflush(stdout);
	printf("%i", printf("%"));
}*/
