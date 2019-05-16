#include <stdio.h>
#define MAXDEG 2222

typedef struct poly{
	int n;
	long long coeff[MAXDEG];
} poly;

int main(void)
{
	int i, j;
	poly a, b, c;
	
	scanf("%d %d", &(a.n), &(b.n));
    c.n = a.n + b.n;

    /* 다항식 a와 다항식 b의 계수 입력 */
	for(i=0; i<=(a.n); i++)
		scanf("%lld", &(a.coeff[i]));

	for(i=0; i<=(b.n); i++)
		scanf("%lld", &(b.coeff[i]));

    /* 다항식 c의 초기화 */
	for(i=0; i<=(a.n+b.n); i++)
		c.coeff[i] = 0;

    /* 다항식 c의 계수 계산(a와 b의 곱) */
	for(i=0; i<=(a.n+b.n); i++){
		for(j=0; j<=i; j++)
			if((j <= a.n) && (i-j <= b.n))  /* The most important !! */
				c.coeff[i] += a.coeff[j]*b.coeff[i-j];
    }

    /* 다항식 c의 계수 출력*/
	for(i=0; i<=(a.n+b.n); i++)
		printf("%lld ", c.coeff[i]);
}
