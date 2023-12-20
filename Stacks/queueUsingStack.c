#include <stdio.h>
#include <stdbool.h>
typedef struct stack
{
    int index;
    int *arr;
    int size;
    int capacity;
} Stack;

void initializeStack(Stack *stack, int capacity)
{
    stack->index = -1;
    stack->size = 0;
    stack->capacity = capacity;
    stack->arr = (char *)malloc(capacity * sizeof(char));
}

void push(Stack *stack, int element)
{
    if (stack->index >= stack->capacity)
    {
        printf("Stack overflow\n");
        return;
    }
    ++stack->index;

    stack->arr[stack->index] = element;
    // printf("%c", stack->arr[stack->index]);
    stack->size++;
}

int pop(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack undeflow\n");
        return -1;
    }
    stack->size--;
    return stack->arr[stack->index--];
}

bool isEmpty(Stack *stack)
{
    return stack->index == -1;
}

int size(Stack *stack)
{
    return stack->size;
}

int top(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->index];
}


Stack s1;
Stack s2;
typedef struct {
    int front;
} MyQueue;


MyQueue* myQueueCreate() {
    initializeStack(&s1,100);
    initializeStack(&s2,100);
    MyQueue* q = (MyQueue*) malloc(1*sizeof(MyQueue*));
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    if(isEmpty(&s1)) obj->front = x;
    push(&s1,x);
}

int myQueuePop(MyQueue* obj) {

    if(isEmpty(&s2))
    {
        while(!isEmpty(&s1))
        {
            push(&s2,pop(&s1));
        }
    }
    return pop(&s2);
    
}

int myQueuePeek(MyQueue* obj) {
    if(!isEmpty(&s2))
    {
        obj->front = top(&s2);
    }
    return obj->front;
}

bool myQueueEmpty(MyQueue* obj) {

    return isEmpty(&s1)&&isEmpty(&s2);
    
}

void myQueueFree(MyQueue* obj) {

    free(obj);
    
}
