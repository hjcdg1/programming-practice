#include <stdio.h>

char unpack(int p, int k)	//	맨 오른쪽 4바이트만 짤려서 char로 변환됨.
{
	int n = k * 8;
	unsigned mask = 255;

	mask <<= n;
	return ((p&mask) >> n);
}

int main(void)
{
	return 0;
}
