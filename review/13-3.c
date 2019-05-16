#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x)>(y))?(x):(y))

int main(void)
{
	int n, i, *arr, *brr, max;
	scanf("%d", &n);
	arr = (int*) malloc((n+1)*sizeof(int));
	brr = (int*) malloc((n+1)*sizeof(int));
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	max = arr[0];
	brr[0] = arr[0];
	for(i=1; i<n; i++){
		brr[i] = max(arr[i], brr[i-1]+arr[i]);
		if(brr[i] > max)
			max = brr[i];
	}

	printf("%d", max);
}
	
