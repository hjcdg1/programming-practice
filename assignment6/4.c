#include <stdio.h>

void fswap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void fchange(int x, int y, int* arr, int n)
{
	int j;
	for(j=0; j<n; j++)
		if(arr[j]==x)
			arr[j] = y;
}

void fshift(int x, int y, int* a)
{
	int i;
	int temp = a[y];

	for(i=0; i<y-x; i++)
		a[y-i] = a[y-i-1];

	a[x] = temp;
}

void fsort(int x, int y, int a[])
{
	int i, j;
	
	for(i=0; i<y-x; i++)
	{
		for(j=0; j<y-x-i; j++)
		{
			if(a[x+j]>a[x+j+1])
				fswap(a+x+j, a+x+j+1);
		}
	}
}

int main(void)
{
	int n, i, k;
	int A[501];
	int qn;
	int q[3];

	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", &A[i]);

	scanf("%d", &qn);

	for(k=0; k<qn; k++)
	{
		for(i=0;i<3;i++)
			scanf("%d", &q[i]);

		if(q[0]==0)
			fswap(&A[q[1]], &A[q[2]]);

		else if(q[0]==1)
			fchange(q[1], q[2], A, n);
		
		else if(q[0]==2)
			fshift(q[1], q[2], A);
		
		else if(q[0]==3)
			fsort(q[1], q[2], A);
	}


	for (i=0;i<n;i++)
		printf("%d ", A[i]);
}
