#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "Queue.h"

// Function declarations
void testNewQueue(void);
void testQueueSize(void);
void testEnqueue(void);
void testDequeue(void);
void testClear(void);
void testIsFull(void);
void testIsEmpty(void);
void testFirst(void);
void testLast(void);

int main()
{
    // Run tests
    testNewQueue();
    testQueueSize();
    testEnqueue();
    testDequeue();
    testClear();
    testFirst();
    testLast();
    testIsFull();
    testIsEmpty();

    printf("\nAll tests passed! :)\n");
    return EXIT_SUCCESS;
}

// Funciton definitions
void testNewQueue(void)
{
    printf("Testing newQueue().. ");

    queue testQueue;
    queueInit(&testQueue, 10);

    printf("passed!\n");
    queueDestroy(&testQueue);
}

void testQueueSize(void)
{
    printf("Testing queueSize().. ");

    queue testQueue;
    queueInit(&testQueue, 5);

    assert(queueSize(&testQueue) == 0);

    queueEnqueue(&testQueue, 2);
    queueEnqueue(&testQueue, 4);
    queueEnqueue(&testQueue, 6);
    queueEnqueue(&testQueue, 8);

    assert(queueSize(&testQueue) == 4);

    queueDequeue(&testQueue);
    queueDequeue(&testQueue);

    assert(queueSize(&testQueue) == 2);

    queueDequeue(&testQueue);
    queueDequeue(&testQueue);
    queueDequeue(&testQueue);

    assert(queueSize(&testQueue) == 0);

    printf("passed!\n");

    queueDestroy(&testQueue);
}

void testEnqueue(void)
{
    printf("Testing queueEnqueue().. ");

    queue testQueue;
    queueInit(&testQueue, 5);

    assert(queueSize(&testQueue) == 0);

    queueEnqueue(&testQueue, 2);
    queueEnqueue(&testQueue, 4);
    queueEnqueue(&testQueue, 6);

    assert(queueSize(&testQueue) == 3);

    assert(queueFirst(&testQueue) == 2);

    printf("passed!\n");
    queueDestroy(&testQueue);
}

void testDequeue(void)
{
    printf("Testing queueDequeue().. ");

    queue testQueue;
    queueInit(&testQueue, 5);

    queueEnqueue(&testQueue, 2);
    queueEnqueue(&testQueue, 4);
    queueEnqueue(&testQueue, 6);

    assert(queueDequeue(&testQueue) == 2);

    queueEnqueue(&testQueue, 8);
    queueEnqueue(&testQueue, 10);

    assert(queueDequeue(&testQueue) == 4);
    assert(queueDequeue(&testQueue) == 6);
    assert(queueDequeue(&testQueue) == 8);

    printf("passed!\n");
    queueDestroy(&testQueue);
}

void testClear(void)
{
    printf("Testing queueClear().. ");

    queue testQueue;
    queueInit(&testQueue, 5);

    assert(queueSize(&testQueue) == 0);

    queueEnqueue(&testQueue, 2);
    queueEnqueue(&testQueue, 4);
    queueEnqueue(&testQueue, 6);

    assert(queueSize(&testQueue) == 3);
    assert(queueFirst(&testQueue) == 2);
    
    queueClear(&testQueue);
    
    assert(queueIsEmpty(&testQueue));
    assert(queueSize(&testQueue) == 0);
    assert(queueFirst(&testQueue) == 0);
    
    queueEnqueue(&testQueue, 2);
    queueEnqueue(&testQueue, 4);

    assert(queueSize(&testQueue) == 2);
    assert(queueFirst(&testQueue) == 2);

    printf("passed!\n");
    queueDestroy(&testQueue);
}

void testIsFull(void)
{
    printf("Testing queueIsFull().. ");

    queue testQueue;
    queueInit(&testQueue, 5);

    assert(!queueIsFull(&testQueue));

    queueEnqueue(&testQueue, 2);
    queueEnqueue(&testQueue, 4);

    assert(!queueIsFull(&testQueue));

    queueEnqueue(&testQueue, 6);
    queueEnqueue(&testQueue, 8);
    queueEnqueue(&testQueue, 10);

    assert(queueIsFull(&testQueue));

    queueEnqueue(&testQueue, 12);
    queueEnqueue(&testQueue, 14);

    assert(queueIsFull(&testQueue));

    printf("passed!\n");
    queueDestroy(&testQueue);
}

void testIsEmpty(void)
{
    printf("Testing queueIsEmpty().. ");

    queue testQueue;
    queueInit(&testQueue, 5);

    assert(queueIsEmpty(&testQueue));

    queueEnqueue(&testQueue, 2);

    assert(!queueIsEmpty(&testQueue));

    queueEnqueue(&testQueue, 4);
    queueEnqueue(&testQueue, 6);
    queueEnqueue(&testQueue, 8);
    queueEnqueue(&testQueue, 10);

    assert(!queueIsEmpty(&testQueue));

    queueEnqueue(&testQueue, 12);
    queueEnqueue(&testQueue, 14);

    assert(!queueIsEmpty(&testQueue));

    queueDequeue(&testQueue);
    queueDequeue(&testQueue);
    queueDequeue(&testQueue);
    queueDequeue(&testQueue);
    queueDequeue(&testQueue);

    assert(queueIsEmpty(&testQueue));

    printf("passed!\n");
    queueDestroy(&testQueue);
}

void testFirst(void)
{
    printf("Testing queueFirst().. ");

    queue testQueue;
    queueInit(&testQueue, 4);
    assert(queueIsFull(&testQueue) == 0);
    // [ | | | ]

    assert(queueFirst(&testQueue) == 0);

    queueEnqueue(&testQueue, 2);
    assert(queueIsFull(&testQueue) == 0);
    // [2| | | ]
    
    assert(queueFirst(&testQueue) == 2);

    queueEnqueue(&testQueue, 4);
    assert(queueIsFull(&testQueue) == 0);
    // [2|4| | ]
    
    queueEnqueue(&testQueue, 6);
    assert(queueIsFull(&testQueue) == 0);
    // [2|4|6| ]
    
    queueEnqueue(&testQueue, 8);
    assert(queueIsFull(&testQueue) == 1);
    // [2|4|6|8]
    
    
    int last = queueLast(&testQueue);

    queueEnqueue(&testQueue, 10); // Full
    // [2|4|6|8]
    
   last = queueLast(&testQueue);

    assert(queueFirst(&testQueue) == 2);

    queueDequeue(&testQueue);
    // [4|6|8| ]

    assert(queueFirst(&testQueue) == 4);

    queueDequeue(&testQueue);
    // [6|8| | ]
    
    assert(queueFirst(&testQueue) == 6);
    
    queueDequeue(&testQueue);
    // [8| | | ]

    assert(queueFirst(&testQueue) == 8);

    printf("passed!\n");
    queueDestroy(&testQueue);
}

void testLast(void)
{
    printf("Testing queueLast().. ");

    queue testQueue;
    queueInit(&testQueue, 4);

    // [ | | | ]
    assert(queueLast(&testQueue) == 0);

    queueEnqueue(&testQueue, 2);
    // [2| | | ]
    assert(queueLast(&testQueue) == 2);

    queueEnqueue(&testQueue, 4);
    // [2|4| | ]
    assert(queueLast(&testQueue) == 4);
    
    queueEnqueue(&testQueue, 6);
    // [2|4|6| ]
    assert(queueLast(&testQueue) == 6);
    
    queueEnqueue(&testQueue, 8);
    // [2|4|6|8]
    assert(queueLast(&testQueue) == 8);
    
    queueEnqueue(&testQueue, 10); // Full
    // [2|4|6|8]
    assert(queueLast(&testQueue) == 8);

    queueDequeue(&testQueue);
    // [4|6|8| ]
    assert(queueLast(&testQueue) == 8);

    queueDequeue(&testQueue);
    // [6|8| | ]
    assert(queueLast(&testQueue) == 8);
    
    queueDequeue(&testQueue);
    // [8| | | ]
    assert(queueLast(&testQueue) == 8);

    queueDequeue(&testQueue);
    // [ | | | ]
    assert(queueLast(&testQueue) == 0);

    printf("passed!\n");
    queueDestroy(&testQueue);
}