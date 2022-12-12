#include "ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("Hello%10.5iWorld\n",-123);
    printf("Hello%10.5iWorld\n",-123);
    ft_printf("Hello%-10.5iWorld\n",-123);
    printf("Hello%-10.5iWorld\n",-123);
    ft_printf("Hello%-10.12iWorld\n",-123);
    printf("Hello%-10.12iWorld\n",-123);
    ft_printf("Hello% 10.5iWorld\n", 123);
    printf("Hello% 10.5iWorld\n", 123);
    ft_printf("Hello%+10.5iWorld\n",123);
    printf("Hello%+10.5iWorld\n",123);
    ft_printf("Hello%0-+10.5iWorld\n",123);
    printf("Hello%-0+10.5iWorld\n",123);
    ft_printf("Hello%0+10iWorld\n",123);
    printf("Hello%0+10iWorld\n",123);
    ft_printf("Hello% iWorld\n",123);
    printf("Hello% iWorld\n",123);
    ft_printf("Hello%.iWorld\n",123);
    printf("Hello%.iWorld\n",123);
    ft_printf("Hello%-20iW%iorld\n",123123, -2);
    printf("Hello%0-20iW%iorld\n",123123, -2);
    ft_printf("Hello%.iW%iorld\n",0, -2);
    printf("Hello%0.iW%iorld\n",0, -2);
}