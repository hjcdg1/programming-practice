#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int current = 0;

int input(char* word[], char* wordtemp[])
{
	char input[10000];

    /* 여러 단어 읿력 받기 */
	int cnt = 0;
        do{
                scanf("%s", input);
                wordtemp[cnt] = (char*)malloc((strlen(input)+1)*sizeof(char));
                strcpy(wordtemp[cnt++], input);
        } while(getchar()!='\n');
	
	return cnt;
}

void insert(char* word[])
{
	char* wordtemp[100];
	int i, j, value = 1;
	int cnt = input(word, wordtemp);

	for(i=0; i<cnt; i++){
		for(j=0; j<current; j++){
			if(strcmp(wordtemp[i], word[j])==0){
                value = 0; 
                break;
            }
			else
                value = 1;
		}
		if(value == 1){
			word[current] = (char*)malloc((strlen(wordtemp[i])+1)*sizeof(char));
			strcpy(word[current++], wordtemp[i]);
		}
	}
}

void delete(char* word[])
{
	char* wordtemp[100];
	int i, j, k;
	int cnt = input(word, wordtemp);

	for(i=0; i<cnt; i++){
        for(j=0; j<current; j++){
            if(strcmp(wordtemp[i], word[j])==0){
                for(k=0; j+k+1<current; k++)
                    word[j+k] = word[j+k+1];
                current--;
				break;
			}
        }
	}
}

void sort(char* word[])
{
        int i, j;
        char* temp;

        for(i=0; i<current-1; i++)
            for(j=0; j<current-i-1; j++)
                if(strlen(word[j]) > strlen(word[j+1]))
                    temp = word[j], word[j] = word[j+1], word[j+1] = temp;
                else if(strlen(word[j]) == strlen(word[j+1]))
                    if(strcmp(word[j], word[j+1])>0)
                        temp = word[j], word[j] = word[j+1], word[j+1] = temp;
}

void find(char* word[])
{
	int i;
	char temp[10000];
	
	scanf("%s", temp);
	sort(word);
	for(i=0; i<current; i++)
		if(strcmp(word[i], temp)==0){
			printf("%d\n", i);
			break;
		}
}

void print(char* word[])
{
	int i;
	sort(word);
	for(i=0; i<current; i++)
        printf("%s ", word[i]);
}

int main(void)
{
	int n, i;
	char query[100];
	char* word[100];

	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", query);
		if(strcmp(query, "insert")==0)
			insert(word);
		else if(strcmp(query, "delete")==0)
			delete(word);
		else if(strcmp(query, "find")==0)
			find(word);
		else if(strcmp(query, "print")==0)
			print(word);
	}
}
