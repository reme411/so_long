/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalnaqb <alalnaqb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:22:39 by alalnaqb          #+#    #+#             */
/*   Updated: 2023/02/13 16:58:48 by alalnaqb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhex(unsigned int nbr, char *hex)
{
	int			len;

	len = 0;
	if (nbr >= 16)
	{
		len = printhex(nbr / 16, hex);
	}
	len += ft_putchar(hex[nbr % 16]);
	return (len);
}
