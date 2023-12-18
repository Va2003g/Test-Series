#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int index;
    char *arr;
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

void push(Stack *stack, char element)
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

void pop(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack undeflow\n");
        return;
    }
    stack->index--;
    stack->size--;
}

bool isEmpty(Stack *stack)
{
    return stack->index == -1;
}

int size(Stack *stack)
{
    return stack->size;
}

char top(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->index];
}

bool match(char a,char b)
{
    if(a=='['&& b==']') return true;
    if(a=='{'&& b=='}') return true;
    if(a=='('&& b==')') return true;
    return false;
}

bool validParenthesis(char* str)
{
    Stack stack;
    initializeStack(&stack,strlen(str));
    for(int i = 0;i<strlen(str);i++)
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
        {
            push(&stack,str[i]);
        }
        else
        {
            if(isEmpty(&stack)) return false;
             if(!match(top(&stack),str[i]))
            {
                return false;
            }
            pop(&stack);
        }
    }
    if(isEmpty(&stack)) return true;
    return false;
}
int main()
{
    
    char* str;
    str = (char *)malloc(101 * sizeof(char));
    scanf("%s",str);
    printf("%d\n",validParenthesis(str));

    // int capacity;
    // printf("Enter the capacity\n");
    // scanf("%d", &capacity);
    // Stack stack;
    // initializeStack(&stack, capacity);

    // for (int i = 0; i < capacity; i++)
    // {
    //     push(&stack, 'A' + i);
    // }
    // printf("%c\n", top(&stack));
    // pop(&stack);
    // printf("%c\n", top(&stack));
    // printf("%d\n", size(&stack));
    // printf("%d\n", isEmpty(&stack));
}