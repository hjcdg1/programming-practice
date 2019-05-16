#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char d;
	struct node* next;
} node;

typedef struct stack {
	int cnt;
	node* top;
} stack;

char pop (stack* s)		//	pop
{
	char data = s->top->d;
	node* save = s->top;
	if((s->cnt)>0){		//	cnt체크 필수!
		s->top = s->top->next;
		free(save);
		(s->cnt)--;
		return data;
	}
	else	return -1;
}

void push (stack* s, char item)	//	push
{
	node* save = s->top;
	s->top = (node*)malloc(sizeof(node));
	s->top->d = item;
	s->top->next = save;
	(s->cnt)++;
}

char look (stack* s)
{
	return (s->top->d);
}

void if_match (stack* s, char input[])
{
	int len = strlen(input);
	int i;
	for(i=0; i<len; i++){
		if((input[i] == ')' && look(s) == '(') || (input[i] == ']' && look(s) == '[') || (input[i] == '}' && look(s) == '{'))
			pop(s);
		else
			push(s, input[i]);
	}
	if(s->cnt == 0)		printf("VALID");
	else		    	printf("INVALID");
}

int main(void)
{
	char input[200000];
	stack s = {0, NULL};
	scanf("%s", input);
	if_match(&s, input);
}
