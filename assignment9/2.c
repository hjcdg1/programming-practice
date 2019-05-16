#include <stdio.h>

void merge(int arr[], int start, int mid, int end)
{
	int acnt=0, bcnt=0, ccnt=0;	//	왼쪽 배열의 길이는 mid, 오른쪽 배열의 길이는 end-(middle+start)+1
	int i;
	int temp[10000];

	while(acnt<mid && bcnt <end-(mid+start)+1)
	{
		if(arr[start+acnt] <= arr[mid+start+bcnt])
		{
			temp[ccnt++] = arr[mid+start+bcnt];
			bcnt++;
		}
		else
		{
			temp[ccnt++] = arr[start+acnt];
			acnt++;
		}
	}

	while(acnt < mid)
	{
		temp[ccnt++] = arr[start+acnt];
		acnt++;
	}
	while(bcnt < end-(mid+start)+1)
	{
		temp[ccnt++] = arr[mid+start+bcnt];
		bcnt++;
	}

	for(i=0; i<end-start+1; i++)
		arr[start+i] = temp[i];
}

void mergesort(int arr[], int start, int end)
{
	if(end-start+1 < 2)	//	길이가 2 미만이면 그냥 함수 반환
		return;
	else
	{
		int middle = (end-start+1)/2;
		mergesort(arr, start, middle+start-1);
		mergesort(arr, middle+start, end);
		merge(arr, start, middle, end);
	}
}

int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	int arr[n];

	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	mergesort(arr, 0, n-1);

	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
}
