#include <stdio.h>

void print_bit(int a)
{
	int i;
	int n = sizeof(int)*8;
	int mask = 1 << (n-1);

	for(i=1; i<=n; i++)
	{
		putchar(((a & mask) == 0) ? '0' : '1');
		a <<= 1;
		if(i%8 == 0 && i<n)
			putchar(' ');
	}
}

int main(void)
{	
	return 0;
}
