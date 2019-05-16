#include <stdio.h>

int main(void)
{
	int input1, input2;
	
	do
	{
		printf("0과 10사이의 두 수를 입력해주세요.\n");
		scanf("%d %d", &input1, &input2);
	} while(input1>=10 || input2>=10 || input1<=0 || input2<=0);	//	0과 10 사이의 수를 입력한 게 아니라면, 다시 입력을 받아야겠지?
	
	printf("입력한 두 수의 합 = %d\n", input1+input2);

	return 0;
}
