/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:21:57 by ikovalen          #+#    #+#             */
/*   Updated: 2018/12/11 13:22:00 by ikovalen         ###   ########.fr       */
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

void	printhexa(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	uintmax_t		i;
	intmax_t		j;

	j = va_arg(var, intmax_t);
	i = (uintmax_t)j;
	i = convertingu(i, ft);
	if (i == 0)
		fl->iszero = 1;
	if (fl->isdot != 0 || i != 0)
		str = ft_itoa_base(i, 16, fl);
	else
	{
		str = (char *)malloc(1 *sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	str = applyflagsint(str, ft, fl);
	j = -1;
	if (fl->type == 'x')
	{
		while (str[++j] != '\0')
		{
			if (str[j] > 64 && str[j] < 91)
				str[j] = str[j] + 32;
		}
	}
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
}

void	printocta(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	uintmax_t		i;
	intmax_t		j;

	j = va_arg(var, intmax_t);
	i = (uintmax_t)j;
	i = convertingu(i, ft);
	if (fl->isdot != 0 || i != 0)
		str = ft_itoa_base(i, 8, fl);
	else
	{
		str = (char *)malloc(1 *sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	str = applyflagsint(str, ft, fl);
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
}
