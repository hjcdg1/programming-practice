#include <stdio.h>  /* 복습 요망 */

int main(void)
{
	int i, j, n;
	long long int a=1, b=1, c;

	scanf("%d", &n);

	if(n == 0)			printf("0");	
	else if(n == 1)     printf("1");
	else if(n >= 2){
		for(i=0; i<n-1; i++){
			c = a+b;
			a = b;
			b = c;
		}
		printf("%lld", c);
	}
}
