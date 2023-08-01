/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalnaqb <alalnaqb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:15:32 by alalnaqb          #+#    #+#             */
/*   Updated: 2023/02/13 18:24:48 by alalnaqb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsignbr(unsigned int num)
{
	int	len;

	len = 0;
	if (num > 9)
		len += unsignbr(num / 10);
	len += ft_putchar(LOWER_HEX[num % 10]);
	return (len);
}
// int main(void)
// {
// 	int num = 345;
// 	printf("here it is %u\n", num);
// 	unsignbr(num);
// 	int len = unsignbr(num);
// 	printf(" The length is %d\n", len);
// 	return 0;
// }
