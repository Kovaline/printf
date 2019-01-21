/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:46:28 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/27 11:46:29 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*sharp(char *tmp, t_flag *fl, struct s_norme *t)
{
	tmp[t->j++] = '0';
	if (fl->type != 'o')
		tmp[t->j++] = 'X';
	return (tmp);
}

int		validletter(char s)
{
	if (s == 'd' || s == 'i' || s == 'u' || s == 'o'
		|| s == 'x' || s == 'X' || s == 'c' || s == 'p'
		|| s == 's' || s == 'f' || s == '%' || s == 'F'
		|| s == 'O' || s == 'C' || s == 'U' || s == 'D'
		|| s == 'S' || s == 'e' || s == 'E')
		return (1);
	return (0);
}

int		settype(char s, t_flag *fl)
{
	if (s == 'd' || s == 'i' || s == 'u' || s == 'o'
		|| s == 'x' || s == 'X' || s == 'c' || s == 'p'
		|| s == 's' || s == 'f' || s == '%' || s == 'F')
	{
		fl->type = s;
		if (fl->type == 'F' || fl->type == 'f')
			fl->type = 'f';
		if (fl->type == 'd' || fl->type == 'i' || fl->type == 'f')
			fl->sharp = 0;
		if ((fl->type == 'c' || fl->type == 's' || fl->type == 'p'))
		{
			fl->sharp = 0;
			fl->plus = 0;
			fl->space = 0;
		}
		if (fl->type == '%' || fl->type == 'u' || fl->type == 'x'
			|| fl->type == 'X' || fl->type == 'o')
		{
			fl->plus = 0;
			fl->space = 0;
		}
		return (1);
	}
	return (0);
}
