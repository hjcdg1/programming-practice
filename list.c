#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int d;
    struct node* next;
} node;

/*
void insert(node* head, int item)
{
    if(head->next == NULL){
        head->next = (node*)malloc(sizeof(node));
        head->next->d = item;
        head->next->next = NULL;
    }
    else
        insert(head->next, item);
}
*/

void insert(node* head, int item)
{
    node* temp;
    if(head->next == NULL){
        head->next = (node*)malloc(sizeof(node));
        head->next->d = item;
        head->next->next = NULL;
    }
    else if(item <= head->next->d){
        temp = head->next;
        head->next = (node*)malloc(sizeof(node));
        head->next->d = item;
        head->next->next = temp;
    }
    else
        insert(head->next, item);

}

void delete(node* head, int item)
{
    node* temp;
    if(head->next == NULL)
        return;
    else if(head->next->d == item){
        temp = head->next->next;
        free(head->next);
        head->next = temp;
    }
    else
        delete(head->next, item);
}

void print(node* head)
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
    int command, input;
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;

    while(1){
        scanf("%d", &command);
        if(command == 0){
            scanf("%d", &input);
            insert(head, input);
        }
        else if(command == 1){
            scanf("%d", &input);
            delete(head, input);
        }
        else if(command == 2)
            break;
    }

    print(head);
}
