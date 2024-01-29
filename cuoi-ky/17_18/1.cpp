#include <iostream>
#include <vector>
using namespace std;
class Myfloat
{
protected:
    char *mData;

public:
    Myfloat()
    {
        cout << 1;
    };
    Myfloat(float v)
    {
        cout << 3;
        mData = new char[10];
        snprintf(mData, sizeof(mData), "%f", v);
    };
    operator char *() const { return mData; }
    static Myfloat valueOf(float value)
    {
        cout << 2;
        Myfloat temp(value);
        return temp;
    }
    friend istream &operator>>(istream &is, Myfloat &f);
    friend ostream &operator<<(ostream &os, const Myfloat *f);
};
istream &operator>>(istream &is, Myfloat &f)
{
    float x;
    is >> x;
    f = Myfloat(x);
    return is;
};
ostream &operator<<(ostream &os, const Myfloat *f)
{
    os << f->mData;
    return os;
};
class MyComplex : public Myfloat
{
private:
    char *mImaginary;

public:
    MyComplex(){};
    MyComplex(float a, float b)
    {
        mData = Myfloat(a);
        mImaginary = Myfloat(b);
    };
    MyComplex &operator=(const MyComplex &c)
    {
        if (c.mData == mData && c.mImaginary == mImaginary)
            return *this;
        this->mData = c.mData;
        this->mImaginary = c.mImaginary;
        return *this;
    }
};
class PI : public Myfloat
{
private:
    static Myfloat *instance;
    PI()
    {
        instance = new Myfloat(3.14);
    }

public:
    static Myfloat *getInstance()
    {
        if (!instance)
        {
            instance = new PI();
        }
        return instance;
    }
};
Myfloat *PI::instance = nullptr;

int main()
{
    char *s = Myfloat::valueOf(456.0);
    cout << s;
    return 0;
}