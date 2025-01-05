/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:39:39 by lmalinow          #+#    #+#             */
/*   Updated: 2025/01/05 18:43:27 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned long num, char *base, size_t prec, t_print *print)
{
	size_t base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_putnbr(num / base_len, base, prec, print);
	ft_write(base + (num % base_len), 1, print);
}

void	ft_printstr(t_direc args, t_print *print)
{
	char *str;

	str = va_arg(print->arguments, char *);
	if (str == NULL)
		ft_write(STR_NULL, ft_strlen(STR_NULL), print);
	else
		ft_write(str, ft_strlen(str), print);
	(void)args;
}

void	ft_printnbr(t_direc direc, t_print *print)
{
	int num;
	char *str;

	num = va_arg(print->arguments, int);
	str = ft_itoa(num);
	ft_write(str, ft_strlen(str), print);
	(void)direc;
}

void	ft_printunbr(t_direc direc, t_print *print, char *base, char *prefix)
{
	t_uint num;

	num = va_arg(print->arguments, t_uint);
	ft_putnbr(num, base, 0, print);
	(void)direc;
	(void)prefix;
}

void	ft_printptr(t_direc direc, t_print *print)
{
	ft_write(PRE_HEXL, ft_strlen(PRE_HEXL), print);
	ft_putnbr((unsigned long)va_arg(print->arguments, void *), BASE_HEXL, 0, print);
	(void)direc;
}
