#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node* next;
} node;

void insert(node* head, int item){
	if(head->next == NULL){
		head->next = (node*)malloc(sizeof(node));
		head->next->d = item;
		head->next->next = NULL;
	}
	else{
		insert(head->next, item);
		return;
	}
}

void delete(node* head, int item){
	if(head->next == NULL)
		return;
	
	if(head->next->d == item){
		free(head->next);
		head->next = head->next->next;		
	}
	else
		delete(head->next, item);

}

void print(node* head){
	if(head->next == NULL){
		printf("\n");
		return;
	}
	else{
		printf("%d ", head->next->d);
		print(head->next);
	}
}

int main(void)
{
	int i, n, q, x;
	node* head = (node*)malloc(sizeof(node));
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &q);
		if(q == 0){
			scanf("%d", &x);
			insert(head, x);
		}
		else if(q == 1){
			scanf("%d", &x);
			delete(head, x);
		}
		else if(q == 2)
			print(head);
	}
}
