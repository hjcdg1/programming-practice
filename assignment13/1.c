#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc >= 3){
		FILE* a;
		FILE* b;
		int i=0;
		int n;
		int sum=0;
		a = fopen(argv[1], "r");
		b = fopen(argv[2], "w");
		while(fscanf(a, "%d", &n) != EOF)
			sum += n;
		fprintf(b, "%d", sum);
		fclose(a);
		fclose(b);
	}
	else
		return 0;
}
