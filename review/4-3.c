#include <stdio.h>

int main(void)
{
	int n, i, cnt;

	for(n=2; n<1000; n++){
		for(cnt=0, i=1; i<=n; i++)
			if(n%i == 0)	cnt++;
		if(cnt==2)	printf("%d\n", n);
	}
}
