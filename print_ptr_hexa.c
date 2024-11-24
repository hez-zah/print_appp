#include "ft_printf.h"

static	int print_ptr_hex(unsigned long nbr)
{
	int		count;
	char	*symboles;

	symboles = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		count += print_ptr_hex(nbr / 16);
		count += print_ptr_hex(nbr % 16);
	}
	else 
		count += print_char(symboles[nbr % 16]);
	return (count);
}
int	print_ptr(unsigned long nbr)
{
	int count;

	count = 0;
	count += write(1,"0x",2);
	if (nbr == 0)
		count += write(1,"0",1);
	else
	{
		count += print_ptr_hex(nbr);
	}
	return (count);
}
