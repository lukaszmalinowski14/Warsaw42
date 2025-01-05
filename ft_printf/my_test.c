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
