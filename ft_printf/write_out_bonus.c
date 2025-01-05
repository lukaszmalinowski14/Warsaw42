/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_out_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:37:21 by lmalinow          #+#    #+#             */
/*   Updated: 2025/01/05 18:58:25 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(void *buf, size_t len, t_print *print)
{
	ssize_t write_result;

	if (print->char_count == -1)
		return;
	write_result = write(1, buf, len);
	if (write_result == -1)
		print->char_count = -1;
	else
		print->char_count += write_result;
}

void	ft_printchar(t_direc args, t_print *print)
{
	char	c;

	c = va_arg(print->arguments, int);
	ft_write(&c, 1, print);
	(void)args;
}

void	ft_putchar(char c, t_print *print)
{
	ft_write(&c, 1, print);
}
