/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:30:46 by nranna            #+#    #+#             */
/*   Updated: 2024/01/02 14:09:10 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putptr(unsigned long ptr, char *base)
{
	int	nofchars;

	nofchars = 0;
	if (ptr < 16 && ptr != 0)
	{
		nofchars += ft_putstr("0x");
		nofchars += ft_putchar(base[ptr % 16]);
	}
	else if (ptr >= 16)
	{
		nofchars += ft_putptr((ptr / 16), base);
		nofchars += ft_putchar(base[ptr % 16]);
	}
	else if ((void *)ptr == NULL)
		nofchars += ft_putstr("(nil)");
	return (nofchars);
}

int	format_check(char form, va_list ap)
{
	int		nofchars;

	nofchars = 0;
	if (form == 'c')
		nofchars += ft_putchar(va_arg(ap, int));
	else if (form == 's')
		nofchars += ft_putstr(va_arg(ap, char *));
	else if (form == 'd' || form == 'i')
		nofchars += ft_putnbr(va_arg(ap, int));
	else if (form == 'u')
		nofchars += ft_put_unsnbr(va_arg(ap, unsigned int));
	else if (form == 'x')
		nofchars += ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (form == 'X')
		nofchars += ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (form == 'p')
		nofchars += ft_putptr(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (form == '%')
		nofchars += ft_putchar('%');
	return (nofchars);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nofchars;

	nofchars = 0;
	va_start (ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			nofchars += format_check(*format, ap);
		}
		else
			nofchars += ft_putchar(*format);
		format++;
	}
	va_end (ap);
	return (nofchars);
}
