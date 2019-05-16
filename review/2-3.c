#include <stdio.h>

int main(void)
{
	int input;
	double sum=0;
	int n=0;

	while(scanf("%d", &input) != EOF){
		n++;
		sum += input;
	}
	if(n>0)	printf("%.6f", sum/n);
	else	printf("0.000000");
}
