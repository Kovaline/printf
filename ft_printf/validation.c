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

int		validletter(char s)
{
	if (s == 'd' || s == 'i' || s == 'u' || s == 'o'
		|| s == 'x' || s == 'X' || s == 'c' || s == 'p'
		|| s == 's' || s == 'f' || s == '%')
		return (1);
	return (0);
}

int		settype(char s, t_flag *fl)
{
	if (s == 'd' || s == 'i' || s == 'u' || s == 'o'
		|| s == 'x' || s == 'X' || s == 'c' || s == 'p'
		|| s == 's' || s == 'f' || s == '%')
	{
		fl->type = s;
		if ((fl->type == 'd' || fl->type == 'i') && fl->sharp == 1)
			fl->sharp = 0;
		if ((fl->type == 'c' || fl->type == 's' || fl->type == 'p'))
		{
			fl->sharp = 0;
			fl->zero = 0;
			fl->plus = 0;
			fl->space = 0;
		}
		return (1);
	}
	return (0);
}
