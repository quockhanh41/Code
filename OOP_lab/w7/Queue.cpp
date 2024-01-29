#include "Queue.h"
Queue::Queue(int size)
{
    maxSize = size + 1; // One extra space for better implementation
    queueArray = new int[maxSize];
    front = 0;
    rear = -1;
}

void Queue::enqueue(int value)
{
    if (isFull())
    {
        throw std::overflow_error("Queue is full. Cannot enqueue more elements.");
    }
    rear = (rear + 1) % maxSize;
    queueArray[rear] = value;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        throw std::underflow_error("Queue is empty. Cannot dequeue more elements.");
    }
    int removedItem = queueArray[front];
    front = (front + 1) % maxSize;
    return removedItem;
}

int Queue::getFront()
{
    if (isEmpty())
    {
        throw std::underflow_error("Queue is empty. Cannot get front element.");
    }
    return queueArray[front];
}

bool Queue::isEmpty()
{
    return (rear + 1) % maxSize == front;
}

bool Queue::isFull()
{
    return (rear + 2) % maxSize == front;
}

Queue::~Queue()
{
    delete[] queueArray;
}
