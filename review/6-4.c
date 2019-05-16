#include <stdio.h>

void swap(int arr[], int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void change(int arr[], int x, int y)
{
	int i;
	for(i=0; arr[i]!='\0' ; i++)
		if(arr[i] == x)	arr[i] = y;
}

void shift(int arr[], int x, int y)
{
	int temp = arr[y];
	int i;
	for(i=y; i>x; i--){
		arr[i] = arr[i-1];
	}
	arr[x] = temp;
}

void sort(int arr[], int x, int y)
{
	int i, j;
	for(i=x; i<=y; i++){
		for(j=i+1; j<=y; j++){
			if(arr[i] > arr[j])
				swap(arr, i, j);
		}
	}
}

int main(void)
{
	int n, q, i, arr[100000], query, x, y;

	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	arr[n] = '\0';
	scanf("%d", &q);

	for(i=0; i<q; i++){
		scanf("%d %d %d", &query, &x, &y);

		switch(query){
			case 0:
				swap(arr, x, y);
				break;
			case 1:
				change(arr, x, y);
				break;
			case 2:
				shift(arr, x, y);
				break;
			case 3:
				sort(arr, x, y);
				break;
		}
	}

	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
}
