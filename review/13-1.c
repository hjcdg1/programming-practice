#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE* in = fopen(argv[1], "r");
	FILE* out = fopen(argv[2], "w");

	int sum=0, input;
	while(fscanf(in, "%d", &input) != EOF)
		sum += input;
	fprintf(out, "%d", sum);

	fclose(in);
	fclose(out);
}
