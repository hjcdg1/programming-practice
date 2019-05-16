#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	char d;
	struct element* next;
} node;

typedef struct stack{
	int cnt;
	node* top;
} stack;

char pop(stack* s)
{
	char data;
	node* temp;
	if((s->cnt)>0)
	{
		data = s->top->d;
		temp = s->top;
		(s->cnt)--;
		(s->top) = s->top->next;
		free(temp);
		return data;
	}
	return -1;
}

void push(stack* s, char data)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->next = s->top;
	temp->d = data;
	s->top = temp;
	(s->cnt)++;
}

int main(void)
{
	int i=0, value=0;
	char input[1000000];
	char left, right;
	stack p = {0, NULL};	//	스택 초기화
	scanf("%s", input);
	
	for(i=0; input[i] != '\0'; i++)
	{
		if(input[i]=='(' || input[i]=='[' || input[i]=='{')
			push(&p, input[i]);
		else if(input[i]==')' || input[i]==']' || input[i]=='}')
		{
			right = input[i];
			left = pop(&p);
			if( (left=='(' && right==')') || (left=='[' && right==']') || (left=='{' && right=='}') )
				value=1;
			else
			{
				value=0;
				break;
			}
		}
	}

	if(value == 1)		printf("VALID");
	else if(value == 0)	printf("INVALID");
	
	return 0;
}
