#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <limits.h>

typedef struct {
    int front, rear, size;
    unsigned capacity;
    void** job;
} Queue;
 
Queue* createQueue(unsigned capacity)
{
    Queue* queue = (Queue*)malloc(
        sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->job = (void*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(Queue* queue, void* item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->job[queue->rear] = item;
    queue->size = queue->size + 1;
}

void* dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return NULL;
    void* item = queue->job[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

#endif