/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:38:23 by lmalinow          #+#    #+#             */
/*   Updated: 2025/01/05 23:43:23 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//to remove
 //### TO REMOVE ###########
 int len(long nb)
{
 	int i;

	i = (nb <= 0);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

//TO REMOVE #################
char *ft_itoa(int n)
{
	char *str;
	long nb;
	int i;

	nb = n;
	i = len(nb);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (i >= 0 && nb > 0)
	{
		str[i--] = '0' + (nb % 10);
		nb /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}

//TO REMOVE ####################################
size_t ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

//Write out

void ft_write(void *buf, size_t len, t_print *print)
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

void ft_printchar(t_direc args, t_print *print)
{
	char c;

	c = va_arg(print->arguments, int);
	ft_write(&c, 1, print);
	(void)args;
}

void ft_putchar(char c, t_print *print)
{
	ft_write(&c, 1, print);
}

//print_func
void ft_putnbr(unsigned long num, char *base, size_t prec, t_print *print)
{
	size_t base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_putnbr(num / base_len, base, prec, print);
	ft_write(base + (num % base_len), 1, print);
}

void ft_printstr(t_direc args, t_print *print)
{
	char *str;
	size_t len;

	str = va_arg(print->arguments, char *);
	if (str == NULL)
		str = STR_NULL;
	len = ft_strlen(str);
	if ((args.flag & FLAG_PREC) && args.p < len)
		len = args.p;
	if (!(args.flag & FLAG_MINUS))
		ft_add_padding(' ', args.w, len, print);
	ft_write(str, len, print);
	if (args.flag & FLAG_MINUS)
		ft_add_padding(' ', args.w, len, print);
}

void ft_printnbr(t_direc result, t_print *print)
{
	int number;
	t_uint u_number;
	size_t len;

	number = va_arg(print->arguments, int);
	u_number = ft_abs(number);
	len = ft_count_nbr_length(u_number, result.p, ft_strlen(BASE_DEC));
	if (number < 0 || (result.flag & (FLAG_PLUS | FLAG_SPACE)))
		len += 1;
	if (!(result.flag & FLAG_MINUS) && !(result.flag & FLAG_ZERO))
		ft_add_padding(' ', result.w, len, print);
	if (number < 0)
		ft_putchar('-', print);
	else if (result.flag & FLAG_PLUS)
		ft_putchar('+', print);
	else if (result.flag & FLAG_SPACE)
		ft_putchar(' ', print);
	if (!(result.flag & FLAG_MINUS) && (result.flag & FLAG_ZERO))
		ft_add_padding('0', result.w, len, print);
	ft_printnbr_sec(result, print, u_number, len);
}

void ft_printnbr_sec(t_direc result, t_print *print, t_uint u_number, size_t len)
{
	char	*str;

	str = ft_itoa(u_number);
	if (ft_strlen(str) < len)
		if ((result.flag & FLAG_PLUS) || (result.flag & FLAG_SPACE))
			ft_add_padding('0', len - 1, ft_strlen(str), print);
		else
			ft_add_padding('0', len, ft_strlen(str), print);
	ft_write(str, ft_strlen(str), print);
	if (result.flag & FLAG_MINUS)
		ft_add_padding(' ', result.w, len, print);
}

void ft_printunbr(t_direc result, t_print *print, char *base, char *prefix)
{
	t_uint number;
	size_t len;
	size_t lenx;

	number = va_arg(print->arguments, t_uint);
	lenx = ft_count_nbr_length(number, 0, ft_strlen(base));
	len = ft_count_nbr_length(number, result.p, ft_strlen(base));
	if ((result.flag & FLAG_ALTER) && number != 0)
		len += ft_strlen(prefix);
	if (!(result.flag & FLAG_MINUS) && !(result.flag & FLAG_ZERO))
		ft_add_padding(' ', result.w, len, print);
	if ((result.flag & FLAG_ALTER) && number != 0)
		ft_write(prefix, ft_strlen(prefix), print);
	if (!(result.flag & FLAG_MINUS) && (result.flag & FLAG_ZERO))
		ft_add_padding('0', result.w, len, print);
	if ( lenx < len)
		if (result.flag & FLAG_ALTER)
			ft_add_padding('0', len - ft_strlen(prefix), lenx, print);
		else
			ft_add_padding('0', len, lenx, print);
	ft_putnbr(number, base, result.p, print);
	if (result.flag & FLAG_MINUS)
		ft_add_padding(' ', result.w, len, print);
}

void ft_printptr(t_direc direc, t_print *print)
{
	ft_write(PRE_HEXL, ft_strlen(PRE_HEXL), print);
	ft_putnbr((unsigned long)va_arg(print->arguments, void *), BASE_HEXL, 0, print);
	(void)direc;
}
//new
void ft_add_padding(char c, size_t w, size_t len, t_print *print)
{
	size_t i;

	if (w <= len)
		return;
	i = 0;
	while (i < w - len)
	{
		ft_write(&c, 1, print);
		i++;
	}
}

void	ft_parseflags(t_direc *result, t_print *print)
{
	result->flag = 0x00;
	while (1)
	{
		if (print->str[0] == '#')
			result->flag |= FLAG_ALTER;
		else if (print->str[0] == '+')
			result->flag |= FLAG_PLUS;
		else if (print->str[0] == ' ')
			result->flag |= FLAG_SPACE;
		else if (print->str[0] == '-')
			result->flag |= FLAG_MINUS;
		else if (print->str[0] == '0')
			result->flag |= FLAG_ZERO;
		else
			break;
		print->str += 1;
	}
}

t_uint ft_abs(int i)
{
	if (i < 0)
		return ((t_uint)(-i));
	else
		return ((t_uint)i);
}

size_t ft_count_nbr_length(unsigned long num, size_t prec, size_t base_len)
{
	size_t result;

	if (num == 0 && prec == 0)
		return (0);
	result = 1;
	while (num >= base_len || prec > 1)
	{
		if (prec > 1)
			prec -= 1;
		num /= base_len;
		result += 1;
	}
	return (result);
}

void	ft_parsewidth_precision(t_direc *result, t_print *print)
{
	result->w = 0;
	result->p = 1;
	while (print->str[0] >= '0' && print->str[0] <= '9')
	{
		result->w = result->w * 10 + (print->str[0] - '0');
		print->str += 1;
	}
	if (print->str[0] == '.')
	{
		result->flag |= FLAG_PREC;
		result->flag &= ~FLAG_ZERO;
		print->str += 1;
		result->p = 0;
		while (print->str[0] >= '0' && print->str[0] <= '9')
		{
			result->p = result->p * 10 + (print->str[0] - '0');
			print->str += 1;
		}
	}
}

//main
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

	print->str += 1;
	ft_parseflags(&result, print);
	ft_parsewidth_precision(&result, print);
	result.text = print->str[0];
	if (result.text != '\0')
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

int	main(void)
{
	int a = 4;
	ft_printf("First arg: |%-10d|\n", 123); //"|123       |"
	ft_printf("|%010d|\n", 42);				//"|0000000042|"
	ft_printf("|%-010d|\n", 42);			// "|42        |" (flag `-` overwrite `0`)
	printf("|% d|\n", 42);				// "| 42|"
	ft_printf("|% d|\n", 42);				// "| 42|"
	printf("|% d|\n", -42);				// "|-42|"
	ft_printf("|% d|\n", -42);				// "|-42|"
	ft_printf("|%+ d|\n", 42);				// "|+42|"
	ft_printf("|%+d|\n", 42);				// "|+42|"
	ft_printf("|%+d|\n", -42);				// "|-42|"
	ft_printf("|%#x|\n", 134);				// Wynik: "|0x86|"
	ft_printf("|%#X|\n", 10);				// Wynik: "|0XA|"
	ft_printf("|%#x|\n", 134);				// Wynik: "|0x86|"
	ft_printf("|%#X|\n", 10);				// Wynik: "|0XA|"
	ft_printf("|%.3x|\n", 255);		// Wynik: "|0ff|"
	ft_printf("|%.3x|\n", 255); // Wynik: "|0ff|"
	printf("|%.5d|\n", 42);	// Wynik: "|00042|"
	ft_printf("|%.5d|\n", 42);	// Wynik: "|00042|"
	ft_printf("|%.5s|\n", "Hello, World!"); // Wynik: "|Hello|"
	ft_printf("|%.10s|\n", "Hi!");			// Wynik: "|Hi!|"
	ft_printf("|%10.5s|\n", "Hello, World!"); // Wynik: "|     Hello|"
	printf("|%#.5x|\n", 255);			  // Wynik: "|0x000ff|"
	ft_printf("|%#.5x|\n", 255);			  // Wynik: "|0x000ff|"
	printf("|%+.3d|\n", 42);				  // Wynik: "|+042|"
	ft_printf("|%+.3d|\n", 42);				  // Wynik: "|+042|"
	ft_printf("|%10.4x|\n", 255);			  // Wynik: "|      00ff|"
	ft_printf("|%#10.3x|\n", 255);			  // Wynik: "|     0x0ff|"
	ft_printf("|%+10.5d|\n", 123);			  // Wynik: "|    +00123|"

	return (0);
}
