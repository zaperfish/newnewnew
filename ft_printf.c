#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

t_format *initF(t_format *f)
{
    f->len = 0;
    f->width = 0;
    f->precision = -1;
    f->hash = 0;
    f->zero = 0;
    f->minus = 0;
    f->space = 0;
    f->plus = 0;
    f->prefix = 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int print_len;
    t_format f;

    print_len = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            initF(&f);
            format += ft_eval_format(&f, &args, format + 1);
            print_len += f.len;
        }
        else
            print_len += write(1, format, 1);
        format++;
    }
    va_end(args);
    return (print_len);
}