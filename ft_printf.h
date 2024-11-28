#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
ssize_t	ft_hexa(unsigned long num, char *base);
ssize_t	ft_adresse(void *addr);
ssize_t	ft_putnbr(long nbr);
ssize_t	ft_put_u_nbr(unsigned int nbr);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *s);
ssize_t	ft_specifi(const char *str, va_list *args);

#endif
