#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void snail(int** a, int x, int y, int n, int num)
{
	int i;

	if(n <= 0)	
		return;

	else{
		for(i=y; i<=y+n-1; i++)
			a[x][i] = num++;
		for(i=x+1; i<=x+n-1; i++)
			a[i][y+n-1] = num++;
		for(i=y+n-2; i>=y; i--)
			a[x+n-1][i] = num++;
		for(i=x+n-2; i>=x+1; i--)
			a[i][y] = num++;
		snail(a, x+1, y+1, n-2, num);		
	}
}

int main(void)
{
	int n, i, j;
	int** a;
	int num=1;

    /* 2차원 배열 동적 할당 */
	scanf("%d", &n);
	a = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
		a[i] = (int*)malloc(n*sizeof(int));

	snail(a, 0, 0, n, num);

	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}	
