/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/05/02 13:16:09 by asideris          #+#    #+#             */
/*   Updated: 2024/05/02 13:16:09 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *to_print, ...)
{
	va_list	ap;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(ap, to_print);
	while (to_print[i])
	{
		if (to_print[i] == '%')
		{
			printed = printed + ft_print_to_print(to_print[++i], ap);
		}
		else
		{
			printed = printed + write(1, &(to_print[i]), 1);
		}
		i++;
	}
	va_end(ap);
	return (printed);
}

/*#include <stdio.h>
int	main(void)
{
	int result;
	char *str;
	int og_result;
	void *ptr;

	str = "hello there\n";
	ptr = NULL;
	printf("*******************************\n");
	printf("C\n");
	printf("retour original; %c\n", 'A');
	ft_printf("retour perso; %c\n", 'A');
	printf("retour count ; %d\n", ft_printf("%c", 'A'));
	printf("retour count original; %d\n", printf("%c", 'A'));
	printf("*******************************\n");
	printf("S\n");

	og_result = printf("%s", NULL);
	result = ft_printf("%s", NULL);
	ft_printf("retour du count %i\n", result);
	printf("retour du count original %i\n", og_result);
	// INTEGER
	printf("*******************************\n");
	printf("I\n");
	printf("retour original; %i\n", 15);
	ft_printf("retour perso; %i\n", 15);
	ft_printf("retour count ; %d\n", ft_printf("%i", 15));
	printf("retour count original; %d\n", printf("%i", 15));
	// HEX cap
	printf("*******************************\n");
	printf("X\n");
	printf("retour original; %X\n", -15);
	ft_printf("retour perso; %X\n", -15);
	printf("retour count ; %d\n", ft_printf("%X", -15));
	printf("retour count original; %d\n", printf("%X", -15));
	// HEX nocap
	printf("*******************************\n");
	printf("x\n");
	printf("retour original; %x\n", 15);
	ft_printf("retour perso; %x\n", 15);
	printf("retour count : %d\n", ft_printf("%x", 15));
	printf("retour count original: %d\n", printf("%x", 15));
	// POINTEUR VOID
	printf("*******************************\n");
	printf("p\n");
	printf("  perso %d\n", ft_printf("%p", ptr));
	printf("  origi %d\n", printf("%p", ptr));
	ptr = str;
	printf("  perso %d\n", ft_printf("%p", ptr));
	printf("  origi %d\n", printf("%p", ptr));
	printf("*******************************\n");
	printf("%%\n");
	printf("retour count ; %d\n", ft_printf("%%   "));
	printf("retour count original; %d\n", printf("%%   "));
}*/
