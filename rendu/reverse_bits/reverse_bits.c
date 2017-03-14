#include <unistd.h>

unsigned char			reverse_bits(unsigned char octet)
{
	int					i;
	int					n;
	int					res;

	n = octet;
	i = 10000000;
	res = 0;
	while (i > 0)
	{
		res = i * n / 2 + res;
		i = i / 10; 
	}
	return ((unsigned char) res);
}
