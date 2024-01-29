// #include <iostream>
// #include <vector>
// using namespace std;
// class A
// {
// private:
//     int *a;

// public:
//     A()
//     {
//         a = new int[3];
//         for (int i = 0; i < 3; i++)
//             a[i] = i + 1;
//     }
//     ~A() { delete[] a; }
//     void showAdd() { cout << a; }
//     A(const A &other)
//     {
//         a = new int[3];
//         std::copy(other.a, other.a + 3, a);
//     }
//     A operator=(const A &other)
//     {
//         if (this == &other)
//             return *this;
//         this->a = new int[3];
//         std::copy(other.a, other.a + 3, this->a);
//         return *this;
//     }
// };
// void init(A &a)
// {
//     A b;
//     a = b;
//     b.showAdd();
//     cout << endl;
//     a.showAdd();
// }
// int main()
// {
//     A obj;
//     init(obj);
// }
#include <iostream>
#include <cstring>

struct Base
{
    Base(const char *s) { m_str = strdup(s); }
    Base(const Base &b) { m_str = strdup(b.m_str); }
    ~Base()
    {
        std::cout << "~" << m_str << "\n";
        delete[] m_str;
    }
    Base &operator=(const Base &b)
    {
        std::cout << m_str << " = " << b.m_str << "\n";
        Base tmp(b);
        std::swap(m_str, tmp.m_str);
        return *this;
    }

private:
    char *m_str;
};

struct Derive : public Base
{
    Derive(const char *s) : Base(s) {}
};
int main()
{
    Derive d1("hello");
    Derive d2("world");
    d1 = d1; // Assign to itself.
    d2 = d1;
}