#include <stdio.h>

int ab(int a)
{
	if(a>0)	return a;
	else	return (-a);
}
typedef struct circle
{
	int x;
	int y;
	int r;
} circle;

int distance(circle c1, circle c2)
{
	int d = ((c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y)*(c1.y - c2.y));
	return d;
}

void checkprint(int a, int b, circle c[])
{
	int r = c[a].r + c[b].r;
	if((r*r > distance(c[a], c[b])) && ((c[a].r-c[b].r)*(c[a].r-c[b].r) < distance(c[a], c[b])))	
		printf("yes\n");
	else	
		printf("no\n");
}

int main(void)
{
	int n, q;
	int i;
	int test1, test2;
	scanf("%d", &n);
	scanf("%d", &q);
	circle c[n];

	for(i=0; i<n; i++)
		scanf("%d %d %d", &c[i].x, &c[i].y, &c[i].r);

	for(i=0; i<q; i++)
	{
		scanf("%d %d", &test1, &test2);
		checkprint(test1, test2, c);
	}

	return 0;
}
