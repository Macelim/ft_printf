#include "ft_printf.h"

ssize_t	ft_hexa(unsigned long num, char *base)
{
	ssize_t	len;

	len = 0;
	if (num >= 16)
		len += ft_hexa(num / 16, base);
	len += ft_putchar(base[num % 16]);
	return (len);
}

ssize_t	ft_adresse(void *addr)
{
	if (!addr)
		return (ft_putstr("0x0"));
	return (ft_putstr("0x") + ft_hexa((unsigned long)addr, "0123456789abcdef"));
}

ssize_t	ft_hexa_conv(unsigned int c, int index)
{
	char	*base;
	size_t	value;

	value = 0;
	if (index == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (c > 15)
	{
		value += ft_hexa_conv(c / 16, index);
		value += ft_hexa_conv(c % 16, index);
	}
	else
	{
		value += ft_putchar(base[c]);
	}
	return (value);
}

ssize_t	ft_specifi(const char *str, va_list *args)
{
	if (*str == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (*str == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (*str == 'p')
		return (ft_adresse(va_arg(*args, void *)));
	if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (*str == 'u')
		return (ft_put_u_nbr(va_arg(*args, unsigned int)));
	if (*str == 'x')
		return (ft_hexa(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (*str == 'X')
		return (ft_hexa(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (*str == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	len;
	ssize_t	ret;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				ret = ft_specifi(format, &args);
			else
				break ;
		}
		else
			ret = ft_putchar(*format);
		if (ret < 0)
			return (va_end(args), -1);
		len += ret;
		format++;
	}
	va_end(args);
	return (len);
}
