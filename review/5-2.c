#include <stdio.h>

long long int combination (int n, int k)
{
	if(k==0)	return 1;
	else{
		if(n==0)	return 0;
		else
			return (combination(n-1, k-1) + combination(n-1, k));
	}
}

int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%lld", combination(n, k));
}
