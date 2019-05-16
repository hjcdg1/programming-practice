#include <stdio.h>
#include <string.h>

typedef struct student
{
	char name[30];
	double height;
	int weight;
} student;

void name(student person[], int n)
{
	int i, j;
	int p, q;
	int k, l;
	student temp;

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if(strcmp(person[j].name, person[j+1].name)>0)
			{
				temp = person[j];
				person[j] = person[j+1];
				person[j+1] = temp;
			}
			else if(strcmp(person[j].name, person[j+1].name)==0)
			{
				if(person[j].height > person[j+1].height)
				{
					temp = person[j];
					person[j] = person[j+1];
					person[j+1] = temp;
				}
				else if(person[j].height == person[j+1].height)
				{
					if(person[j].weight > person[j+1].weight)
					{
						temp = person[j];
						person[j] = person[j+1];
						person[j+1] = temp;
					}
				}
			}
		}
	}
	
	for(i=0; i<n; i++)
		printf("%s %.1f %d\n", person[i].name, person[i].height, person[i].weight);
}

void height(student person[], int n)
{
	int i, j;
	int p, q;
	int k, l;
	student temp;

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if(person[j].height > person[j+1].height)
			{
				temp = person[j];
				person[j] = person[j+1];
				person[j+1] = temp;
			}
			else if(person[j].height == person[j+1].height)
			{
				if(person[j].weight > person[j+1].weight)
				{
					temp = person[j];
					person[j] = person[j+1];
					person[j+1] = temp;
				}
				else if(person[j].weight == person[j+1].weight)
				{
					if(strcmp(person[j].name, person[j+1].name)>0)
					{
						temp = person[j];
						person[j] = person[j+1];
						person[j+1] = temp;
					}
				}
			}
		}
	}
	
	for(i=0; i<n; i++)
		printf("%s %.1f %d\n", person[i].name, person[i].height, person[i].weight);
}

void weight(student person[], int n)
{
	int i, j;
	int p, q;
	int k, l;
	student temp;

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if(person[j].weight > person[j+1].weight)
			{
				temp = person[j];
				person[j] = person[j+1];
				person[j+1] = temp;
			}
			else if(person[j].weight == person[j+1].weight)
			{
				if(strcmp(person[j].name, person[j+1].name)>0)
				{
					temp = person[j];
					person[j] = person[j+1];
					person[j+1] = temp;
				}
				else if(strcmp(person[j].name, person[j+1].name)==0)
				{
					if(person[j].height > person[j+1].height)
					{
						temp = person[j];
						person[j] = person[j+1];
						person[j+1] = temp;
					}
				}
			}
		}
	}
	
	for(i=0; i<n; i++)
		printf("%s %.1f %d\n", person[i].name, person[i].height, person[i].weight);
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	student person[n];

	for(i=0; i<n; i++)
		scanf("%s %lf %d", person[i].name, &person[i].height, &person[i].weight);
	
	name(person, n);
	height(person, n);
	weight(person, n);

	return 0;
}

