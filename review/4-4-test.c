#include <stdio.h>

void print(int total, int star_num)
{
    int i;
    int space_num = (total-star_num)/2;

    for(i=0; i<space_num; i++)
        printf(" ");
    for(i=0; i<star_num; i++)
        printf("*");
    for(i=0; i<space_num; i++)
        printf(" ");
    printf("\n");
}

int main(void)
{
    int n, i, upper, down;
    scanf("%d", &n);

    for(i=0; i<n; i++)
        print(2*n-1, 2*n-1-2*i);
    for(i=0; i<n-1; i++)
        print(2*n-1, 3+2*i);
}
