/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalnaqb <alalnaqb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:29:28 by alalnaqb          #+#    #+#             */
/*   Updated: 2023/02/11 16:42:33 by alalnaqb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

int		ft_printf(const char *formate, ...);
int		ft_putchar(char c);
int		printhex(unsigned int nbr, char *hex);
int		printnbr(long long int num);
int		printptr(unsigned long n);
int		printstr(char *str);
int		unsignbr(unsigned int u);
#endif
