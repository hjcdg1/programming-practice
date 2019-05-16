#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int middle, int end)
{
	int* temp = (int*) malloc((end-start+1)*sizeof(int));
	int a_cnt = 0, b_cnt = 0, c_cnt = 0;
	int a_len = middle - start + 1;
	int b_len = end - middle;
	int i;

	while(a_cnt<a_len && b_cnt<b_len){
		if(arr[start + a_cnt] > arr[middle + 1 + b_cnt])
			temp[c_cnt++] = arr[start + a_cnt++];
		else
			temp[c_cnt++] = arr[middle + 1+ b_cnt++];
	}

	while(a_cnt < a_len)
		temp[c_cnt++] = arr[start + a_cnt++];
	while(b_cnt < b_len)
		temp[c_cnt++] = arr[middle + 1 + b_cnt++];

	for(i=0; i< end-start+1; i++)
		arr[start+i] = temp[i];
	free(temp);
}

void mergesort(int* arr, int start, int end)	//	mergesort 의 역할 : 그 부분의 배열을 정렬
{
	int middle;
	if(end-start == 0)	return;
	else{
		middle = (end+start)/2;
		mergesort(arr, start, middle);
		mergesort(arr, middle+1, end);
		merge(arr, start, middle, end);
	}
}

int main(void)
{
	int n,i;
	int* arr;

	scanf("%d", &n);
	arr = (int*) malloc(n*sizeof(int));
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	mergesort(arr, 0, n-1);
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
}
