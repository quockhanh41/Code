#include "Array.h"

int &Array::getValueAt(int index) const
{
    if (index < 0 || index >= size)
    {
        throw IndexOutOfRangeException();
    }
    return arr[index];
}

Array::~Array()
{
    delete[] arr;
}

