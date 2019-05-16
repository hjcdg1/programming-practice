#include <stdio.h>
#define NUM 1000000

void bubble_sort(int arr[], int len)
{
	int i, j, temp;

	for(i=0; i<len-1; i++)
	{
		for(j=0; j<len-i-1; j++)
		{
			if(arr[j] > arr[j+1])		//	큰 것부터 정렬하려면(내림차순), 부등호를 반대로 하면 된다.
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

/* 다른 방식의 버블 소트
void bubble_sort(int arr[], int len)
{
	int i, j, temp;

	for(i=0; i<len; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
*/

int main(void)
{
	int i, j;
	int arr[NUM];

	for(i=0; i<NUM; i++)
		arr[i] = rand()%1000;

	bubble_sort(arr, NUM);

	for(i=0; i<NUM; i++)
		printf("%d\n", arr[i]);
}
