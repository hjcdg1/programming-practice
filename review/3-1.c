#include <stdio.h>

int main(void)
{
	const int d = 'a'-'A';
	char input[100];
	int cnt[30];
	int i, j=0;

	scanf("%s", input);
	for(i=0; i<30; i++)
		cnt[i] = 0;

	while(input[j] != '\0'){
		if(input[j]>='a' && input[j]<='z')
			cnt[input[j++]-'a']++;
		else
			cnt[input[j++]-'A']++;
	}
	
	for(i=0; i<30; i++)
		if(cnt[i] != 0)
			printf("%c: %d ", 'a'+i, cnt[i]);
}
