#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentindex = 0;

int input(char** word, char* temp)	//	각 quiery마다 입력받는 줄에 존재하는 단어들을 word배열에 저장한다. ex> word[2]는 그 줄의 세번째 단어의 첫번째 글자가 저장된 공간의 주소.
{
	char c;
	int n=0, k=0, i=0, j=0;
	int templen;
	
	while((c=getchar())!='\n')
		temp[n++]=c;
	templen = n;
	temp[templen] = '\0';
	
	for(j=0; j<templen; j++)
	{
		if(temp[j] == ' ')
			temp[j] = '\0';
	}
	
	while(i<templen)
	{
		while(temp[i] == '\0')
			i++;
		word[k] = (char*)malloc(100*sizeof(char));
		strcpy(word[k++], &temp[i]);
		while(temp[i] != '\0')
			i++;
	}

	return k;
}


void swap(char** p, char** q)		//	바꾸려는 대상이 char* 변수이므로 char**을 써야 한다.
{
	char *temp;			//	바꾸려는 대상이 char* 변수이므로 char*을 써야 한다.

	temp=*p;
	*p=*q;
	*q=temp;
}


void print(char** realtext)		//	print 함수 : 버블소트로 정렬 후 출력
{
	int i=0, j=0;

	for(i=0; i<currentindex-1; i++)
	{
		for(j=0; j<currentindex-i-1; j++)
		{
			if(strlen(realtext[j])>strlen(realtext[j+1]))
				swap(&realtext[j], &realtext[j+1]);
			else if(strlen(realtext[j])==strlen(realtext[j+1]))
			{
				if(strcmp(realtext[j], realtext[j+1])>0)
					swap(&realtext[j], &realtext[j+1]);
			}
		}
	}

	for(i=0; i<currentindex; i++)
		printf("%s ", realtext[i]);
	printf("\n");
}


void insert(char** word, char** realtext, char* temp)	//	insert 함수 : word[m]이 이미 존재하는 지 확인하고, 존재하지 않는 건 삽입
{
	int j=0, m=0, k;
	int state=1;
	
	k = input(word, temp);

	for(m=0; m<k; m++)
	{
		state=1;

		for(j=0; j<currentindex; j++)
		{
			if(strcmp(realtext[j],word[m])==0)
			{
				state=0;
				break;
			}
		}

		if(state==1)
		{
			realtext[currentindex] = (char*)malloc(100*sizeof(char));
			strcpy(realtext[currentindex++],word[m]);
		}

		free(word[m]);
	}
}


void delete(char** word, char** realtext, char* temp)	//	word[m]에 해당하는 걸 찾아 삭제(그 오른쪽에 있는 것들의 인덱스는 모두 1씩 감소시켜 왼쪽으로 땡기기)
{
	int j=0, m=0, l=0, k;

	k = input(word, temp);
	
	for(m=0; m<k; m++)
	{
		for(l=0; l<currentindex; l++)
		{
			if(strcmp(word[m],realtext[l]) == 0)
			{
				for(j=0; l+j+1<currentindex; j++)
					realtext[l+j]=realtext[l+j+1];
				currentindex--;
			}
		}
	}
}


void find(char** word, char** realtext, char* temp)	//	word[0]에 찾을 단어의 첫 글자 공간 주소값을 저장 -> 버블소트로 정렬한 후 찾을 단어가 몇 번째 인덱스에 있는지 출력
{
	char c;
	int n=0, i=0, j=0;
	int templen;
	
	scanf("%s", temp);
	
	word[0] = (char*)malloc(100*sizeof(char));
	strcpy(word[0], temp);

	for(i=0; i<currentindex-1; i++)
	{
		for(j=0; j<currentindex-i-1; j++)
		{
			if(strlen(realtext[j])>strlen(realtext[j+1]))
				swap(&realtext[j], &realtext[j+1]);
			else if(strlen(realtext[j])==strlen(realtext[j+1]))
			{
				if(strcmp(realtext[j], realtext[j+1])>0)
					swap(&realtext[j], &realtext[j+1]);
			}
		}
	}

	for(i=0; i<currentindex; i++)
	{
		if(strcmp(word[0], realtext[i])==0)
			printf("%d\n", i);
	}

	free(word[0]);
}	


int main(void)
{
	char q[1000];		//	입력받을 명령어(insert, delete, find, print)를 넣어둘 배열
	char* word[1000];	//	quiery마다 한 줄씩 입력받는데, 그 줄에 존재하는 여러 단어들을 잠시 넣어두는 장소
	char* realtext[1000];	//	최종적으로 출력할 문자들이 담겨있는 장소
	char temp[1000];	//	입력받은 값을 word에 넣기 전에 잠시 저장해두는  장소
	int n;
	int i=0;
	int currentindex=0;	//	만약 현재 realtext[0], realtext[1] . . . realtext[8]까지 단어가 채워져 있다면, currentindex값은 9가 된다

	scanf("%d", &n);	//	몇개의 query를 입력받을래?
	
	for(i=0; i<n; i++)	//	한 번 query를 입력받을 때마다
	{
		scanf("%s", q); //	일단 명령어(insert, delete, find, print)를 입력받아 q에 넣자
		
		if(q[0] == 'i')
			insert(word, realtext, temp);
		
		else if(q[0] == 'd')
			delete(word, realtext, temp);

		else if(q[0] == 'f')
			find(word, realtext, temp);

		else if(q[0] == 'p')
			print(realtext);
	}

	for(i=0; i<currentindex; i++)
		free(realtext[i]);
}
