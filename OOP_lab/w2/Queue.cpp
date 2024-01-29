#include "Queue.h"

Queue::Queue()
{
    arr = new int[(int)1e6];
    frontIndex = rearIndex = -1;
}

Queue::~Queue()
{
    delete[] arr;
}

void Queue::setCapcity(int capacity)
{
    this->capacity = capacity;
}
int Queue::getSize()
{
    if (rearIndex == -1 && frontIndex == -1)
        return 0;
    return rearIndex - frontIndex;
};

bool Queue::isEmpty()
{
    if (getSize() == 0)
        return 1;
    return 0;
};
bool Queue::isFull()
{
    if (getSize() == capacity)
        return 1;
    return 0;
};
void Queue::enqueue(int value)
{
    if (!isFull())
    {
        arr[++rearIndex] = value;
    }
    else
        cout << "Queue is full!\n";
}
void Queue::dequeue()
{
    if (!isEmpty())
    {
        frontIndex++;
    }
    else
        cout << "Queue is empty!\n";
}
int Queue::getValueAtIndex(int index)
{
    return arr[index];
}
