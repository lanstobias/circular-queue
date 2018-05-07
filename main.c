#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void demo()
{
    queue queue;
    queueInit(&queue, 4);

    printf("queueInit(&queue, 4)\n");

    printf("isFull? %d\n", queueIsFull(&queue));
    printf("isEmpty? %d\n", queueIsEmpty(&queue));
    printf("first: %d\n", queueFirst(&queue));
    printf("last: %d\n", queueLast(&queue));
    printf("size: %d\n", queueSize(&queue));
    printf("\n");

    queueEnqueue(&queue, 2);
    queueEnqueue(&queue, 4);
    queueEnqueue(&queue, 6);
    // queueEnqueue(&queue, 8);
    // queueEnqueue(&queue, 10);
    printf("queueEnqueue(&queue, 2)\n");
    printf("queueEnqueue(&queue, 4)\n");
    printf("queueEnqueue(&queue, 6)\n");
    // printf("queueEnqueue(&queue, 8)\n");
    // printf("queueEnqueue(&queue, 10)\n");
    printf("\n");

    printf("isFull? %d\n", queueIsFull(&queue));
    printf("isEmpty? %d\n", queueIsEmpty(&queue));
    printf("first: %d\n", queueFirst(&queue));
    printf("last: %d\n", queueLast(&queue));
    printf("size: %d\n", queueSize(&queue));
    printf("\n");

    int dequeueVal = queueDequeue(&queue);
    printf("queueDequeue(&queue, 2)\n");
    printf("deququValue: %d\n", dequeueVal);
    printf("first: %d\n", queueFirst(&queue));
    printf("last: %d\n", queueLast(&queue));
    printf("size: %d\n", queueSize(&queue));
    printf("\n");
}

void debug()
{
    int dequeueValue, full, empty, size, first, last;
    
    queue queue;
    queueInit(&queue, 4);
    
    full = queueIsFull(&queue);
    empty = queueIsEmpty(&queue);
    
    queueEnqueue(&queue, 2);
    size = queueSize(&queue);
    first = queueFirst(&queue);
    last = queueLast(&queue);
    
    queueEnqueue(&queue, 4);
    size = queueSize(&queue);
    first = queueFirst(&queue);
    last = queueLast(&queue);
    
    queueEnqueue(&queue, 6);
    size = queueSize(&queue);
    first = queueFirst(&queue);
    last = queueLast(&queue);
    
    full = queueIsFull(&queue);
    empty = queueIsEmpty(&queue);
    
    dequeueValue = queueDequeue(&queue);
    dequeueValue = queueDequeue(&queue);
    dequeueValue = queueDequeue(&queue);
    
    queueEnqueue(&queue, 2);
    queueEnqueue(&queue, 4);
    queueEnqueue(&queue, 6);
    queueEnqueue(&queue, 8);
    queueEnqueue(&queue, 10);
}

int main()
{
    // debug();
    demo();

    return EXIT_SUCCESS;
}