#include <stdio.h>

int main(void)
{
	int input;
	int max1=-1;
	int max2=-1;

	while(scanf("%d", &input) != EOF){
		if(input > max1){
			max2 = max1;
			max1 = input;
		}
		else if(input > max2 && input < max1){
			max2 = input;
		}
	}

	printf("%d", max2);
}
