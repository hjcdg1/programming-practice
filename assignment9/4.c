#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentindex=0;
void swap(char** a, char** b);

void sort(char** realtext)
{
	int i, j;

	for(i=0; i<currentindex-1; i++)
	{
		for(j=0; j<currentindex-1-i; j++)
		{
			if(strcmp(realtext[j], realtext[j+1])>0)
				swap(&realtext[j], &realtext[j+1]);
		}
	}
}

void swap(char** a, char** b)
{
	char* temp = *a;
	*a = *b;
	*b = temp;
}

void insert(char** realtext, char* tempword)
{
	int i=0, j=0;
	int state = 1;
	
	scanf("%s", tempword);

	state=1;

	for(j=0; j<currentindex; j++)
	{
		if(strcmp(realtext[j], tempword) == 0)
		{
			state = 0;
			break;
		}
	}
	if(state == 1)
	{
		realtext[currentindex] = (char*)malloc(10000*sizeof(char));
		strcpy(realtext[currentindex++], tempword);
	}
}

void fdelete(char** realtext, char* tempword)
{
	int j=0, k=0;

	scanf("%s", tempword);

	for(j=0; j<currentindex; j++)
	{
		if(strcmp(realtext[j], tempword) == 0)
		{
			for(k=0; j+k+1<currentindex; k++)
				realtext[j+k] = realtext[j+k+1];
			currentindex--;
		}
	}
}

void find(char** realtext, char* tempword)
{
	int i, j, state=0;

	scanf("%s", tempword);	//	tempword에 찾을 단어 넣어두기

	sort(realtext);
	for(i=0; i<currentindex; i++)
	{
		if(strcmp(realtext[i], tempword) == 0)
		{
			printf("%d\n", i);
			state = 1;
		}
	}
	if(state == 0)	printf("-1\n");
}

void print(char** realtext)
{
	int i, j;
	
	sort(realtext);
	for(i=0; i<currentindex; i++)
		printf("%s ", realtext[i]);
	printf("\n");
}

int main(void)
{
	char* realtext[10000];
	char tempword[1000], q[200];
	int n, i;

	scanf("%d", &n);

	for(i=0; i<n; i++)
	{	
		scanf("%s", q);

		if(q[0] == 'i')
			insert(realtext, tempword);
		else if(q[0] == 'd')
			fdelete(realtext, tempword);
		else if(q[0] == 'f')
			find(realtext, tempword);
		else if(q[0] == 'p')
			print(realtext);
	}

	return 0;
}
