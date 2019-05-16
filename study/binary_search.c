#include <stdio.h>
#define NUM 100

void binary_search(int* array, int start, int num, int f)
{
	if(num == 1)
	{
		if(array[start] == f)
		{
			printf("I found it!!!\n");
			return;
		}
	}
	else
	{
		int middle = num/2;	//   5개면, 앞에 2개, 뒤에 3개로 나눔
		binary_search(array, start, middle, f);
		binary_search(array, start+middle, num-middle, f);
	}
}

int main(void)
{
	int array[NUM];
	int f;

	printf("Enter a number to search: ");
	scanf("%d", &f);

	binary_search(array, 0, NUM, f);
}
