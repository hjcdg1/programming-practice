#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE * in, * p, * out;
	char word[10000], pattern[10000];
	char* s[1000];
	int i=0, k, j;
	int line_cnt, pl, temp_len=0, value;

	/* 파일 개방 */
	in = fopen(argv[1], "r");
	p = fopen(argv[2], "r");
	out = fopen(argv[3], "w");
	
	/* input.txt로부터 읽어온 단어들 저장해두기 */
	while(fscanf(in, "%s", word) != EOF){
		s[i] = (char*)malloc(10000*sizeof(char));
		strcpy(s[i++], word);		
	}
	line_cnt = i;	// 읽어온 단어의 총 개수

	/* pattern 파일로부터 읽어오기 */
	fscanf(p, "%s", pattern);
	pl = strlen(pattern);

	/* pattern 검사하기 */
	for(i=0; i<line_cnt; i++){
		temp_len = strlen(s[i]);

		for(k=0; k<temp_len-pl+1; k++){
			for(j=0; j<pl; j++){
				if(pattern[j] == s[i][k+j])
					value = 1;
				else{
					value = 0;
					break;
				}
			}
			if(value == 1)
				fprintf(out, "%d %d\n", i+1, k+1);
		}

	}

}
