#include <stdio.h>

int main(void)
{
	char text[256] = "C is a general-purpose, imperative computer programming language, supporting structured programming, lexical variable scope and recursion, while a static type system prevents many unintended operations.";
	char input[10];
	char c;
	int state=0;
	int i=0, j=0;
	int n;
	int counter=0;

	while((c=getchar())!=EOF)	// 입력 패턴 받기
	{
		if(c<='z' && c>= 'a')
			input[i++] = c;
		else if(c<='Z' && c>= 'A')
			input[i++] = c+32;	//	소문자의 아스키 코드에 맞춰주자
	}

	for(n=0; n<256; n++)
	{
		for(j=0; j<i; j++)
		{
			if(state == j)
			{
					if(text[n] == input[state] || text[n] == input[state]-32)
					{
						if(j == i-1)
						{
							state=0;
							counter++;
							break;	// break가 필수
						}
						else
						{
							state++;
							break;	// break가 필수
						}
					}
					else
					{
						state=0;
						break;		// break가 필수
					}
			}
		}

		/*
		if(state == 0)
		{
			if(text[n] == input[state] || text[n] == input[state] - 32)
				state++;
			else
				state = 0;
		}
		else if(state == 1)
		{
			if(text[n] == input[state] || text[n] == input[state] - 32)
				state++;
			else
				state = 0;
		}
		else if(state == 2)
		{
			if(text[n] == input[state] || text[n] == input[state] - 32)
			{
				state=0;
				counter++;
			}
			else
				state = 0;
		}*/
	}

	printf(" %d\n", counter);

	return 0;
}
