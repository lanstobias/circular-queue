# Circular Queue implementation in C

## Design
Here's the internal structure of the datatype
```c
typedef struct
{
    int rear, front;
    int* array;
    int size;
    int nrOfElements;
} queue;
```

Methods
```c
int queueDequeue(queue* self);
int queueEnqueue(queue* self, int value);
void queueClear(queue* self);
int queueIsFull(queue* self);
int queueIsEmpty(queue* self);
int queueSize(queue* self);
int queueFirst(queue* self);
int queueLast(queue* self);
```

## Usage
```c
// Create queue object
queue queue;

// Initialize the queue with given size
queueInit(&queue, 100);

// Add values to the queue
queueEnqueue(&queue, 2);
queueEnqueue(&queue, 4);
queueEnqueue(&queue, 6);

// Get first in queue
int dequeueVal = queueDequeue(&queue); // <-- 2
```

## Tests
There are tests for all methods. To create the executable tests file, run the make command
```shell
$ make tests
```

You can then execute the test file as shown below
```
$ ./tests
Testing newQueue().. passed!
Testing queueSize().. passed!
Testing queueEnqueue().. passed!
Testing queueDequeue().. passed!
Testing queueClear().. passed!
Testing queueFirst().. passed!
Testing queueLast().. passed!
Testing queueIsFull().. passed!
Testing queueIsEmpty().. passed!

All tests passed! :)
```
