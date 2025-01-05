/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_ft_printf_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:00:06 by lmalinow          #+#    #+#             */
/*   Updated: 2025/01/05 22:45:41 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BASE_DEC "0123456789"
#define BASE_HEXL "0123456789abcdef"
#define BASE_HEXU "0123456789ABCDEF"
#define STR_NULL "(null)"
#define PRE_HEXL "0x"
#define PRE_HEXU "0X"

#define FLAG_ALTER 0x01
#define FLAG_PLUS 0x02
#define FLAG_SPACE 0x04
#define FLAG_MINUS 0x08
#define FLAG_ZERO 0x10
#define FLAG_PREC 0x20

typedef unsigned char t_flag;
typedef unsigned int t_uint;

typedef struct s_print
{
	char *s;
	va_list a;
	int r;
} t_print;

typedef struct s_direc
{
	t_flag f;
	size_t w;
	size_t p;
	char t;
} t_direc;

void pf_printstr(t_direc direc, t_print *print)
{
	char *str;
	size_t len;

	str = va_arg(print->a, char *);
	if (str == NULL)
		str = STR_NULL;
	len = pf_strlen(str);
	if ((direc.f & FLAG_PREC) && direc.p < len)
		len = direc.p;
	if (!(direc.f & FLAG_MINUS))
		pf_putpad(' ', direc.w, len, print);
	pf_write(str, len, print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, len, print);
}

void pf_printchar(t_direc direc, t_print *print)
{
	if (!(direc.f & FLAG_MINUS))
		pf_putpad(' ', direc.w, 1, print);
	pf_putchar(va_arg(print->a, int), print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, 1, print);
}

size_t pf_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

t_uint pf_abs(int i)
{
	if (i < 0)
		return ((t_uint)(-i));
	else
		return ((t_uint)i);
}
void pf_write(void *buf, size_t len, t_print *print)
{
	ssize_t wrt;

	if (print->r == -1)
		return;
	wrt = write(STDOUT_FILENO, buf, len);
	if (wrt == -1)
		print->r = -1;
	else
		print->r += wrt;
}
void pf_printptr(t_direc direc, t_print *print)
{
	void *ptr;
	size_t len;

	ptr = va_arg(print->a, void *);
	len = pf_strlen(PRE_HEXL) + pf_countnbr((unsigned long)ptr, 1, pf_strlen(BASE_HEXL));
	if (!(direc.f & FLAG_MINUS))
		pf_putpad(' ', direc.w, len, print);
	pf_putstr(PRE_HEXL, print);
	pf_putnbr((unsigned long)ptr, BASE_HEXL, 1, print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, len, print);
}

void pf_putchar(char c, t_print *print)
{
	pf_write(&c, 1, print);
}

void pf_putstr(char *str, t_print *print)
{
	pf_write(str, pf_strlen(str), print);
}

size_t pf_countnbr(unsigned long num, size_t prec, size_t base_len)
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

void pf_printnbr(t_direc direc, t_print *print)
{
	int num;
	t_uint unum;
	size_t len;

	num = va_arg(print->a, int);
	unum = pf_abs(num);
	len = pf_countnbr(unum, direc.p, pf_strlen(BASE_DEC));
	if (num < 0 || (direc.f & (FLAG_PLUS | FLAG_SPACE)))
		len += 1;
	if (!(direc.f & FLAG_MINUS) && !(direc.f & FLAG_ZERO))
		pf_putpad(' ', direc.w, len, print);
	if (num < 0)
		pf_putchar('-', print);
	else if (direc.f & FLAG_PLUS)
		pf_putchar('+', print);
	else if (direc.f & FLAG_SPACE)
		pf_putchar(' ', print);
	if (!(direc.f & FLAG_MINUS) && (direc.f & FLAG_ZERO))
		pf_putpad('0', direc.w, len, print);
	pf_putnbr(unum, BASE_DEC, direc.p, print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, len, print);
}

void pf_putnbr(unsigned long num, char *base, size_t prec, t_print *print)
{
	size_t base_len;

	base_len = pf_strlen(base);
	if (prec > 1)
		pf_putnbr(num / base_len, base, prec - 1, print);
	else if (num >= base_len)
		pf_putnbr(num / base_len, base, prec, print);
	if (num != 0 || prec > 0)
		pf_write(base + (num % base_len), 1, print);
}

void pf_putpad(char c, size_t w, size_t len, t_print *print)
{
	size_t i;

	if (w <= len)
		return;
	i = 0;
	while (i < w - len)
	{
		pf_write(&c, 1, print);
		i++;
	}
}
static void pf_printpercent(t_direc direc, t_print *print)
{
	if (!(direc.f & FLAG_MINUS))
		pf_putpad(' ', direc.w, 1, print);
	pf_putchar('%', print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, 1, print);
}

void pf_printdirec(t_direc direc, t_print *print)
{
	if (direc.t == 'c')
		pf_printchar(direc, print);
	else if (direc.t == 's')
		pf_printstr(direc, print);
	else if (direc.t == 'd' || direc.t == 'i')
		pf_printnbr(direc, print);
	else if (direc.t == 'u')
		pf_printunbr(direc, print, BASE_DEC, "");
	else if (direc.t == 'x')
		pf_printunbr(direc, print, BASE_HEXL, PRE_HEXL);
	else if (direc.t == 'X')
		pf_printunbr(direc, print, BASE_HEXU, PRE_HEXU);
	else if (direc.t == 'p')
		pf_printptr(direc, print);
	else if (direc.t == '%')
		pf_printpercent(direc, print);
	else
	{
		pf_putchar('%', print);
		pf_putchar(direc.t, print);
	}
}






void pf_printunbr(t_direc direc, t_print *print, char *base, char *prefix)
{
	t_uint num;
	size_t len;

	num = va_arg(print->a, t_uint);
	len = pf_countnbr(num, direc.p, pf_strlen(base));
	if ((direc.f & FLAG_ALTER) && num != 0)
		len += pf_strlen(prefix);
	if (!(direc.f & FLAG_MINUS) && !(direc.f & FLAG_ZERO))
		pf_putpad(' ', direc.w, len, print);
	if ((direc.f & FLAG_ALTER) && num != 0)
		pf_putstr(prefix, print);
	if (!(direc.f & FLAG_MINUS) && (direc.f & FLAG_ZERO))
		pf_putpad('0', direc.w, len, print);
	pf_putnbr(num, base, direc.p, print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, len, print);
}


static void pf_parseflags(t_direc *direc, t_print *print)
{
	direc->f = 0x00;
	while (1)
	{
		if (print->s[0] == '#')
			direc->f |= FLAG_ALTER;
		else if (print->s[0] == '+')
			direc->f |= FLAG_PLUS;
		else if (print->s[0] == ' ')
			direc->f |= FLAG_SPACE;
		else if (print->s[0] == '-')
			direc->f |= FLAG_MINUS;
		else if (print->s[0] == '0')
			direc->f |= FLAG_ZERO;
		else
			break;
		print->s += 1;
	}
}

static void pf_parsewidth(t_direc *direc, t_print *print)
{
	direc->w = 0;
	direc->p = 1;
	while (print->s[0] >= '0' && print->s[0] <= '9')
	{
		direc->w = direc->w * 10 + (print->s[0] - '0');
		print->s += 1;
	}
	if (print->s[0] == '.')
	{
		direc->f |= FLAG_PREC;
		direc->f &= ~FLAG_ZERO;
		print->s += 1;
		direc->p = 0;
		while (print->s[0] >= '0' && print->s[0] <= '9')
		{
			direc->p = direc->p * 10 + (print->s[0] - '0');
			print->s += 1;
		}
	}
}

t_direc pf_parsedirec(t_print *print)
{
	t_direc direc;

	print->s += 1;
	pf_parseflags(&direc, print); //ft to parse flags
	pf_parsewidth(&direc, print); //ft to parse width
	direc.t = print->s[0];
	if (direc.t != '\0')
		print->s += 1;
	return (direc);
}


static void pf_direc(t_print *print)
{
	t_direc direc;

	direc = pf_parsedirec(print); //ft to save parameters after % to t_direc struc
	pf_printdirec(direc, print); //ft to select accurate function to print
}

static void pf_text(t_print *print)
{
	size_t len;

	len = 0;
	while (print->s[len] != '\0' && print->s[len] != '%')
		len++;
	pf_write(print->s, len, print);
	print->s += len;
}

int ft_printf(char const *f, ...)
{
	t_print print;

	va_start(print.a, f);
	print.s = (char *)f;
	print.r = 0;
	while (print.r != -1 && print.s[0] != '\0')
	{
		if (print.s[0] == '%')
			pf_direc(&print); //ft to display formated text after %
		else
			pf_text(&print); //ft to display regular text before %
	}
	va_end(print.a);
	return (print.r);
}

int main(void)
{
	//ft_printf("first arg: %.5s, sec arg: %010d\n","Hello World!", 12345);
	ft_printf("|%.5d|\n", 42);
	return (0);
}
