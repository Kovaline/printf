/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:56:47 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/27 11:56:49 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		checkfirstflag(char *str, int i, t_flag *fl)
{
	while (str[i] == '#' || str[i] == '+' || str[i] == '-'
		|| str[i] == '0' || str[i] == ' ')
	{
		if (str[i] == '#')
			fl->sharp = 1;
		if (str[i] == '0')
			fl->zero = 1;
		if (str[i] == '+')
			fl->plus = 1;
		if (str[i] == '-')
			fl->minus = 1;
		if (str[i] == ' ')
			fl->space = 1;
		i++;
	}
	if (fl->minus == 1)
		fl->zero = 0;
	if (fl->plus == 1)
		fl->space = 0;
	return (i);
}

int		checksecondflag(char *str, int i, t_fl *ft)
{
	if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
			ft->hh = 1;
		else
			ft->h = 1;
		return (1);
	}
	if (str[i] == 'l')
	{
		if (str[i + 1] == 'l')
			ft->ll = 1;
		else
			ft->l = 1;
		return (1);
	}
	if (str[i] == 'L')
	{
		ft->bigl = 1;
		return (1);
	}
	return (0);
}

int		countwidth(char *str, int i, t_flag *fl)
{
	fl->width = ft_atoi(str + i);
	while (str[i] > 47 && str[i] < 58)
		i++;
	if (str[i] == '.')
	{
		i++;
		fl->isdot = 1;
	}
	fl->dot = ft_atoi(str + i);
	while (str[i] > 47 && str[i] < 58)
		i++;
	return (i);
}

int		checkflags(char *str, int i, t_fl *ft, t_flag *fl)
{
	int count;
	int j;

	count = 0;
	if (validletter(str[i]) == 0)
	{
		j = i;
		if (j < (i = checkfirstflag(str, i, fl)))
			;
		if ((str[i] > 47 && str[i] < 58) || str[i] == '.') 
			i = countwidth(str, i, fl);
		if (checksecondflag(str, i, ft) == 1)
		{
			if (ft->ll == 1 || ft->hh == 1)
				i++;
			i++;
		}
	}
	if (settype(str[i], fl) == 0)
		return (i);
	return (i);
}
