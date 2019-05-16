#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i=0, j, k;
	int** a = NULL;
	int** b = NULL;
	int** c = NULL;

	scanf("%d", &n);
	a = (int**)malloc(n*sizeof(int*));
	b = (int**)malloc(n*sizeof(int*));
	c = (int**)malloc(n*sizeof(int*));

	for(i=0; i<n; i++){
		a[i] = (int*)malloc(n*sizeof(int));
		b[i] = (int*)malloc(n*sizeof(int));
		c[i] = (int*)malloc(n*sizeof(int));
	}

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &b[i][j]);

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			c[i][j] = 0;
			for(k=0; k<n; k++)
				c[i][j] += a[i][k]*b[k][j];
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n-1; j++)
			printf("%d ", c[i][j]);
		printf("%d\n", c[i][n-1]);
	}
}
