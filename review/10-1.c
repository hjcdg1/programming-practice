#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void locate(int* arr, int data, int start, int end)
{
	int middle = (start+end)/2;  /*  홀수면, 중간보다 오른쪽 ㅎㅎ */
	if(start == end){
        if(arr[middle] == data)
            printf("%d ", middle);
        else
            printf("-1 ");
    }
    else{
        if(arr[middle] == data)
            printf("%d ", middle);
        else if(arr[middle] > data)
            locate(arr, data, start, middle);
        else
            locate(arr, data, middle+1, end);
    }
/*
	if(end == start && data == arr[middle])		printf("%d ", middle);
	else if(end == start && data != arr[middle])	printf("-1 ");
	else if(end != start){
		if(data > arr[middle])
			locate(arr, data, middle+1, end);
		else if(data < arr[middle])
			locate(arr, data, start, middle);
		else{
			printf("%d ", middle);
			return;
		}
	}
*/
}

int main(void)
{
	int n, q, i;
	int* arr1 = NULL;
	int* arr2 = NULL;

	scanf("%d%d", &n, &q);
	arr1 = (int*)malloc(n*sizeof(int));
	arr2 = (int*)malloc(q*sizeof(int));

	for(i=0; i<n; i++)
		scanf("%d", &arr1[i]);
	for(i=0; i<q; i++)
		scanf("%d", &arr2[i]);	
	for(i=0; i<q; i++)
		locate(arr1, arr2[i], 0, n-1);
}
