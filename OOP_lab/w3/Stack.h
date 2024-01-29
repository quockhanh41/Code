#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
    T *data;
    int size;
    int capacity;

public:
    Stack();
    Stack(int n);
    ~Stack();
    void clear();
    bool isFull();
    bool isEmpty();
    void push(const T &item);
    T pop();
    T getTop();
    int getSize();
    T At(int index);
};