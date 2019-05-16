#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char x[1001];
	char y[1001];
	char z[1001];
	int i=0, j, m;
	int xlen, ylen, zlen;
	char c;
	int state=0;

	while((c=getchar())!='\n')	//	x입력
		x[i++] = c;
	xlen = i;
//	x[i]=0;
	i=0;

	while((c=getchar())!='\n')	//	y입력
		y[i++] = c;
	ylen = i;
//	y[i]=0;
	i=0;

	while((c=getchar())!='\n')	//	z입력
		z[i++] = c;
	zlen = i;
//	z[i]=0;

	for(i=0; i<xlen-(ylen-1); i++)
	{	
		for(m=0; m<ylen; m++)
		{
			if(y[m] == x[i+m] || y[m] == '?')
				state = 1;
			else
			{
				state = 0;
				break;
			}
		}
		
		if(state==1)
		{
			for(m=0; m<ylen; m++)
				x[i+m] = z[m];
			i = i + ylen-1;
		}
	}

	printf("%s", x);
}
