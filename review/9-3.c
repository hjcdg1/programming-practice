#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char** word, int start, int middle, int end)
{
	char** temp = (char**)malloc((end-start+1)*sizeof(char*));
	int a_cnt=0, b_cnt=0, c_cnt=0;
	int a_len = middle-start+1;
	int b_len = end-middle;
	int i;

	while(a_cnt<a_len && b_cnt<b_len){
		if(strcmp(word[start+a_cnt], word[middle+1+b_cnt]) < 0)
			temp[c_cnt++] = word[start+a_cnt++];
		else
			temp[c_cnt++] = word[middle+1+b_cnt++];
	}
	while(a_cnt<a_len)
		temp[c_cnt++] = word[start+a_cnt++];
	while(b_cnt<b_len)
		temp[c_cnt++] = word[middle+1+b_cnt++];

	for(i=0; i<end-start+1; i++)
		word[start+i] = temp[i];
	free(temp);
}

void mergesort(char** word, int start, int end)
{
	int middle;
	if(end == start)	return;
	else{
		middle = (end+start)/2;
		mergesort(word, start, middle);
		mergesort(word, middle+1, end);
		merge(word, start, middle, end);
	}
}

int main(void)
{
	int n, i;
	char** word;
	char t[10000];

	scanf("%d", &n);
	word = (char**)malloc(n*sizeof(char*));
	for(i=0; i<n; i++){
		scanf("%s", t);		//	엔터를 쳐야 여태까지 친 내용들이 '입력버퍼'에 들어간다!!!
					//	엔터를 안 쳤으면 맨 처음 scanf에서 코드는 멈춰있다가, 엔터를 친 순간 코드가 진행된다.
		word[i] = (char*)malloc((strlen(t)+1)*sizeof(char));
		strcpy(word[i], t);
	}

	mergesort(word, 0, n-1);

	for(i=0; i<n; i++)
		printf("%s ", word[i]);
}
