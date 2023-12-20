#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int index;
    int* arr;
    int size;
    int capacity;
} Stack;

void initializeStack(Stack *stack, int capacity)
{
    stack->index = -1;
    stack->size = 0;
    stack->capacity = capacity;
    stack->arr = (int *)malloc(capacity * sizeof(int));
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
    return  stack->arr[stack->index--];
    
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


int longestValidParentheses(char* s) {
    int count = 0;
    Stack s1;
    initializeStack(&s1,strlen(s));
    int* dp = (int*) calloc(strlen(s),sizeof(int));
    for(int i = 0;i<strlen(s);i++)
    {
        if(s[i]==')'&&isEmpty(&s1)) continue;

        if(s[i]=='(') push(&s1,i);

        else
        {
            int length = i - top(&s1) + 1;
            if(top(&s1)>1)
                length+=dp[top(&s1)-1];
            pop(&s1);
            dp[i] = length;
            count = length>count ? length : count;
        }
    }
    return count;
}