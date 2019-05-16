#include <stdio.h>

int main(void)
{
	char x[1001], y[1001], z[1001], c;
	int i = 0, j = 0, k = 0, value;
	int xlen, ylen;

	while((c=getchar()) != '\n')
		x[i++] = c;
	while((c=getchar()) != '\n')
		y[j++] = c;
	while((c=getchar()) != '\n')
		z[k++] = c;
	xlen=i, ylen=j;

	for(i=0; i<xlen-ylen+1; i++){
		for(j=0; j<ylen; j++){
			if(y[j] == x[i+j] || y[j] == '?')
				value = 1;
			else{
				value = 0;
				break;
			}
		}
		if(value == 1){
			for(j=0; j<ylen; j++)
				x[i+j] = z[j];
			i += ylen-1;
		}
	}

	for(i=0; i<xlen; i++)
		printf("%c", x[i]);
}
