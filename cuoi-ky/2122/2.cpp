#include <iostream>
#include <vector>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base::Base()" << endl;
    }

    Base(int t)
    {
        cout << "Base::Base(int)" << endl;
    }

    Base(int t, int k)
    {
        cout << "Base::Base(int, int)" << endl;
    }

    Base(const Base &src)
    {
        cout << "Base::Base(const Base&)" << endl;
    }

    Base &operator=(const Base &src)
    {
        cout << "Base::operator=()" << endl;
        return *this;
    }

    virtual void doSth(int x)
    {
        cout << "Base::doSth(int)" << endl;
    }

    void doSthE(int x)
    {
        cout << "Base::doSthE(int)" << endl;
    }

    virtual ~Base()
    {
        cout << "Base::~Base()" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived::Derived()" << endl;
    }

    Derived(int t) : Base(t)
    {
        cout << "Derived::Derived(int)" << endl;
    }

    Derived(int t, int k)
    {
        cout << "Derived::Derived(int, int)" << endl;
    }

    Derived(const Derived &src) : Base(src)
    {
        cout << "Derived::Derived(const Derived&)" << endl;
    }

    Derived &operator=(const Derived &src)
    {
        cout << "Derived::operator=()" << endl;
        return *this;
    }

    void doSth(int x)
    {
        cout << "Derived::doSth(int)" << endl;
    }

    void doSthE(int x)
    {
        cout << "Derived::doSthE(int)" << endl;
    }

    ~Derived()
    {
        cout << "Derived::~Derived()" << endl;
    }
};

void testing(Base &first, Derived second)
{
    cout << "\nTesting 3: " << endl;
    Derived x;
    x = second;
    first.doSth(1);
    first.doSthE(2);

    cout << "\nTesting 4: " << endl;
    x.doSth(3);
    x.doSthE(4);
}
int main()
{
    cout << "Testing 1: " << endl;
    Derived x(5), y(3, 7);
    cout << "\nTesting 2: " << endl;
    testing(x, y);
    cout << "\nTesting 5: " << endl;
    return 0;
}
// Testing 1: 
// Base::Base(int)
// Derived::Derived(int)
// Base::Base()
// Derived::Derived(int, int)

// Testing 2: 
// Base::Base(const Base&)
// Derived::Derived(const Derived&)

// Testing 3: 
// Base::Base()
// Derived::Derived()
// Derived::operator=()
// Derived::doSth(int)
// Base::doSthE(int)

// Testing 4: 
// Derived::doSth(int)
// Derived::doSthE(int)
// Derived::~Derived()
// Base::~Base()// Derived::~Derived()
// Base::~Base()

// Testing 5: 
// Derived::~Derived()
// Base::~Base()
// Derived::~Derived()
// Base::~Base()

