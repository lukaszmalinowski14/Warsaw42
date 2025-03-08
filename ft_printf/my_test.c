#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// Funkcja pomocnicza do porównywania wyników
// Funkcja pomocnicza do porównywania wyników

int main()
{

	// Testy z NULL
	int c=printf("Wskaźnik NULL: %p\n", NULL);
	int d=ft_printf("Wskaźnik NULL: %p\n", NULL);
	printf("%d, %d\n",c,d);
	printf("Wskaźnik NULL: %p\n", (void *)0);
	ft_printf("Wskaźnik NULL: %p\n", (void *)0);

	// // Testy z różnymi adresami
	int x = 10;
	printf("Adres x: %p\n", (void *)&x);
	ft_printf("Adres x: %p\n", (void *)&x);
	printf("Adres funkcji main: %p\n", (void *)main);
	ft_printf("Adres funkcji main: %p\n", (void *)main);

	// // Testy z dużymi adresami
	int e=printf("Duży adres: %p\n", (void *)ULONG_MAX);
	int f=ft_printf("Duży adres: %p\n", (void *)ULONG_MAX);
	printf("%d, %d\n", e, f);

	// // Testy z różnymi kombinacjami
	printf("Różne: %p, %p, %p\n", (void *)&x, (void *)main, NULL);
	ft_printf("Różne: %p, %p, %p\n", (void *)&x, (void *)main, NULL);

	int a=printf(" %p %p \n",(void *)0, (void *)0);
	int b=ft_printf(" %p %p \n", (void *)0, (void *)0);

	printf("%d, %d \n", a, b);

	return 0;
}
// int main(void)
// {
// 	int x = 10;
// 	int *ptr = &x;

// 	printf("%p\n", (void *)0); // Poprawione: rzutowanie na void *
// 	// int a = 4;
// 	ft_printf("First arg: %d\n", 5454);
// 	printf("%p \n", 0);
// 	// ft_printf("First arg: %s\n", "Hello World!");
// 	// ft_printf("First arg: %d\n", 12764);
// 	// ft_printf("First arg: %i\n", -123);
// 	// ft_printf("First arg: %d\n", 0);
// 	// ft_printf("First arg: %d\n", -2147483648);
// 	// ft_printf("First arg: %u\n", -214);
// 	// ft_printf("First arg: %u\n", 2147483646);
// 	// ft_printf("First arg: %x\n", 21474);
// 	// ft_printf("First arg: %x\n", -21474);
// 	// ft_printf("First arg: %X\n", 21474);
// 	// ft_printf("First arg: %X\n", -21474);
// 	// ft_printf("First arg: %p\n", &a);
// 	// ft_printf("First %% arg: %s\n", "Hello!");
// 	// ft_printf("First arg: %q\n", "Hello!");
// 	// printf("%-x\n", 42);
// 	// ft_printf("%-x\n", 42);
// 	// printf("|%16s|\n", "nark nark");
// 	// ft_printf("|%16s|\n", "nark nark");

// 	return (0);
// }

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
