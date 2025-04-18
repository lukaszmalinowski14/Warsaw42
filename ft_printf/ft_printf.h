/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:42:38 by lmalinow          #+#    #+#             */
/*   Updated: 2025/03/09 15:13:00 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdarg.h>
#include "libft/libft.h"

#define BASE_DEC "0123456789"
#define BASE_HEXL "0123456789abcdef"
#define BASE_HEXU "0123456789ABCDEF"
#define STR_NULL "(null)"
#define PRE_HEXL "0x"
#define PRE_HEXU "0X"

typedef unsigned char t_flag;
typedef unsigned int t_uint;

typedef struct s_print
{
	char *str;
	va_list arguments;
	int char_count;
} t_print;

typedef struct s_direc
{
	t_flag flag;
	size_t w;
	size_t p;
	char text;
} t_direc;

void ft_parse_text(t_print *print);
void ft_putnbr(unsigned long num, char *base, size_t prec, t_print *print);
void ft_write(void *buf, size_t len, t_print *print);
void ft_printchar(t_direc args, t_print *print);
void ft_printstr(t_direc args, t_print *print);
void ft_printnbr(t_direc direc, t_print *print);
void ft_printunbr(t_direc direc, t_print *print, char *base, char *prefix);
void ft_putchar(char c, t_print *print);
void ft_printptr(t_direc direc, t_print *print);
t_direc ft_parse_format_specifier(t_print *print);
void ft_print_arg(t_direc args, t_print *print);
void ft_specifier(t_print *print);
int ft_printf(char const *f, ...);

#endif
