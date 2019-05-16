#include <stdio.h>
#include <stdio.h>
#define NUM 1000000

/* 한 번 호출할 때마다, 피벗 왼쪽엔 피벗보다 작은 수들이, 오른쪽엔 피벗보다 큰 수들이 존재 */
void quick_sort(int arr[], int start, int end)
{
	int i, j, pivot, temp;
	
	i = start;
	j = end;
	pivot = arr[(start+end)/2];

	while(i <= j)			//	i가 j보다 작아질 때(즉, 피벗 기준으로 왼쪽엔 작은 것, 오른쪽엔 큰 것이 정렬 완료) 빠져나온다.
	{
		while(arr[i] < pivot)	//	내림차순으로 하려면 여기를 >로
			i++;
		while(arr[j] > pivot)	//	여기를 <로 하면 된다.
			j--;
		if(i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
    
	if(j > start)		//	만약 피벗이 맨 왼쪽에 위치해있다면(가장 작은 값이라면), j가 곧 start이므로, 호출해줄 필요 없다.
		quick_sort(arr, start, j);
	if(i < end)			//	만약 피벗이 맨 오른쪽에 위치해있다면(가장 큰 값이라면), i가 곧 end이므로, 호출해줄 필요 없다.
		quick_sort(arr, i, end);
}

int main(void)
{
	int arr[NUM];// = {3,7,1,2,5,10,2,11,4,6};
	int i;

	for(i=0; i<NUM; i++)
		arr[i] = rand()%NUM;

	quick_sort(arr, 0, NUM-1);
	
	for(i=0; i<NUM; i++)
		printf("%d\n",arr[i]);

	return 0;
}
