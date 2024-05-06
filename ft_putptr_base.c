/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:05:47 by asideris          #+#    #+#             */
/*   Updated: 2024/05/03 14:28:25 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr(unsigned long nbr, char *base)
{
	unsigned long	baselen;
	int				count;

	count = 0;
	baselen = (unsigned long)ft_strlen(base);
	if (nbr < baselen)
	{
		write(1, &base[nbr], 1);
		count++;
	}
	else
	{
		count += ft_print_ptr(nbr / baselen, base);
		count += ft_print_ptr(nbr % baselen, base);
	}
	return (count);
}

int	ft_putptr_base(unsigned long nbr, char *base)
{
	int	count;

	count = 2;
	write(1, "0x", 2);
	return (count + ft_print_ptr(nbr, base));
}
