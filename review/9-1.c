#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long int twopower(int power)
{
	if(power == 0)	return 1;
	else
		return 2*twopower(power-1);
}

unsigned long long int convert (char answer[], int len)
{
	int i;
	unsigned long long int data=0;
	for(i=0; i<len; i++){
		if(answer[len-1-i] == '1')
			data+=twopower(i);
	}
	return data;
}

void printbin(unsigned long long int data, int len)
{
	int i;
	unsigned long long int mask = 1;
	for(i=0; i<len; i++){
		if((mask & (data>>(len-1-i))) == 1)	printf("1");
		else					printf("0");
	}
	printf("\n");
}

int main(void)
{
	int n, m, i, x, y, len;
	char** answer;
	char query[10];

	scanf("%d%d", &n, &m);
    
    /* 2차원 배열 동적 할당 */
	answer = (char**)malloc(n*sizeof(char*));
	for(i=0; i<n; i++){
		answer[i] = (char*)malloc(65*sizeof(char));
		scanf("%s", answer[i]);
	}
	len = strlen(answer[0]);

	for(i=0; i<m; i++){
		scanf("%s %d %d", query, &x, &y);

		if(strcmp(query, "and")==0)
			printbin((convert(answer[x],len) &  convert(answer[y],len)), len);
		else if(strcmp(query, "or")==0)
                        printbin((convert(answer[x],len) |  convert(answer[y],len)), len);
		else if(strcmp(query, "xor")==0)
                        printbin((convert(answer[x],len) ^  convert(answer[y],len)), len);
		else if(strcmp(query, "right")==0)
                        printbin((convert(answer[x],len)>>y), len);
		else if(strcmp(query, "left")==0)
                        printbin((convert(answer[x],len)<<y), len);
	}
}
