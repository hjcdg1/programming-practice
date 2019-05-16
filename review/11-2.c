#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node* next;
} node;

/* 정렬 insert */
void insert (node* head, int item)
{
	node* save;

	if(head->next == NULL){
		head->next = (node*)malloc(sizeof(node));
		head->next->d = item;
		head->next->next = NULL;
	}
	else{
		if(item > head->next->d)
			insert(head->next, item);
		else{
			save = head->next;
			head->next = (node*)malloc(sizeof(node));
			head->next->d = item;
			head->next->next = save;
		}
	}
}

void delete (node* head, int item)
{
	node* save;
	if(head->next == NULL)
		return;

	if(head->next->d == item){
		save = head->next->next;
		free(head->next);
		head->next = save;
	}
	else{
		delete(head->next, item);
	}
}

void print (node* head)
{
	if(head->next == NULL)
		return;
	else{
		printf("%d ", head->next->d);
		print(head->next);
	}
}

int main(void)
{
	int n, i, query, x;
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
