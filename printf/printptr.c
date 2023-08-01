/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalnaqb <alalnaqb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:34:45 by alalnaqb          #+#    #+#             */
/*   Updated: 2023/02/13 16:53:20 by alalnaqb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += printptr(n / 16);
	}
	len += ft_putchar(LOWER_HEX[n % 16]);
	return (len);
}
// int main()
// {
// 	int	a = 422;

// 	printptr(a);
// 	return (0);
// }
