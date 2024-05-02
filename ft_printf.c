/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:44:19 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 16:44:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return(1);
}

int ft_putstr(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i])
    {
        count += ft_putchar(str[i]);
        i++;
    }
    printf("retuned by putstr: %d \n", count);
    return(count);
}

int ft_putnbr(int n)
{
    int count;

    count = 0;

    if(n < 0 )
    {
        write(1,"-",1);
        ft_putnbr(-n);
        
    }
    else if(n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
        
       
    }
    else
    {
        ft_putchar(n + '0');
        count ++;
    }
    return(count);
}
int ft_putdouble(double num)
{
    int precision;
    int count;
    int integerPart = (int)num;
    double fractionalPart = num - integerPart;

    count = 0;

    count += ft_putnbr(integerPart); 

    precision = 15;
    if (precision > 0)
    {
        ft_putchar('.'); 

        while (precision > 0)
        {
            fractionalPart *= 10;
            ft_putchar((int)fractionalPart + '0');
            count ++;
            fractionalPart -= (int)fractionalPart;
            precision--;
        }
    }
    return(count);
}

int print_to_print(char to_print_type, va_list ap)
{
    int printed;

    printed = 0;
    if(to_print_type == 'c')
       printed = printed + ft_putchar(va_arg(ap,int));
    else if(to_print_type == 's')
        printed = ft_putstr(va_arg(ap, char *));
    else if(to_print_type == 'd')
        printed = printed + ft_putdouble(va_arg(ap, double));
    else if(to_print_type == 'i')
        printed = printed + ft_putnbr(va_arg(ap, int));
    /*else if(to_print_type == 'x')
        printed = printed + ft_puthex(va_arg(ap, int), 16);
    else if(to_print_type == 'X')
        printed = printed + ft_puthexcap(va_arg(ap, int), 16);*/
    else
        printed = printed + write(1,&to_print_type,1);
    return(printed);
}
int ft_printf(const char * to_print, ...)
{
    va_list ap;
    int     i;
    int     printed;

    i = 0;
    printed = 0;
    va_start(ap, to_print);

    while(to_print[i])
    {
        if(to_print[i] == '%')
        {
            printed = printed +  print_to_print(to_print[++i], ap);
        }
        else
        {
            printed = printed + write(1, &(to_print[i]), 1);
        }

        i++;
    }
    va_end(ap);
    return(printed);
    

}

int main()
{
    int result;
    char    *str;
    int og_result;

    str = "hello there\n";
    result = ft_printf("%s\n",str);
    og_result = printf("%s\n",str);
   
    ft_printf("retour du print %i\n",result);
    printf("retour du print OG %i\n",og_result);

}
