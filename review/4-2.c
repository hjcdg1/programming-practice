#include <stdio.h>
#include <string.h>

int main(void)
{
	char H[10000];
	char N[10000];
	int hlen, nlen;
	int i, j, v, cnt=0;

	scanf("%s", H);
	scanf("%s", N);

	hlen = strlen(H);
	nlen = strlen(N);

	for(i=0; i<hlen-nlen+1; i++){
		for(j=0; j<nlen; j++){
			if(N[j] == H[i+j])
				v = 1;
			else{
				v = 0;
				break;
			}
		}
		if(v == 1)	cnt++;
	}
	printf("%d", cnt);
}
