
#include<stdio.h>
#include<stdbool.h>
typedef struct {
    int front;
    int rear;
    int size;
    int* arr;
    int capacity;    
} MyCircularQueue;


MyCircularQueue* createQueue(int k) {
    MyCircularQueue* queue = (MyCircularQueue*) malloc(1*sizeof(MyCircularQueue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = k;
    queue->arr = (int*) malloc(k*sizeof(int));
    for(int i = 0;i<k;i++) queue->arr[i] = -1;
    return queue;
}

bool isEmpty(MyCircularQueue* obj) {
    
    return obj->size==0;
}

bool isFull(MyCircularQueue* obj) {
    return obj->size==obj->capacity;
    
}

void push(MyCircularQueue* obj, int value) {

    if(isFull(obj)) return;
    obj->size = obj->size + 1;
    obj->rear = (obj->rear+1)%obj->capacity;
    obj->arr[obj->rear] = value;
    // return true;
}

int pop(MyCircularQueue* obj) {
    if(isEmpty(obj)) return -1;
    obj->size = obj->size - 1;
    int temp = obj->arr[obj->front];
    obj->arr[obj->front] = -1;
    obj->front = (obj->front+1)%obj->capacity;
    return temp;
}

int top(MyCircularQueue* obj) {
    return obj->arr[obj->front];
}

MyCircularQueue* queue1;
MyCircularQueue* queue2;
typedef struct {

    
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*) malloc(sizeof(MyStack));
    queue1 = createQueue(100);
    // queue2 = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    return stack;
}

void myStackPush(MyStack* obj, int x) {

    push(queue1,x);
    for(int i = 0;i<queue1->size-1;i++)
    {
        push(queue1,pop(queue1));
    }
}

int myStackPop(MyStack* obj) {
    return pop(queue1);
}

int myStackTop(MyStack* obj) {
    return top(queue1);
    
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(queue1);
    
}

void myStackFree(MyStack* obj) {
    free(obj);
    free(queue1);
}
