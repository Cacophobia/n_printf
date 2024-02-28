/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:43:24 by nranna            #+#    #+#             */
/*   Updated: 2024/01/02 13:59:27 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	big_n;
	int			nofchars;

	big_n = n;
	nofchars = 0;
	if (big_n < 0)
	{
		nofchars += ft_putchar('-');
		big_n = big_n * -1;
	}
	if (big_n > 9)
	{
		nofchars += ft_putnbr(big_n / 10);
	}
	nofchars += ft_putchar((big_n % 10) + '0');
	return (nofchars);
}

int	ft_put_unsnbr(unsigned int n)
{
	int	nofchars;

	nofchars = 0;
	if (n > 9)
	{
		nofchars += ft_putnbr(n / 10);
	}
	nofchars += ft_putchar((n % 10) + '0');
	return (nofchars);
}

int	ft_puthex(unsigned int n, char *base)
{
	long int	big_n;
	int			nofchars;

	big_n = n;
	nofchars = 0;
	if (big_n < 16)
		nofchars += ft_putchar(base[big_n % 16]);
	else if (big_n >= 16)
	{
		nofchars += ft_puthex((big_n / 16), base);
		nofchars += ft_putchar(base[big_n % 16]);
	}
	return (nofchars);
}
