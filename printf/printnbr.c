/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalnaqb <alalnaqb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:24:52 by alalnaqb          #+#    #+#             */
/*   Updated: 2023/02/13 17:18:19 by alalnaqb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(long long int num)
{
	char	*digits;
	int		len;

	digits = "0123456789";
	len = 0;
	if (num < 0)
	{
		len = len + ft_putchar('-');
		num = num * -1;
	}
	if (num >= 10)
	{
		len += printnbr(num / 10);
	}
	len += ft_putchar(digits[num % 10]);
	return (len);
}

// int	main(void)
// {
// 	int	m;

// 	m = -42;
// 	printf("the num is %d\n", m);
// 	printnbr(m);
// 	return (0);
// }
