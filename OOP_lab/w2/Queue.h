#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int frontIndex;
    int rearIndex;
    int capacity = (int)1e6;

public:
    Queue();
    ~Queue();
    void setCapcity(int);
    int getSize();
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    void dequeue();
    int getValueAtIndex(int index);
};
