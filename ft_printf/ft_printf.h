/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:55:28 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/28 12:40:48 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

typedef	struct	s_fl
{
	unsigned int		l : 1;
	unsigned int		h : 1;
	unsigned int		ll : 1;
	unsigned int		hh : 1;
	unsigned int		bigl : 1;
}				t_fl;

typedef struct s_flag
{
	unsigned int 		zero : 1;
	unsigned int		sharp : 1;
	unsigned int		minus : 1;
	unsigned int		plus : 1;
	unsigned int		space : 1;
	unsigned int		width;
	unsigned int		dot;
	unsigned int		count;
	unsigned int 		isdot;
	char				type;
	unsigned int 		iszero;
}				t_flag;

void	printocta(va_list var, t_fl *ft, t_flag *fl);
char	*sharp(char *tmp, t_flag *fl, struct s_norme *t);
uintmax_t	convertingu(uintmax_t i, t_fl *ft);
char	*applyflagsint(char *str, t_fl *ft, t_flag *fl);
void	printhexa(va_list var, t_fl *ft, t_flag *fl);
void	printu(va_list var, t_fl *ft, t_flag *fl);
char 	*ft_itoa_base(intmax_t nb, int base, t_flag *fl);
char	*applysignsnone(char *tmp, int j, int len);
char	*applynone(char *tmp, char *str, t_flag *fl, unsigned int size);
char	*applyzero(char *tmp, char *str, t_flag *fl);
char	*applyminus(char *tmp, char *str, t_flag *fl, unsigned int size);
void	printint(va_list var, t_fl *ft, t_flag *fl);
int		checkflags(char *str, int i, t_fl *ft, t_flag *fl);
int		validletter(char s);
void	printit(va_list var, t_fl *ft, t_flag *fl);
int		settype(char s, t_flag *fl);
