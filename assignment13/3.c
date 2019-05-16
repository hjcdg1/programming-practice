#include <stdio.h>
#define max(x, y) ((x>y)?(x):(y))

int main(void)
{
	int n, i, m=0, a[10000], b[10000];

	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	b[0] = a[0];
	m = a[0];
	for(i=1; i<n; i++){
		b[i] = max(b[i-1]+a[i], a[i]);
		if(b[i] > m)
			m = b[i];
	}
	printf("%d", m);
}
