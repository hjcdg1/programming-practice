#include <stdio.h>

long long int fibo(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
	{
		long long int a=0;
		long long int b=1;
		long long int c;
		long long int i;

		for(i=0; i<n-1; i++)
		{
			c=a+b;
			a=b;
			b=c;
		}
		return c;
	}
}

int main(void)
{
	int input;
	scanf("%d", &input);
	printf("%lld", fibo(input));
}
