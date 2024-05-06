/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:19:35 by asideris          #+#    #+#             */
/*   Updated: 2024/05/06 11:12:43 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_to_print(char to_print_type, va_list ap);
int	ft_printf(const char *to_print, ...);
int	ft_putchar(char c);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putptr_base(unsigned long nbr, char *base);
int	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_putnbr(int nbr);
int	ft_putunbr(unsigned int nbr);

#endif
