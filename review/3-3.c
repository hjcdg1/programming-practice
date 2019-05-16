#include <stdio.h>

int main(void)
{
	int arr[1001];
	int i=0, j;

	while(scanf("%d", &arr[i]) != EOF){
		i++;
	}

	for(j=0; j<i; j++)
		printf("%d ", arr[i-1-j]);
}
