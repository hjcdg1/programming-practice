#include <stdio.h>

int fibo1(int n)			//	for문으로 피보나치 수열 구현 (Good)
{
	if (n==0 || n==1)	//	f(0)=f(1)=1
		return 1;
	else			//	f(n)=f(n-1)+f(n-2)  (n이 0 혹은 1이 아닐 때)
	{
		int a=1;	//	else문을 빠져나가면 소멸되는 scope의 변수들을 선언
		int b=1;
		int c;
		int i;

		for(i=0; i<n-1; i++)	//	n=2일 땐 한 번 반복하고, n=3일 땐 두 번 반복해야되니까.... i<n-1이네!
		{
			c=a+b;
			a=b;		//	a=b; 와 b=c;의 순서는 절대로 바뀌어서는 안됨
			b=c;
		}

		return c;
	}
}

int fibo2(int n)			//	재귀함수로 피보나치 수열 구현 (Bad)
{
	if(n==0 | n==1)				//	f(0)=f(1)=1
		return 1;
	else
		return fibo2(n-1) + fibo2(n-2);	//	f(n)=f(n-1)+f(n-2)
}

int main(void)
{
	int i;

	for(i=0;i<20;i++)
	{
		printf("%d\n", fibo2(i));
	}
}
