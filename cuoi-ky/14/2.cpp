#include <iostream>
#include <vector>
using namespace std;
class IFace
{
public:
    virtual void show() = 0;
    virtual IFace *clone() = 0;
    virtual ~IFace()
    {
    }
};
class Face : public IFace
{
private:
    string shape;

protected:
    string getShape();

public:
    Face(){};
    Face(string sh) : shape(sh)
    {
    }
    virtual void show()
    {
        cout << "Shape :" << shape << endl;
    }
    IFace *clone()
    {
        return new Face(shape);
    };
};
class EyedFace
{
private:
    string shape;
    int eyes;

public:
    static int countInstance;
    EyedFace(){};
    EyedFace(string shape, int eyes)
    {
        countInstance++;
        this->shape = shape;
        this->eyes = eyes;
    };
    void show()
    {
        cout << shape << " " << eyes;
    }
    EyedFace *clone()
    {
        return new EyedFace(shape, eyes);
    }
    ~EyedFace()
    {
        countInstance--;
    }
};
int EyedFace::countInstance = 0;
void testFace(IFace *fc)
{
    IFace *a[3] = {fc, fc->clone(), fc->clone()};
    for (int i = 0; i < 3; i++)
    {
        a[i]->show();
        delete a[i];
    }

    cout << "The same 3 lines ?";
}
int main()
{
    Face fc;
    Face fc1("“Rectangle”");
    testFace(&fc1);
    return 0;
}