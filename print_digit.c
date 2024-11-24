#include "ft_printf.h"

int	print_digit(int nbr)
{
	int	count;

	count = 0;
	if (nbr == INT_MIN)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nbr < 0)
	{
		count += write(1,"-",1);
		nbr *= -1;
	}
	if (nbr < 10)
		count += print_char(nbr + '0');
	else 
	{
		count += print_digit(nbr / 10);
 		count += print_digit(nbr % 10);
	}
	return (count);
}
