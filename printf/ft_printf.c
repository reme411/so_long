/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalnaqb <alalnaqb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:01:43 by alalnaqb          #+#    #+#             */
/*   Updated: 2023/02/13 17:33:26 by alalnaqb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checking(va_list args, char form)
{
	int	len;

	len = 0;
	if (form == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (form == 's')
		len += printstr(va_arg(args, char *));
	else if (form == 'p')
	{
		len += printstr("0x");
		len += printptr(va_arg(args, unsigned long));
	}
	else if (form == 'd' || form == 'i')
		len += printnbr(va_arg(args, int));
	else if (form == 'u')
		len += unsignbr(va_arg(args, unsigned int));
	else if (form == 'x')
		len += printhex(va_arg(args, unsigned int), LOWER_HEX);
	else if (form == 'X')
		len += printhex(va_arg(args, unsigned int), UPPER_HEX);
	return (len);
}

int	ft_printf(const char *formate, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, formate);
	while (formate[i] != '\0')
	{
		if (formate[i] == '%')
		{
			formate++;
			if (*formate == '%')
				len += write (1, "%", 1);
			else
				len += checking (args, *formate);
		}
		else
			len += write(1, formate, 1);
		formate++;
	}
	va_end(args);
	return (len);
}

// int main() 
// {
// 	char	c = 'A';
// 	char	str[] = "Hello, World!";
// 	int		x = 42;
// 	unsigned int y = 123456789;

// 	printf(" OG Character value: %c\n", c);
// 	ft_printf("Character value: %c\n", c);
// 	printf(" OG String value: %s\n", str);
// 	ft_printf("String value: %s\n", str);
// 	printf(" OG Integer value: %d\n", x);
// 	ft_printf("Integer value: %d\n", x);
// 	printf(" OG Unsigned integer value: %u\n", y);
// 	ft_printf("Unsigned integer value: %u\n", y);
// 	printf(" OG Hexadecimal value: %x\n", x);
// 	ft_printf("Hexadecimal value: %x\n", x);
// 	printf(" OG Uppercase hexadecimal value: %X\n", x);
// 	ft_printf("Uppercase hexadecimal value: %X\n", x);
// 	printf(" OG Percent sign: %%\n");
// 	ft_printf("Percent sign: %%\n");
// 	ft_printf("pointer value: %p\n", str);
// 	return (0);
// }
