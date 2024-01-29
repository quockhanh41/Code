#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int capacity = (int)1e6;
    int size = 0;

public:
    Stack();
    Stack(int size, int value);
    Stack(int capacity, int size, int value);
    void setCapacity(int capacity);
    ~Stack();
    int getSize();
    int getValueAtIndex(int index);
    bool isEmpty();
    bool isFull();
    void push(int value);
    void pop();
    int getTopValue();
};
