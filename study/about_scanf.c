#include <stdio.h>

int main(void)
{
	int n;
	char c;

	scanf("%d", &n);
	//1. scanf("%c", &c);	// 1번을 쓰면, 앞에서 scanf로 정수하나를 읽어들인 후에 입력버퍼에 남아있는 개행 문자를 자동으로 읽어들인다.
	//2. scanf(" %c", &c);	// 2번을 쓰면, 남아있던 개행문자를 무시할 수 있게 된다.

	return 0;
}
