
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

void pf_putchar(char c, t_print *print)
{
	pf_write(&c, 1, print);
}

void pf_putstr(char *str, t_print *print)
{
	pf_write(str, pf_strlen(str), print);
}

void pf_putnbr(unsigned long num, char *base, size_t prec, t_print *print)
{
	size_t base_len;

	base_len = pf_strlen(base);
	if (num >= base_len)
		pf_putnbr(num / base_len, base, prec, print);
	pf_write(base + (num % base_len), 1, print);
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
		pf_putchar('%', print);
	else
	{
		pf_putchar('%', print);
		pf_putchar(direc.t, print);
	}
}
void pf_printchar(t_direc direc, t_print *print)
{
	char c;

	c = va_arg(print->a, int);
	pf_putchar(c, print);
	(void)direc;
}

void pf_printstr(t_direc direc, t_print *print)
{
	char *str;

	str = va_arg(print->a, char *);
	if (str == NULL)
		pf_putstr(STR_NULL, print);
	else
		pf_putstr(str, print);
	(void)direc;
}

void pf_printnbr(t_direc direc, t_print *print)
{
	int num;

	num = va_arg(print->a, int);
	if (num < 0)
		pf_putchar('-', print);
	pf_putnbr(pf_abs(num), BASE_DEC, 0, print);
	(void)direc;
}

void pf_printunbr(t_direc direc, t_print *print, char *base, char *prefix)
{
	t_uint num;

	num = va_arg(print->a, t_uint);
	pf_putnbr(num, base, 0, print);
	(void)direc;
	(void)prefix;
}

void pf_printptr(t_direc direc, t_print *print)
{
	pf_putstr(PRE_HEXL, print);
	pf_putnbr((unsigned long)va_arg(print->a, void *), BASE_HEXL, 0, print);
	(void)direc;
}

t_direc pf_parsedirec(t_print *print)
{
	t_direc result;

	result.t = print->s[1];
	if (result.t != '\0')
		print->s += 2;
	else
		print->s += 1;
	return (result);
}

static void pf_direc(t_print *print)
{
	t_direc direc;

	direc = pf_parsedirec(print);
	pf_printdirec(direc, print);
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
			pf_direc(&print);
		else
			pf_text(&print);
	}
	va_end(print.a);
	return (print.r);
}

int main(void)
{
	int a = 4;
	//ft_printf("First arg: %c\n", 'a');
	//ft_printf("First arg: %u\n", -123);
	ft_printf("First arg: %x\n", 21474);
	ft_printf("First arg: %x\n", -21474);
	return (0);
}
