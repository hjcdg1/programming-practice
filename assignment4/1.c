#include <stdio.h>

int main(void)
{
	char input[1000];
	char c;
	int i=0;
	int j=0;

	while((c=getchar())!=EOF)
		input[i++] = c;

	for(j=0; j<i; j++)
	{
		if(input[j]>='a' && input[j]<='z')
			printf("%c", input[j]-32);
		else if(input[j]>='A' && input[j]<='Z')
			printf("%c", input[j]+32);
	}

	return 0;
}
