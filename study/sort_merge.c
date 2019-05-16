#include <stdio.h>
#include <stdlib.h>
#define NUM 1000000

void merge (int a[], int b[], int m, int n)
{
	int temp[NUM];
	int cnt_a=0, cnt_b=0, cnt_sum=0;
	int i;

	while(cnt_a<m && cnt_b<n)
	{
		if(a[cnt_a] <= b[cnt_b])		//	내림차순으로 하려면, 부등호만 바꿔주면 된다.
			temp[cnt_sum++] = a[cnt_a++];
		else
			temp[cnt_sum++] = b[cnt_b++];
	}

	while(cnt_a<m)
		temp[cnt_sum++] = a[cnt_a++];
	while(cnt_b<n)
		temp[cnt_sum++] = b[cnt_b++];

	for(i=0; i<m+n; i++)
		a[i] = temp[i];
}

void merge_sort (int array[], int p, int n)
{
	if (n<2)	return;
	else
	{
		int middle = n/2;

		merge_sort(array, p, middle);
		merge_sort(array, p+middle, n-middle);
		merge(array+p, array+p+middle, middle, n-middle);
	}
}

int main(void)
{
	int array[NUM];
	int i, j;

	for(i=0; i<NUM; i++)
		array[i] = rand()%(NUM);
	
	merge_sort(array, 0, NUM);

	for(i=0; i<NUM; i++)
		printf("%d\n", array[i]);
}
