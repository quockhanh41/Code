

#include <math.h>
#include <stdio.h>
class Function
{
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};
class Sin : public Function
{
public:
    double Value(double x)
    {
        return sin(x);
    }
    double Derive(double x)
    {
        return cos(x);
    }
};
double DeriveProduct(Function *f, Function *g, double x)
{
    if (f != NULL && g != NULL)
    {
        return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
    }
    return 0;
}
double DeriveSum(Function *f, Function *g, double x)
{
    if (f != NULL && g != NULL)
    {
        return f->Derive(x) + g->Derive(x);
    }
    return 0;
}
int main()
{
    double x = 3.14 / 6; // PI/6
    Sin *s = new Sin();
    double y = DeriveProduct(s, s, x);
    printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
    printf("y = %f\n", y);
}