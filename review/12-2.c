#include <stdio.h>
#define MAXDEG 2222

typedef struct poly {
	int n;
	long long coeff[MAXDEG];
} poly;

int main(void)
{
	int n, m, i, j;
	poly f, g, fg;
	scanf("%d%d", &(f.n), &(g.n));
	fg.n = f.n + g.n;

	for(i=0; i<=f.n; i++)
		scanf("%lld", &(f.coeff[i]));
	for(i=0; i<=g.n; i++)
		scanf("%lld", &(g.coeff[i]));
	for(i=0; i<=fg.n; i++){
		fg.coeff[i] = 0;
		for(j=0; j<=i; j++){
			if(i-j <= g.n)
				fg.coeff[i] += (f.coeff[j]) * (g.coeff[i-j]);
		}
	}
	for(i=0; i<=fg.n; i++)
		printf("%lld ", fg.coeff[i]);
}
