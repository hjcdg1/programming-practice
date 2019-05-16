#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[1001];
	int value;
	int i;

	scanf("%s", input);
	for(i=0; i<strlen(input); i++){
		if(input[i] == input[strlen(input)-1-i])
			value = 1;
		else{
			value = 0;
			break;
		}
	}

	if(value == 0)	printf("False");
	else		printf("True");
}
