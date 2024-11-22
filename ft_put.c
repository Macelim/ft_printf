#include "ft_printf.h"

ssize_t	ft_putnbr(long nbr)
{
	ssize_t	len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	len += ft_putchar((nbr % 10) + '0');
	return (len);
}

ssize_t	ft_put_u_nbr(unsigned int nbr)
{
	ssize_t	len;

	len = 0;
	if (nbr >= 10)
		len += ft_put_u_nbr(nbr / 10);
	len += ft_putchar((nbr % 10) + '0');
	return (len);
}

ssize_t	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

ssize_t	ft_putstr(char *s)
{
	ssize_t	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (s[len])
		ft_putchar(s[len++]);
	return (len);
}
