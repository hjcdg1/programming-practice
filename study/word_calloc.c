#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 20
#define N 5

void swap(char** p, char** q)	//	바꾸고자 하는 대상이 포인터 변수!!! 그런데 바꾸려면 바꾸고자 하는 대상으 주소값을 받아야 함! 포인터 변수의 주소값이므로 char**
{
	char* temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

void sort_words(char** w, int n)	//	
{
	int i, j;

	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(strcmp(w[j], w[j+1]) > 0)
				swap(&w[j], &w[j+1]);
}

void wrt_words(char** w, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%s\n", w[i]);
	}
}

int main(void)
{
	char word[MAXWORD];
	char *w[N];
	int n;
	int i;

	for(i=0; scanf("%s", word) == 1; ++i)
	{
		if(i>=N)
		{
			printf("Error: There are many words.\n");
			break;
		}

		if(strlen(word) >= MAXWORD)
		{
			printf("Error: There is a word too long.\n");
			i--;
			continue;
		}
		
		w[i] = (char*)calloc(strlen(word)+1, sizeof(char));	//	널문자를 위해 실제 길이보다 1만큼 긴 공간을 할당해야 함

		if(w[i] == NULL)
		{
			printf("Error: Calloc failed.\n");
			i--;
			continue;
		}

		strcpy(w[i], word);	//	word가 가리키는 공간부터 시작해서 널문자를 만날 때까지의 배열들을 w[i]에 갖다 붙임
	}

	n = i;		//	word 수를 n이라 하자

	sort_words(w, n);
	wrt_words(w, n);

	return 0;
}
