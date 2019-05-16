#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int arr[], int start, int end)
{
	if(end > start + 1)
	{
		int pivot = arr[start];
		int left = start + 1;
		int right = end;
		
		while(left < right)
		{
			if(arr[left] <= pivot)
				left++;
			else
				swap(&arr[left], &arr[--right]);
		}
		swap(&arr[--left], &arr[start]);
		sort(arr, start, left);
		sort(arr, right, end);
	}
}
