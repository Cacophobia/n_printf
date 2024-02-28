/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:49:38 by nranna            #+#    #+#             */
/*   Updated: 2023/12/28 23:27:46 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(char *s)
{
	int	nofchars;

	nofchars = 0;
	if (!s)
		s = "(null)";
	while (s[nofchars])
	{
		write (1, &s[nofchars], 1);
		nofchars++;
	}
	return (nofchars);
}
