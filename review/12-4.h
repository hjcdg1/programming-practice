#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
        int d;
        struct node* next;
} node;

typedef struct stack {
        int cnt;
        node* top;
} stack;

typedef struct board {
        int tile[4][4];
} board;

typedef struct savenode {
        board* d;
        struct savenode* next;
} savenode;

int pop (stack* s)               //      pop
{
        int data = s->top->d;
        node* save = s->top;
        if((s->cnt)>0){          //      cnt체크 필수!
                s->top = s->top->next;
                free(save);
                (s->cnt)--;
                return data;
        }
        else    return -1;
}

void push (stack* s, int item)  //      push
{
        node* save = s->top;
        s->top = (node*)malloc(sizeof(node));
        s->top->d = item;
        s->top->next = save;
        (s->cnt)++;
}

int look (stack* s)
{
        if(s->cnt > 0)
                return (s->top->d);
        else
                return -1;
}

int count (node* head)
{
	if(head == NULL)		return 0;
	else if(head->d == -2)		return count(head->next);
	else				return (1+count(head->next));
}

void print(board *a){
        int i,j;
        printf("-----------------------------\n");
        for(i = 0; i < 4; ++i){
                printf("|      |      |      |      |\n|");
                for(j = 0; j < 4; ++j){
                        if(a->tile[i][j] == 0) printf("      |");
                        else printf("%6d|", a->tile[i][j]);
                }
                printf("\n|      |      |      |      |\n");
                printf("-----------------------------\n");
        }
        return;
}

void insert (savenode* head, board* item)
{
	if(head->next == NULL){
		head->next = (savenode*)malloc(sizeof(savenode));
		head->next->d = item;
		head->next->next = NULL;
	}
	else
		insert(head->next, item);
}

#ifdef ONLINE_JUDGE
int getseed(){
        return 0;
}
#endif

#ifndef ONLINE_JUDGE
#include <time.h>
int getseed(){
        return time(NULL);
}
#endif

