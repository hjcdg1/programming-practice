#include <stdio.h>

int main(void)
{
	int n=0, i=0, j=0;
	int k;
	int counter[26];
	char input[200];
	char c;

	while((c=getchar())!=EOF)	//	input[]에 입력받기
		input[n++] = c;
	
	for(j=0;j<26;j++)
		counter[j]=0;		//	counter[] 요소들 모두 일단 0으로 초기화

	for(i=0;i<n;i++)		//	input[]의 글자 수만큼 반복
	{
		if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z'))
		{
			if(input[i]<='Z')		//	대문자라면
				counter[input[i]-'A']++;
			else				//	소문자라면
				counter[input[i]-'a']++;
		}
	}
	
	for(j=0;j<26;j++)
		if(counter[j] != 0)
			printf("%c: %d ", 'a'+j, counter[j]);

	return 0;
}
