#include "Stack.h"
template <class T>
Stack<T>::Stack()
{
    size = 0;
    capacity = (int)1e6;
    data = new T[(int)1e6];
};
template <class T>
Stack<T>::Stack(int n)
{
    data = new T[n];
    size = 0;
    capacity = n;
};
template <class T>
Stack<T>::~Stack()
{
    delete[] data;
};
template <class T>
void Stack<T>::clear()
{
    ~Stack();
    Stack();
};
template <class T>
bool Stack<T>::isFull()
{
    return size >= capacity;
};
template <class T>
bool Stack<T>::isEmpty()
{
    return size == 0;
};
template <class T>
void Stack<T>::push(const T &item)
{
    if (!Stack::isFull())
        data[size++] = item;
    else
        cout << "Stack is full!\n";
};
template <class T>
T Stack<T>::pop()
{
    if (!isEmpty())
    {
        T *temp = &data[size - 1];
        T temp1 = data[size - 1];
        delete temp;
        size--;
        return temp1;
    }
    else
    {
        cout << "Stack is empty!\n";
        return T(-1);
    }
};
template <class T>
T Stack<T>::getTop()
{
    if (isEmpty())
        cout << "Stack is empty!\n";
    return data[size - 1];
};
template <class T>
int Stack<T>::getSize()
{
    return size;
};
template <class T>
T Stack<T>::At(int index)
{
    return data[index];
};