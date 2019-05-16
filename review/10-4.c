#include <stdio.h>
#include <string.h>

typedef struct {
	char name[10];
	float height;
	int weight;
} person;

void namesort(person c[], int len)
{
	int i, j;
	person temp;

	for(i=0; i<len-1; i++)
		for(j=0; j<len-1-i; j++)
			if(strcmp(c[j].name, c[j+1].name) > 0){
				temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
			}
}

void heightsort(person c[], int len)
{
        int i, j;
        person temp;

        for(i=0; i<len-1; i++)
                for(j=0; j<len-1-i; j++)
                        if(c[j].height > c[j+1].height){
                                temp = c[j];
                                c[j] = c[j+1];
                                c[j+1] = temp;
                        }
}

void weightsort(person c[], int len)
{
        int i, j;
        person temp;

        for(i=0; i<len-1; i++)
                for(j=0; j<len-1-i; j++)
                        if(c[j].weight > c[j+1].weight){
                                temp = c[j];
                                c[j] = c[j+1];
                                c[j+1] = temp;
                        }
}

void print(person c[], int len, void (*n)(person*, int), void (*h)(person*, int), void (*w)(person*, int))
{
	int i;

	w(c,len);  h(c,len);  n(c, len);
	for(i=0; i<len; i++)	printf("%s %.1f %d\n", c[i].name, c[i].height, c[i]. weight);
        
	n(c,len);  w(c,len);  h(c, len);
	for(i=0; i<len; i++)    printf("%s %.1f %d\n", c[i].name, c[i].height, c[i]. weight);
        
	h(c,len);  n(c,len);  w(c, len);
	for(i=0; i<len; i++)    printf("%s %.1f %d\n", c[i].name, c[i].height, c[i]. weight);

}


int main(void)
{
	int n, i;

	scanf("%d", &n);
	person c[n];
	for(i=0; i<n; i++)
		scanf("%s %f %d", c[i].name, &(c[i].height), &(c[i].weight));
	print(c, n, namesort, heightsort, weightsort);
}
