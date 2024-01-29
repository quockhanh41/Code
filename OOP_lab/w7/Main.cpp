#include <iostream>
#include <vector>
#include "Array.h"
#include "Date.h"
#include "File.h"
#include "Fraction.h"
#include "Integer.h"
#include "Time.h"
#include "Queue.h"
using namespace std;

int main()
{
    // bai 1 ---------------------------------------------------------
    Fraction myFraction;
    int num, den;
    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;
    try
    {
        myFraction.SetValue(num, den);
        int ans = myFraction.GetNumerator() / myFraction.GetDenominator();
        cout << ans << endl;
    }
    catch (DividedByZeroException &ex)
    {
        cout << ex.what() << endl;
    }

    // bai 2 ---------------------------------------------------------
    try
    {
        Array myArray(5);

        for (int i = 0; i < 5; ++i)
        {
            myArray.getValueAt(i) = i * 10;
        }
        int value = myArray.getValueAt(10);
        cout << "Value at index 10: " << value << endl;
    }
    catch (IndexOutOfRangeException &ex)
    {
        cout << ex.what() << endl;
    }

    // bai 3 ---------------------------------------------------------
    string filePath;

    cout << "Enter the file path: ";
    cin >> filePath;

    try
    {
        openFile(filePath);
    }
    catch (FileNotFoundException &ex)
    {
        std::cerr << ex.what() << endl;
    }

    // bai 4 ---------------------------------------------------------
    string s;
    cout << "Enter a string to change to integer: ";
    cin >> s;
    try
    {
        changeToInteger(s);
    }
    catch (const IntegerFormatException &e)
    {
        std::cerr << e.what() << '\n';
    }

    // bai 5 ---------------------------------------------------------
    int day, month, year;
    char x;
    cout << "Enter dd/mm/yyyy: ";
    cin >> day >> x >> month >> x >> year;
    try
    {
        checkDateFormat(day, month, year);
    }
    catch (const DateFormatException &e)
    {
        std::cerr << e.what() << '\n';
    }

    // bai 6 ---------------------------------------------------------
    int hour, minute, second;
    cout << "Enter hh/mm/ss: ";
    cin >> hour >> x >> minute >> x >> second;
    try
    {
        checkTimeFormat(hour, minute, second);
    }
    catch (const TimeFormatException &e)
    {
        std::cerr << e.what() << '\n';
    }
    // bai 7 ------------------------------------------------------------
    Queue myQueue(5);

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element of Queue: " << myQueue.getFront() << std::endl;
    while (!myQueue.isEmpty())
    {
        std::cout << "Dequeued from Queue: " << myQueue.dequeue() << std::endl;
    }
    try
    {
        myQueue.dequeue(); 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}