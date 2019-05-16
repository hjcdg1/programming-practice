#include <stdio.h>

int pack (char a, char b, char c, char d)
{
	int p = a;

	p = (p << 8) | b;
	p = (p << 8) | c;
	p = (p << 8) | d;
	return p;
}

int main(void)
{
	return 0;
}
