#include <stdio.h>
#include <stdlib.h>
#define ab(x) (((x)>0)?(x):(-(x)))


int main(void)
{
	int n, cnt=0, i, j, p, q;
	char** arr = NULL;

    /* 2차원 배열 */
	scanf("%d", &n);
	arr = (char**)malloc(n*sizeof(char*));
	for(i=0; i<n; i++)
		arr[i] = (char*)malloc(n*sizeof(char));

	for(i=0; i<n; i++)
		scanf("%s", arr[i]);

	for(i=0; i<n; i++){
	for(j=0; j<n; j++){
		if(arr[i][j] == 'Q'){
			for(p=0; p<n; p++){
			for(q=0; q<n; q++){
				if(arr[p][q] == 'Q'){
					if(p == i && q == j);
					else if(p == i || q == j)	cnt++;
					else if(ab(p-i)==ab(q-j))	cnt++;
				}
			}
			}
		}
	}
	}
	printf("%d", cnt/2);
}
