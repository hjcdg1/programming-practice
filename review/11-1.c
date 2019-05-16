#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

void insert(node* head, int d)
{
	if(head->next == NULL){
		head->next = (node*)malloc(sizeof(node));
		head->next->data = d;
		head->next->next = NULL;
	}
	else
		insert(head->next, d);
}

void delete(node* head, int d)
{
	node* save;

	if(head->next == NULL)
		return;
	
	if(head->next->data == d){
		save = head->next->next;
		free(head->next);
		head->next = save;
		return;
	}
	else
		delete(head->next, d);
}

void print(node* head)
{
	if(head->next == NULL)
		return;
	else{
		printf("%d ", head->next->data);
		print(head->next);
	}
}

int main(void)
{
	int n, i, query, x;

    /* dummy node */
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;

	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &query);
		switch(query){
			case 0:
				scanf("%d", &x);
				insert(head, x);
				break;
			case 1:
				scanf("%d", &x);
				delete(head, x);
				break;
			case 2:
				print(head);
				break;
		}
	}
}
