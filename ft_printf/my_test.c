#include "ft_printf.h"

int main(void)
{
	int a = 4;
	ft_printf("First arg: %c\n", 'a');
	ft_printf("First arg: %s\n", "Hello World!");
	ft_printf("First arg: %d\n", 12764);
	ft_printf("First arg: %i\n", -123);
	ft_printf("First arg: %d\n", 0);
	ft_printf("First arg: %d\n", -2147483648);
	ft_printf("First arg: %u\n", -214);
	ft_printf("First arg: %u\n", 2147483646);
	ft_printf("First arg: %x\n", 21474);
	ft_printf("First arg: %x\n", -21474);
	ft_printf("First arg: %X\n", 21474);
	ft_printf("First arg: %X\n", -21474);
	ft_printf("First arg: %p\n", &a);
	ft_printf("First %% arg: %s\n", "Hello!");
	ft_printf("First arg: %q\n", "Hello!");

	return (0);
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
