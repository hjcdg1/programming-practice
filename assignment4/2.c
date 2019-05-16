#include <stdio.h>
#include <string.h>

int main(void)
{
	char H[1000];
	char N[1000];
	int hlen=0, nlen=0;
	int k=0, l=0;
	int state=0;
	int counter=0;
	
	scanf("%s", H);
	scanf("%s", N);

	hlen = strlen(H);
	nlen = strlen(N);

	for(k=0; k<hlen-(nlen-1); k++)
	{
		for(l=0; l<nlen; l++)
		{
			if(H[l+k] == N[l])	
				state=1;
			else
			{
				state=0;
				break;
			}
		}

		if(state == 1)
			counter++;
	}

	printf("%d", counter);
}
