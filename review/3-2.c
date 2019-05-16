#include <stdio.h>
#include <string.h>

int main(void)
{
	char text[10000] = "C is a general-purpose, imperative computer programming language, supporting structured programming, lexical variable scope and recursion, while a static type system prevents many unintended operations.";
	char pattern[4];
	int cnt=0;
	int i, j;
	int value;
	int textlen = strlen(text);

	scanf("%s", pattern);
	
	for(i=0; i<textlen-2; i++ ){
		for(j=0; j<3; j++){
			if(pattern[j] == text[i+j])
				value = 1;
			else{
				value = 0;
				break;
			}
		}
		if(value == 1)	cnt++;
	}

	printf("%d", cnt);
}
