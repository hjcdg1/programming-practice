#include <stdio.h>
#define NUM 100

void insertion_sort(int arr[], int len)	//	이미 정렬된 arr[0]~arr[i-1]에, arr[i]를 알맞는 위치에 삽입시켜 정렬하는 알고리즘
{
	int sorted, temp, i, j;

	for(i=1; i<len; i++)	//	맨 앞에 것은 이미 정렬된 배열로 취급되므로, 두 번째 요소부터 시작한다.
	{
		temp = arr[i];
		for(j=i-1 ; j>=0 && arr[j]>=temp ; j--)		//	내림차순으로 정렬하려면, 여기서 arr[j]<=temp로 바꿔주면 된다.
			arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
}

int main(void)
{
	int arr[NUM];
	int i;

	for(i=0; i<NUM; i++)
		arr[i] = rand()%(NUM);

	insertion_sort(arr, NUM);

	for(i=0; i<NUM; i++)
		printf("%d\n", arr[i]);
}
