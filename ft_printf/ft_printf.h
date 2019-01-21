/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:55:28 by ikovalen          #+#    #+#             */
/*   Updated: 2019/01/21 17:01:36 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define A i = 0; fl.count = 0; settozero(&ft, &fl); va_start(var, format)
# define B fl->isdot = 0; fl->dot = 0; tmp = applyflagsint(tmp, ft, fl)
# include "libft/libft.h"

typedef	struct	s_fl
{
	unsigned int		l : 1;
	unsigned int		h : 1;
	unsigned int		ll : 1;
	unsigned int		hh : 1;
	unsigned int		bigl : 1;
}				t_fl;

typedef struct	s_flag
{
	unsigned int		zero : 1;
	unsigned int		sharp : 1;
	unsigned int		minus : 1;
	unsigned int		plus : 1;
	unsigned int		space : 1;
	unsigned int		width;
	unsigned int		dot;
	unsigned int		count;
	unsigned int		isdot;
	char				type;
	unsigned int		iszero;
}				t_flag;

char			*ft_itoad(intmax_t nb, int base);
void			printdouble(va_list var, t_fl *ft, t_flag *fl);
char			*ft_utoa_base(uintmax_t nb, int base, t_flag *fl);
void			printocta(va_list var, t_fl *ft, t_flag *fl);
char			*sharp(char *tmp, t_flag *fl, struct s_norme *t);
uintmax_t		convertingu(uintmax_t i, t_fl *ft);
char			*applyflagsint(char *str, t_fl *ft, t_flag *fl);
void			printhexa(va_list var, t_fl *ft, t_flag *fl);
void			printu(va_list var, t_fl *ft, t_flag *fl);
char			*ft_itoa_base(intmax_t nb, int base, t_flag *fl);
char			*applysignsnone(char *tmp, int j, int len);
char			*applynone(char *tmp, char *str, t_flag *fl, unsigned int size);
char			*applyzero(char *tmp, char *str, t_flag *fl);
char			*applyminus(char *tmp, char *str,
				t_flag *fl, unsigned int size);
void			printint(va_list var, t_fl *ft, t_flag *fl);
int				checkflags(char *str, int i, t_fl *ft, t_flag *fl);
int				validletter(char s);
void			printit(va_list var, t_fl *ft, t_flag *fl);
int				settype(char s, t_flag *fl);
#endif
