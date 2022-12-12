#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

typedef struct s_format
{
    int len;
    int width;
    int precision;
    int hash;
    int zero;
    int minus;
    int space;
    int plus;
    int prefix;
}t_format;

int ft_printf(const char *format, ...);
void print_i(t_format *f, int i);
int ft_eval_format(t_format *f, va_list *args, const char *format);

#endif