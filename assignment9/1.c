#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int two(int power)
{
	unsigned long long int a = 1;
	int i;
	for(i=0; i<power; i++)
		a *= 2;
	return a;
}

unsigned long long int convert (char s[], int len)
{
	int i;
	unsigned long long int temp = 0;

	for(i=len-1 ; i>=0 ; i--)
	{
		if(s[i] == '1')
			temp += two(len-1-i);
	}

	return temp;
}

void print_bit(unsigned long long int a, int len)
{
	int i;
	unsigned long long int mask = 1;

	for(i=0; i<len ; i++)
	{
		putchar((((a >> (len-1-i)) & mask) == 1) ? '1' : '0');
	}
	printf("\n");
}

int convertnum (char s[])
{
	int a = s[0]-48;
	return a;
}

int main(void)
{
	int n, m;
	int i;
	int x, y;
	int len;
	char* input[1000];
	char q[100];

	scanf("%d", &n);
	scanf("%d", &m);

	for(i=0; i<n; i++)
		input[i] = (char*)malloc(100*sizeof(char));

	for(i=0; i<n; i++)
		scanf("%s", input[i]);
	len = strlen(input[0]);
	
	for(i=0; i<m; i++)
	{
		scanf("%s %d %d", q, &x, &y);
		
		if(q[0] == 'a')
		{
			print_bit(convert(input[x], len) & convert(input[y], len), len);
		}
		else if(q[0] == 'o')
		{
			print_bit(convert(input[x], len) | convert(input[y], len), len);
		}
		else if(q[0] == 'x')
		{
			print_bit(convert(input[x], len) ^ convert(input[y], len), len);
		}
		else if(q[0] == 'r')
		{
			print_bit(convert(input[x], len) >> y, len);
		}
		else if(q[0] == 'l')
		{
			print_bit(convert(input[x], len) << y, len);
		}
	}
	
}
