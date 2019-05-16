#include <stdio.h>

int main(void)
{
	int p=2;
	int i=0;
	int state=0;
	int j=0;

	for(i=1;i<999;i++, p++)
	{
		state=0;
		for(j=1; j<=p; j++)
			if(p%j == 0)	
				state++;
		
		if(state==2)	
			printf("%d\n", p);
	}
}
