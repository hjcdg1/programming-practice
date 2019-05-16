#include <stdio.h>

void bubblesort(int *arr, int n)
{
	int temp;
	int i, j;

	for(i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(void)
{
	int n, i, arr[10000];

	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	bubblesort(arr, n);
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
}
