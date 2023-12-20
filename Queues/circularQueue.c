
#include<stdio.h>
#include<stdbool.h>
typedef struct {
    int front;
    int rear;
    int size;
    int* arr;
    int capacity;    
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*) malloc(1*sizeof(MyCircularQueue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = k;
    queue->arr = (int*) malloc(k*sizeof(int));
    for(int i = 0;i<k;i++) queue->arr[i] = -1;
    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    
    return obj->size==0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size==obj->capacity;
    
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if(myCircularQueueIsFull(obj)) return false;
    obj->size = obj->size + 1;
    obj->rear = (obj->rear+1)%obj->capacity;
    obj->arr[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return false;
    obj->size = obj->size - 1;
    obj->arr[obj->front] = -1;
    obj->front = (obj->front+1)%obj->capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->rear==-1) return -1;
    return obj->arr[obj->rear];
    
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}
