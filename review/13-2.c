#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* in = fopen(argv[1], "r");
	FILE* pattern = fopen(argv[2], "r");
	FILE* out = fopen(argv[3], "w");

	int plen;
	char p[1000];
	fscanf(pattern, "%s", p);
	plen = strlen(p);

	int i=0, wordcnt;
	char* word[10000];
	char temp[1000];
	while(fscanf(in, "%s", temp) != EOF){
		word[i] = (char*)malloc( (10000)*sizeof(char) );
		strcpy(word[i++], temp);
	}
	wordcnt = i;
	
	int j, k, value, templen;
	for(i=0; i<wordcnt; i++){
		templen = strlen(word[i]);			//	이거 매우 중요함 ! ! !
		for(j=0; j<templen-plen+1; j++){
			for(k=0; k<plen; k++){
				if(p[k] != word[i][j+k]){
					value = 0;
					break;
				}
				else
					value = 1;
			}
			if(value == 1)	fprintf(out, "%d %d\n", i+1, j+1);
		}
	}
	fclose(in);
	fclose(pattern);
	fclose(out);
}
