#include <stdio.h>

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubblesort(int a[], int n)		//	int a[]대신 int* a를 써도 같다.
{
	int i, j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
				swap(a+j, a+j+1);	//	a+j대신 &a[j]를, a+j+1대신 &a[j+1]를 써도 같다.
		}
	}
}

int main(void)
{
	int i;
	int n;
	scanf("%d", &n);
	int a[n];

	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	bubblesort(a, n);
	
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
}
