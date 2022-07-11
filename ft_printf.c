/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 11:25:38 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/11 13:00:48 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * @brief This funciton is called when a '%' is found in the str. It checks
 * what character comes after this '%' and what action is needed.
 * 
 * @param str 
 * @param arg 
 * @param i 
 * @param c 
 * @return int 
 */
static int	ft_check_conversion(char str, va_list *arg, int i, int *c)
{
	if (str == 'c')
		return (ft_putchar(va_arg(*arg, int), i, c));
	else if (str == 's')
		return (ft_putstr(va_arg(*arg, char *), i, c));
	else if (str == 'p')
		return (ft_putptr(va_arg(*arg, unsigned long), i, c));
	else if (str == 'i')
		return (ft_putnbr(va_arg(*arg, int), i, c));
	else if (str == 'd')
		return (ft_putnbr(va_arg(*arg, int), i, c));
	else if (str == 'u')
		return (ft_putnbr(va_arg(*arg, unsigned int), i, c));
	else if (str == 'x')
		return (ft_puthexa(va_arg(*arg, unsigned int), i, c, 0));
	else if (str == 'X')
		return (ft_puthexa(va_arg(*arg, unsigned int), i, c, 1));
	else
		return (ft_putchar(str, i, c));
}

/**
 * @brief The starting point of the Printf function. 
 * 
 * @param str The string that has to be printed
 * @param ... a variable number of arguments
 * @return (int) The amount of characters that are printed
 */
int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (0);
			else
				i = ft_check_conversion(str[i], &arg, i, &c);
		}
		else
			i = ft_putchar(str[i], i, &c);
	}
	va_end(arg);
	return (c);
}
