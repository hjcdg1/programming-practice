#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n, i, j, k;
	scanf("%d", &n);
	int a[n][n];
	int b[n][n];
	int c[n][n];
	
	for(i=0; i<n; i++)			//	행렬 A 입력받기
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	for(i=0; i<n; i++)			//	행렬 B 입력받기
	        for(j=0; j<n; j++)
	                scanf("%d", &b[i][j]);

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			c[i][j]=0;
			for(k=0; k<n; k++)
				c[i][j] += a[i][k]*b[k][j];	//	행렬 곱셈
		}
	}

	for(i=0; i<n; i++)
	{
		for(j=0; j<n-1; j++)
			printf("%d ", c[i][j]);
		printf("%d\n", c[i][n-1]);
	}
}
