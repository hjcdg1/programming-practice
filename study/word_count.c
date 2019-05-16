#include <stdio.h>

int word_cnt(const char *s)
{
	int cnt=0;

	while(*s != '\0'){
		while(isspace(*s))
			s++;

		if(*s != '\0'){
			cnt++;
			while((*s != '\0') && !isspace(*s))
				s++;
		}
	}
	return cnt;
}


int main(void)
{
	char text[] = " Hello World My bro!";

	printf("단어 갯수 : %d\n", word_cnt(text));
	return 0;
}
