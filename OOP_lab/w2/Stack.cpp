#include "Stack.h"
Stack::Stack()
{
    arr = new int[(int)1e6];
};

Stack::Stack(int size, int value)
{
    arr = new int[(int)1e6];
    for (int i = 0; i < size; i++)
        arr[i] = value;
    this->size = size;
};
Stack::Stack(int capacity, int size, int value)
{
    this->capacity = capacity;
    this->size = size;
    arr = new int[capacity];
    for (int i = 0; i < size; i++)
        arr[i] = value;
};
Stack::~Stack()
{
    delete[] arr;
}
int Stack::getSize() { return size; }
void Stack::setCapacity(int capacity) { this->capacity = capacity; }
int Stack::getValueAtIndex(int index)
{
    return arr[index];
}

bool Stack::isEmpty()
{
    return size == 0;
}
bool Stack::isFull()
{
    return size == capacity;
}
void Stack::push(int value)
{
    if (!Stack::isFull())
        arr[size++] = value;
    else
        cout << "Stack is full!\n";
}
void Stack::pop()
{
    if (!Stack::isEmpty())
        size--;
    else
        cout << "Stack is empty!\n";
}
int Stack::getTopValue()
{
    return arr[size - 1];
}
