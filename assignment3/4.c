#include <stdio.h>

int main(void)
{
	char a[1000];
	char c;
	int i=0;
	int j=0;
	int value=1;

	while((c=getchar())!=EOF)		//	입력받기 (insensitive)
	{
		if(c>='a' && c<= 'z')
			a[i++] = c-'a';

		else if(c>='A' && c<= 'Z')
			a[i++] = c-'A';
	}

	for(j=0; j < i-j-1 ; j++)		//	매 순간 a[j]와 a[i-j-1]을 비교할 것이므로 조건문을 이러하게
	{
		if(a[j] == a[i-j-1])
			value = 1;
		else
		{
			value = 0;
			break;		//	꼭 필요
		}
	}

	if(value == 1)		printf("True\n");
	else if(value == 0) 	printf("False\n");

	return 0;
}
