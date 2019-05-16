#include <stdio.h>

void swap(int* x, int* y)	//	바꾸려는 대상이 int형 변수이기 때문에 int*를 쓴다. 바꾸려는 대상이 char*형 변수라면, char**를 쓴다.
{
	int temp;		//	바꾸려는 대상이 int형 변수이기 때문에 int를 쓴다. 바꾸려는 대상이 char*형 변수라면, char*를 쓴다.
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int  x, y;
	scanf("%d %d", &x, &y);
	swap(&x, &y);
	printf("%d %d", x, y);
	return 0;	
}
