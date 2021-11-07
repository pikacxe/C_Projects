#include <stdlib.h>
#include <stdio.h>

typedef struct node_st{
    int n;
    struct node_st *next;
}NODE;

NODE *create_new_element(int n){
    NODE *new= malloc(sizeof (NODE));
    (*new).next = NULL;
    (*new).n = n;
    return new;
}

void init_list(NODE** head,int n){
    *head =create_new_element(n);
}

void add(NODE** head,int n){
    if(*head == NULL){
        NODE *temp = create_new_element(n);
        *head = temp;
        return;
    }
    else{
        NODE *temp = *head;
        while(temp-> next != NULL){
            temp = temp-> next;
        }
        temp->next = create_new_element(n);

    }
}

NODE *remove_el(NODE* head,int n){
    NODE *removed=NULL;
    NODE *temp;
    while(head !=NULL){
        if(head->n == n){
            removed = head;
            temp->next = head->next;
            free(head);
            return removed;
        }
        temp = head;
        head = head->next;
    }
    puts("Ne postoji navedeni element u listi!");
    return removed;
}

void print_list(NODE* head){
    if(head == NULL){
        puts("Lista je prazna!");
        return;
    }
    while(head != NULL){
        printf("%d ",head->n);
        head = head-> next;
    }
    puts("\n\n");
}
void destroy_list(NODE **head){
    if((*head)==NULL){
        return;
    }
    destroy_list(&((*head)->next));
    free(*head);
    *head = NULL;
}


int main(){
    NODE* head=NULL;
    add(&head,1);
    add(&head,2);
    add(&head,3);
    add(&head,4);
    add(&head,5);
    add(&head,6);
    puts("Lista pre brisanja:\n");
    print_list(head);
    remove_el(head,4);
    puts("Lista pre brisanja:\n");
    print_list(head);
    destroy_list(&head);
    print_list(head);
    return 0;
}