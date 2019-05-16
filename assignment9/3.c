#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* temp[10000];

void merge(char* arr[], int start, int mid, int end)
{
	int acnt=0, bcnt=0, ccnt=0;
	int i=0;

	while(acnt < mid && bcnt < end - (start+mid) + 1)
	{
		if(strcmp(arr[start+acnt], arr[start+mid+bcnt])>0)
		{
			strcpy(temp[ccnt++], arr[start+mid+bcnt]);
			bcnt++;
		}
		else
		{
			strcpy(temp[ccnt++], arr[start+acnt]);
			acnt++;
		}
	}

	while(acnt < mid)
	{
		strcpy(temp[ccnt++], arr[start+acnt]);
		acnt++;
	}

	while(bcnt < end - start - mid + 1)
	{
		strcpy(temp[ccnt++], arr[start+mid+bcnt]);
		bcnt++;
	}

	for(i=0; i<end-start+1; i++)
		strcpy(arr[start+i], temp[i]);
}

void mergesort2(char* arr[], int start, int end)
{
	if(end-start+1 < 2)
		return;
	else
	{
		int middle = (end-start+1)/2;
		mergesort2(arr, start, middle+start-1);
		mergesort2(arr, middle+start, end);
		merge(arr, start, middle, end);
	}
}

int main(void)
{
	int i;
	int n;
	scanf("%d", &n);
	char* arr[n];

	for(i=0; i<n; i++)
	{
		arr[i] = (char*) malloc(1000*sizeof(char));
		temp[i] = (char*) malloc(1000*sizeof(char));
	}
	for(i=0; i<n; i++)
		scanf("%s", arr[i]);

	mergesort2(arr, 0, n-1);

	for(i=0; i<n; i++)
		printf("%s ", arr[i]);
}
