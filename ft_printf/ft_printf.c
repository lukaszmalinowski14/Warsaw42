/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:38:23 by lmalinow          #+#    #+#             */
/*   Updated: 2025/02/25 16:33:42 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_text(t_print *print)
{
	size_t	len;

	len = 0;
	while (print->str[len] != '\0' && print->str[len] != '%')
	{
		len++;
	}
	ft_write(print->str, len, print);
	print->str += len;
}

t_direc	ft_parse_format_specifier(t_print *print)
{
	t_direc	result;

	result.text = print->str[1];
	if (result.text != '\0')
		print->str += 2;
	else
		print->str += 1;
	return (result);
}

void	ft_print_arg(t_direc args, t_print *print)
{
	if (args.text == 'c')
		ft_printchar(args, print);
	else if (args.text == 's')
		ft_printstr(args, print);
	else if (args.text == 'p')
		ft_printptr(args, print);
	else if (args.text == 'd' || args.text == 'i')
		ft_printnbr(args, print);
	else if (args.text == 'u')
		ft_printunbr(args, print, BASE_DEC, "");
	else if (args.text == 'x')
		ft_printunbr(args, print, BASE_HEXL, PRE_HEXL);
	else if (args.text == 'X')
		ft_printunbr(args, print, BASE_HEXU, PRE_HEXU);
	else if (args.text == '%')
		ft_putchar('%', print);
	else
	{
		ft_putchar('%', print);
		ft_putchar(args.text, print);
	}
}

void	ft_specifier(t_print *print)
{
	t_direc	param;

	param = ft_parse_format_specifier(print);
	ft_print_arg(param, print);
}

int	ft_printf(char const *f, ...)
{
	t_print	print;

	va_start(print.arguments, f);
	print.str = (char *)f;
	print.char_count = 0;
	while (print.char_count != -1 && print.str[0] != '\0')
	{
		if (print.str[0] == '%')
		{
			ft_specifier(&print);
		}
		else
		{
			ft_parse_text(&print);
		}
	}
	return (print.char_count);
}

// int	main(void)
// {
// 	int a = 4;
// 	ft_printf("First arg: %c\n", 'a');
// 	ft_printf("First arg: %s\n", "Hello World!");
// 	ft_printf("First arg: %d\n", 12764);
// 	ft_printf("First arg: %i\n", -123);
// 	ft_printf("First arg: %d\n", 0);
// 	ft_printf("First arg: %d\n", -2147483648);
// 	ft_printf("First arg: %u\n", -214);
// 	ft_printf("First arg: %u\n", 2147483646);
// 	ft_printf("First arg: %x\n", 21474);
// 	ft_printf("First arg: %x\n", -21474);
// 	ft_printf("First arg: %X\n", 21474);
// 	ft_printf("First arg: %X\n", -21474);
// 	ft_printf("First arg: %p\n", &a);
// 	ft_printf("First %% arg: %s\n", "Hello!");
// 	ft_printf("First arg: %q\n", "Hello!");

// 	return (0);
// }
