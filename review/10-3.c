#include <stdio.h>

typedef struct {
	int x;
	int y;
	int r;
} circle;

void check (circle first, circle second)
{
	int d = (first.x - second.x)*(first.x - second.x) + (first.y - second.y)*(first.y - second.y);
	
	if((first.r + second.r)*(first.r + second.r) > d  &&  (first.r-second.r)*(first.r-second.r) < d)
		printf("yes\n");
	else
		printf("no\n");
}

int main(void)
{
	int n, q, i, first, second;

	scanf("%d %d", &n, &q);
	circle c[n];

	for(i=0; i<n; i++)
		scanf("%d %d %d", &(c[i].x), &(c[i].y), &(c[i].r));

	for(i=0; i<q; i++){
		scanf("%d %d", &first, &second);
		check(c[first], c[second]);
	}
}
