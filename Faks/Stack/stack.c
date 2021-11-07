#include <stdlib.h>
#include <stdio.h>

typedef struct node_st{
    int num;
    struct node_st *before;
}NODE;

typedef struct stack_st{
    NODE *top;
}STACK;

void init_stack(STACK **stack){
    *stack = (STACK*)malloc(sizeof(STACK));
    (*stack)->top = NULL;
}
NODE *pop(STACK *stack){
    if(stack == NULL){
        puts("Stack is not initialized!");
        return NULL;
    }
    if(stack->top == NULL){
        puts("Stack je prazan!");
        return NULL;
    }
    NODE *temp = stack->top;
    stack->top = temp->before;
    return temp; 
}

NODE *create_node(int n){
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->before = NULL;
    new->num = n;
    return new;
}

void push(STACK *stack,int num){
    if(stack == NULL){
        puts("Stack is not initialized!");
        return;
    }
    NODE *new = create_node(num);
    if(stack->top == NULL){
        stack->top = new;
        return;
    }
    new->before = stack->top;
    stack->top = new;
    return;
}

void print_stack(STACK *stack){
    if(stack == NULL){
        puts("Stack is not initialized!");
        return;
    }
    if(stack->top == NULL){
        puts("Stack is empty!");
        return;
    }
    NODE *temp = stack->top;
    while(temp !=NULL){
        printf("%d\n",temp->num);
        temp = temp->before;
    }

}

void destroy_stack(STACK **stack){
    if(*stack == NULL){
        puts("Stack is already destroyed!");
        return;
    }
    while((*stack)->top != NULL){
        free(pop(*stack));
    }
    stack = NULL;
    puts("Stack succefully destroyed!");
}


int main(){

    STACK *stack =NULL;
    init_stack(&stack);
    puts("Stack:");
    for(int i = 1;i<=10;i++)
        push(stack,i);
    print_stack(stack);
    puts("Stack after removal:");
    for(int i = 1;i<=3;i++)
        pop(stack);
    print_stack(stack);
    destroy_stack(&stack);
    print_stack(stack);
    return 0;
}