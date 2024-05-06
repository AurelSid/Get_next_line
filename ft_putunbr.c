/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:40:58 by asideris          #+#    #+#             */
/*   Updated: 2024/05/06 11:13:21 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int		count;
	char	c;

	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr *= -1;
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
		count++;
	}
	else
	{
		count += ft_putunbr(nbr / 10);
		count += ft_putunbr(nbr % 10);
	}
	return (count);
}
