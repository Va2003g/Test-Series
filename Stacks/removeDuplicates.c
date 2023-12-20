#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int index;
    char* arr;
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

char pop(Stack *stack)
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

char top(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->index];
}

void swap(char* a,char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char* ans){
    int i=0;
    int n=strlen(ans)-1;
    while(i<n){
        swap(&ans[i],&ans[n]);
        i+=1;
        n-=1;
    }
}



char* removeDuplicateLetters(char* s) {
    Stack stack;
    initializeStack(&stack,strlen(s));
    int frequency[26]={0};
    int n = strlen(s);
    for(int i=0;i<n;i++){
        frequency[s[i]-'a']++;
    }
    bool visited[26]={false};
    char* ans = (char*)malloc((n + 1) * sizeof(char));
    int indx=0;
    for(int i=0;i<n;i++){
        frequency[s[i]-'a']-=1;
        if(visited[s[i]-'a']==true) continue;
        while (!isEmpty(&stack)&&top(&stack) > s[i] && frequency[top(&stack) - 'a'] > 0) {
            visited[top(&stack) - 'a'] = false;
            char popped = pop(&stack);
        }
        push(&stack, s[i]);
        visited[s[i] - 'a'] = true;
    }
    while(!isEmpty(&stack)){
        ans[indx++] = pop(&stack);
    }
    ans[indx]='\0';
    // printf("%s",ans);
    reverse(ans);
    return ans;
}
