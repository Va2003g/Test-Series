#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
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


int main() {
    int t;
    scanf("%d",&t);
    Stack s1;
    initializeStack(&s1, 1000);
    while(t-- >0){
        char a[10];
        scanf("%s",a);
        while(a[0]!='?'){
            
            if('0'<=a[0] && a[0]<='9'){
                int index = 0;
                int number = 0;
                while(a[index]!='\0'){
                    number = number *10 + (a[index] - '0');
                    index++;
                }

                push(&s1,number);
            }else{
                int operand = pop(&s1);
                int operand1 = pop(&s1);

                if(a[0]=='+'){
                    push(&s1,operand+operand1);
                }else if(a[0]=='-'){

                    push(&s1,operand1-operand);
                }else if(a[0]=='*'){
    
                    push(&s1,operand*operand1);
                }else{
                    push(&s1,operand1/operand);
                }
            }
            scanf("%s",a);
        }
        int x = pop(&s1);
        printf("%d\n",x);
    }
    return 0;
}