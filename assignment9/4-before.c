#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentindex = 0;

int input(char** word, char* temp)
{
	char c;
	int n=0, k=0, i=0, j=0;
	int templen;

	while((c=getchar())!='\n')
		temp[n++] = c;
	templen = n;
	temp[templen] = '\0';

	for(j=0; j<templen; j++)
		if(temp[j] == ' ')
			temp[j] = '\0';

	while(i<templen)
	{
		while(temp[i] == '\0')
			i++;
		word[k] = (char*)malloc(1000*sizeof(char));
		strcpy(word[k++], &temp[i]);
		while(temp[i] != '\0')
			i++;
	}

	return k;
}

void swap(char** p, char** q)
{
	char *temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void print(char** realtext)
{
	int i=0, j=0;

	for(i=0; i<currentindex-1; i++)
	{
		for(j=0; j<currentindex-i-1; j++)
		{
			if(strcmp(realtext[j], realtext[j+1])>0)
				swap(&realtext[j], &realtext[j+1]);
		}
	}

	for(i=0; i<currentindex; i++)
		printf("%s ", realtext[i]);

	printf("\n");
}

void insert(char** word, char** realtext, char* temp)
{
	int j=0, m=0, k;
	int state=1;

	k=input(word, temp);

	for(m=0; m<k; m++)
	{
		state = 1;
		for(j=0; j<currentindex; j++)
		{
			if(strcmp(realtext[j], word[m])==0)
			{
				state=0;
				break;
			}
		}
		if(state==1)
		{
			realtext[currentindex] = (char*)malloc(1000*sizeof(char));
			strcpy(realtext[currentindex++], word[m]);
		}
		free(word[m]);
	}
}

void fdelete(char** word, char** realtext, char* temp)
{
	int j=0, m=0, l=0, k;

	k = input(word, temp);
	
	for(m=0; m<k; m++)
	{
		for(l=0; l<currentindex; l++)
		{
			if(strcmp(word[m], realtext[l]) == 0)
			{
				for(j=0; l+j+1<currentindex; j++)
					realtext[l+j] = realtext[l+j+1];
				currentindex--;
			}
		}
	}
}

void find(char** realtext, char* temp)
{
	int n=0, i=0, j=0, state=0;

	scanf("%s", temp);

	for(i=0; i<currentindex; i++)
	{
		for(j=0; j<currentindex-1-i; j++)
		{
			if(strcmp(realtext[j], realtext[j+1])>0)
				swap(&realtext[j], &realtext[j+1]);
		}
	}

	for(i=0; i<currentindex; i++)
	{
		if(strcmp(temp, realtext[i])==0)
		{
			printf("%d\n", i);
			state=1;
		}
	}
	if(state==0)	printf("-1\n");
}

int main(void)
{
	char q[1000];
	char* word[1000];
	char* realtext[1000];
	char temp[1000];
	int n;
	int i=0;
	int currentindex=0;

	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%s", q);

		if(q[0] == 'i')
			insert(word, realtext, temp);
		else if(q[0] == 'd')
			fdelete(word, realtext, temp);
		else if(q[0] == 'f')
			find(realtext, temp);
		else if(q[0] == 'p')
			print(realtext);
	}

	for(i=0; i<currentindex; i++)
		free(realtext[i]);
}
