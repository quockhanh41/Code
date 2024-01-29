#include <iostream>
#include <stdexcept>

class Queue
{
private:
    int maxSize;
    int front;
    int rear;
    int *queueArray;

public:
    Queue(int size);

    void enqueue(int value);

    int dequeue();

    int getFront();

    bool isEmpty();

    bool isFull();

    ~Queue();
};