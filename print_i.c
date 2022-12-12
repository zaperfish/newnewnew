#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

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

static void putnbr(t_format *f, long n)
{
    if (n > 9 || f->precision > 1)
    {
        f->precision--;
        putnbr(f, n / 10);
    }
    f->len += write(1, &"0123456789"[n % 10], 1);
}

static void l_align(t_format *f, long i)
{
    if (f->prefix)
        f->len += write(1, &f->prefix, 1);
    putnbr(f, i);
    while (f->width - f->len > 0)
        f->len += write(1, " ", 1);
}

static void r_align(t_format *f, long i)
{
    char fill = ' ';
    int occupied;

    if (f->precision == -1 && f->zero)
    {
        fill = '0';
        if (f->prefix)
            f->len += write(1, &f->prefix, 1);
    }
    occupied = 0;
    occupied += nbrlen(i);
    if (f->precision > occupied)
        occupied = f->precision;
    if (f->prefix && !(f->precision == -1 && f->zero))
        occupied++;
    while (f->width - occupied - f->len> 0)
        f->len += write(1, &fill, 1);
    if (!f->zero && f->prefix)
        f->len += write(1, &f->prefix, 1);
    putnbr(f, i);
}

void print_i(t_format *f, int i)
{
    long n;

    n = i;
    if (n < 0)
    {
        f->prefix = '-';
        n = -n;
    }
    else if (f->plus)
        f->prefix = '+';
    else if (f->space)
        f->prefix = ' ';
    if (f->width && f->minus)
        l_align(f, n);
    else
        r_align(f, n);
}