#include <stdio.h>

long long int combination (int n, int k)
{
	if(k==0)
		return 1;
	else if(k!=0)
	{
		if(n==0)		//	n이 0이고 k가 0이 아닌 경우에 대해 처리를 해주지 않으면, 무한 함수 메모리 할당 -> 메모리 침범 (segmentation fault)
			return 0;	//	재귀함수에서 segmentation fault가 뜨면, 그림을 그려보는 것이 좋다.
		else
			return combination(n-1,k-1) + combination(n-1,k);
	}
}

int main(void)
{
	int input1, input2;
	scanf("%d%d", &input1, &input2);
	printf("%lld", combination(input1, input2));
}
