/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_to_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:05:59 by asideris          #+#    #+#             */
/*   Updated: 2024/05/06 11:05:30 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_to_print(char to_print_type, va_list ap)
{
	int		printed;
	char	percent;

	percent = '%';
	printed = 0;
	if (to_print_type == 'c')
		printed = printed + ft_putchar(va_arg(ap, int));
	else if (to_print_type == 's')
		printed = ft_putstr(va_arg(ap, char *));
	else if (to_print_type == 'i' || to_print_type == 'd')
		printed = printed + ft_putnbr(va_arg(ap, int));
	else if (to_print_type == 'u')
		printed = printed + ft_putunbr(va_arg(ap, unsigned int));
	else if (to_print_type == 'x')
		printed = printed + ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (to_print_type == 'X')
		printed = printed + ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	else if (to_print_type == 'p')
		printed = printed + ft_putptr_base(va_arg(ap, unsigned long long),
				"0123456789abcdef");
	else if (to_print_type == '%')
		printed = printed + write(1, &percent, 1);
	else
		printed = printed + write(1, &to_print_type, 1);
	return (printed);
}
