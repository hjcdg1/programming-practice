#include <stdio.h>

int main(void)
{
	int input[1000];
	int temp;
	int len=0;
	int i=0;

	while((scanf("%d", &input[len]))!=EOF)	//  입력받기
		len++;

	for(i=0 ; len-2*i > 1 ; i++)		//  input[i] 와 input[len-1-i] 를 바꿔가는 작업이므로, i<len-1-i 일때까지만 for문을 돌린다.
	{
		temp = input[len-i-1];
		input[len-i-1] = input[i];
		input[i] = temp;
	}
	
	for(i=0;i<len;i++)
		printf("%d ", input[i]);
	
	printf("\n");

	return 0;
}
