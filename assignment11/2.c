#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node* next;
} node;

void insert (node* head, int item){
	node* pre = head;
	node* cur = head->next;

	if(cur == NULL){		//	하나도 없다면
		head->next = (node*)malloc(sizeof(node));
		head->next->d = item;
		head->next->next = NULL;
	}
	else{				//	하나라도 들어있다면
		while(item > (cur->d)){		//	item보다 크거나 같은 것을 찾을때까지 돈다.
			pre = pre->next;
			cur = cur->next;
			if(cur == NULL)
				break;
		}

		pre->next = (node*)malloc(sizeof(node));
		pre->next->d = item;
		pre->next->next = cur;
	}

}

void delete(node* head, int item){
	node* pre = head;
	node* cur = head->next;

	if(cur == NULL)		//	아무것도 안들어있다면 당연히 지울 것도 없지
		return;
	else{			//	들어있다면
		if(cur->d == item){
			pre->next = cur->next;
			free(cur);
			return;
		}
		else{
			delete(cur, item);
			return;
		}
	}
}


void print(node* head)
{
	if(head->next == NULL)
		printf("\n");
	else
	{
		printf("%d ", head->next->d);
		print(head->next);
	}
}

int main(void)
{
	int n;
	int i;
	int q;
	int x;
	scanf("%d", &n);
	
	node* head = (node*)malloc(sizeof(node));	//	더미 노드
	head->d = 9999;					//	아무거나 상관 없음
	head->next = NULL;				//	처음엔 아무것도 안가리키니 무조건 NULL로 초기화

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
