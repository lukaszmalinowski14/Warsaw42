/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:38:23 by lmalinow          #+#    #+#             */
/*   Updated: 2025/01/05 18:18:35 by lmalinow         ###   ########.fr       */
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

// //### TO REMOVE ###########
// int len(long nb)
// {
// 	int i;

// 	i = (nb <= 0);
// 	while (nb)
// 	{
// 		nb /= 10;
// 		i++;
// 	}
// 	return (i);
// }

// //TO REMOVE #################
// char *ft_itoa(int n)
// {
// 	char *str;
// 	long nb;
// 	int i;

// 	nb = n;
// 	i = len(nb);
// 	str = (char *)malloc(i + 1);
// 	if (!str)
// 		return (NULL);
// 	str[i--] = '\0';
// 	if (nb < 0)
// 	{
// 		str[0] = '-';
// 		nb = -nb;
// 	}
// 	while (i >= 0 && nb > 0)
// 	{
// 		str[i--] = '0' + (nb % 10);
// 		nb /= 10;
// 	}
// 	if (n == 0)
// 		str[0] = '0';
// 	return (str);
// }

// //TO REMOVE ####################################
// size_t ft_strlen(char *str)
// {
// 	size_t len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

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

//moim zdaniem nie potrzebna
void	ft_printchar(t_direc args, t_print *print)
{
	char	c;

	c = va_arg(print->arguments, int);
	ft_write (&c, 1, print);
	(void)args;
}

void	ft_printstr(t_direc args, t_print *print)
{
	char	*str;

	str = va_arg(print->arguments, char *);
	if (str == NULL)
		ft_write(STR_NULL, ft_strlen(STR_NULL), print);
	else
		ft_write(str, ft_strlen(str), print);
	(void)args;
}

void	ft_printnbr(t_direc direc, t_print *print)
{
	int		num;
	char	*str;

	num = va_arg(print->arguments, int);
	str = ft_itoa(num);
	ft_write(str, ft_strlen(str), print);
	(void)direc;
}

void ft_printunbr(t_direc direc, t_print *print, char *base, char *prefix)
{
	t_uint	num;

	num = va_arg(print->arguments, t_uint);
	ft_putnbr(num, base, 0, print);
	(void)direc;
	(void)prefix;
}

void ft_putchar(char c, t_print *print)
{
	ft_write(&c, 1, print);
}

void ft_printptr(t_direc direc, t_print *print)
{
	ft_write(PRE_HEXL, ft_strlen(PRE_HEXL), print);
	ft_putnbr((unsigned long)va_arg(print->arguments, void *), BASE_HEXL, 0, print);
	(void)direc;
}

void	ft_parse_text(t_print *print)
{
	size_t len;

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
	t_direc param;

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
