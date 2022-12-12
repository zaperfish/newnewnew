#include <stdio.h>
#include "ft_printf.h"
#include "../libft/libft.h"
static int nbrlen(long n)
{
    int len;

    if (n == 0)
        return (1);
    len = 0;
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}

static int ft_flags(t_format *f, const char* format)
{
    int i;

    i = 0;
    while (format[i])
    {
        if (format[i] == '-')
            f->minus = 1;
        else if (format[i] == '0')
            f->zero = 1;
        else if (format[i] == '#')
            f->hash = 1;
        else if (format[i] == ' ')
            f->space = 1;
        else if (format[i] == '+')
            f->plus = 1;
        else
            break;
        i++;
    }
    return (i);
}

static int ft_width(t_format *f, const char* format)
{
    f->width = ft_atoi(format);
    if(f->width == 0)
        return (0);
    return (nbrlen(f->width));
}

static int ft_precision(t_format *f, const char *format)
{
    int i;

    i = 0;
    if (format[i] == '.')
    {
        f->precision = ft_atoi(&format[i + 1]);
        if (ft_isdigit(format[i + 1]))
            i++;
        i += nbrlen(f->precision);
    }
    return (i);
}

void ft_print_c(t_format *f, int n)
{

}
void ft_print_s(t_format *f, const char *str)
{

}
void ft_print_p(t_format *f, unsigned long n)
{

}

static int ft_type(t_format *f, const char *format, va_list *args)
{
    if(*format == 'c')
        ft_print_c(f, va_arg(*args, int));
    else if(*format == 's')
        ft_print_s(f, va_arg(*args, const char *));
    else if(*format == 'p')
        ft_print_p(f, va_arg(*args, unsigned long));
    else if(*format == 'd' || *format == 'i')
        print_i(f, va_arg(*args, int));
    // else if(*format == 'u')
    //     ft_print_u(f, va_arg(*args, unsigned int));
    // else if(*format == 'x' || *format == 'X')
    //     ft_print_x(f, va_arg(*args, unsigned int));
    // else if(*format == '%')
    //     ft_print_percent(f);
    return (1);
}

int ft_eval_format(t_format *f, va_list *args, const char *format)
{
    int len;

    len = 0;
    len += ft_flags(f, format);
    len += ft_width(f, format + len);
    len += ft_precision(f, format + len);
    len += ft_type(f, format + len, args);
    //printf("f->pre = %i\n", f->precision);
    return (len);
}