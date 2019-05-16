#include <stdio.h>

int main(void)
{
	char input[10000];
	const int d = 'a'-'A';
	int i=0;

	scanf("%s", input);
	while(input[i] != '\0'){
		if(input[i] >= 'A' && input[i] <= 'Z')
			printf("%c", input[i++]+d);
		else
			printf("%c", input[i++]-d);
	}
	
}
