#include <stdio.h>

int main(void)
{
	int input;
	double sum=0.0;
	int i=0;
	int max=-1;
	int max2=-1;
	int max3=-1;

	printf("0과 2147483647 사이의 값을 입력하세요.\n");
	while((scanf("%d", &input))!=EOF)
	{
		if (input>max)					//	max1~maxn까지 구해야하는 상황이라면 if문은 총 n개만큼이 필요하다
			max3=max2, max2=max, max=input;
		else if (input<max && input>max2)
			max3=max2, max2=input;
		else if (input<max2 && input>max3)
			max3=input;

		i++;	//	i는 입력 횟수 (총 input이 몇 번 들어왔는가)
		sum += input;
	}

	printf("제일 큰 숫자 : %d\n", max);
	printf("2번째로 큰 숫자 : %d\n", max2);
	printf("3번째로 큰 숫자 : %d\n", max3);
	printf("입력된 숫자들의 평균 : %f\n", sum/i);
	
	return 0;
}
