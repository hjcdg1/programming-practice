#include <stdio.h>
#define NUM 1000

void selection_sort(int arr[], int len)
{
	int i, j, indexMin, temp;

	for(i=0; i<len-1; i++)
	{
		indexMin = i;
		for(j=i+1; j<len; j++)
		{
			if(arr[j] < arr[indexMin])	//	내림차순으로 하려면, indexMin대신에 indexMax라 하고, 여기서 부등호를 바꾸면 된다.
				indexMin = j;
		}
		temp = arr[indexMin];
		arr[indexMin] = arr[i];
		arr[i] = temp;
	}
}

int main(void)
{
	int i;
	int arr[NUM];

	for(i=0; i<NUM; i++)
		arr[i] = rand()%1000;

	selection_sort(arr, NUM);

	for(i=0; i<NUM; i++)
		printf("%d\n", arr[i]);

	return 0;
}
