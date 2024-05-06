/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:05:56 by asideris          #+#    #+#             */
/*   Updated: 2024/05/06 11:14:27 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	baselen;
	int				count;

	count = 0;
	baselen = (unsigned int)(ft_strlen(base));
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr = nbr * -1;
	}
	if (nbr < baselen)
	{
		write(1, &base[nbr], 1);
		count++;
	}
	else
	{
		count += ft_putnbr_base(nbr / baselen, base);
		count += ft_putnbr_base(nbr % baselen, base);
	}
	return (count);
}
