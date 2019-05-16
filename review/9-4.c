#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int current = 0;

void insert(char* word[])
{
	int i, value = 1;
	char temp[1000];
	scanf("%s", temp);
	
	for(i=0; i<current; i++){
		if(strcmp(word[i], temp) == 0){
            value=0; 
            break;
        }
		else
            value=1;
	}
	if(value == 1){
		word[current] = (char*)malloc(1000*sizeof(char));
		strcpy(word[current++], temp);
	}
}

void delete(char* word[])
{
	int i, j;
	char temp[1000];
	scanf("%s", temp);

	for(i=0; i<current; i++)
		if(strcmp(word[i], temp) == 0){
			for(j=0; i+j+1<current; j++)
				word[i+j] = word[i+j+1];
			current--;
			break;
		}
}

void sort(char* word[])
{
	int i, j;
	char* temp;
	for(i=0; i<current-1; i++){
		for(j=0; j<current-1-i; j++){
			if(strcmp(word[j], word[j+1]) > 0){
				temp = word[j+1];
				word[j+1] = word[j];
				word[j] = temp;
			}
		}
	}
}

void find(char* word[])
{
	int i, value = 1;
	char temp[1000];
	scanf("%s", temp);
	sort(word);
	for(i=0; i<current; i++)
		if(strcmp(word[i], temp) == 0){
			printf("%d\n", i);
			value = 0;
			break;
		}
	if(value == 1)	printf("-1\n");
}

void print(char* word[])
{
	int i;
	sort(word);
	for(i=0; i<current; i++)
		printf("%s ", word[i]);
	printf("\n");
}

int main(void)
{
	int n, i;
	char query[10];
	char* word[1000];

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
