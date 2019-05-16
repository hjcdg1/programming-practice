#include <stdio.h>

int binary_search(int a[], int which, int start, int end)
{
	int middle = (end+start)/2;

	if(end == start)
	{
		if(a[middle] == which)
			return middle;
		else
			return -1;
	}
	else
	{
		if(which <= a[middle])
			binary_search(a, which, start, middle);

		else if (which > a[middle])
			binary_search(a, which, middle+1, end);
	}
}

int main(void)
{
	int i, j;
	int n, q;
	scanf("%d", &n);
	scanf("%d", &q);
	int arr1[n];
	int arr2[q];
	
	for(i=0; i<n; i++)
		scanf("%d", &arr1[i]);
	
	for(i=0; i<q; i++)
		scanf("%d", &arr2[i]);

	for(i=0; i<q; i++)
		printf("%d ", binary_search(arr1, arr2[i], 0, n-1));
	
	return 0;
}

