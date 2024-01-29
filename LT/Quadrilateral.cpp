#include "Shape.cpp"
class Quadrilateral : public Shape
{
public:
    Quadrilateral() : Shape(4){};
    double getArea()
    {
        Point A = getPoint(0);
        Point B = getPoint(1);
        Point C = getPoint(2);
        Point D = getPoint(3);
        double AB = A.distance(B);
        double BC = B.distance(C);
        double CA = C.distance(A);
        double p1 = (AB + BC + CA) / 2;
        double S1 = sqrt(p1 * (p1 - AB) * (p1 - BC) * (p1 - CA));
        double AD = A.distance(D);
        double CD = C.distance(D);
        double p2 = (CA + AD + CD) / 2;
        double S2 = sqrt(p2 * (p2 - CA) * (p2 - AD) * (p2 - CD));
        return S2 + S1;
    }
};
int main()
{
    Quadrilateral q;
    q.setPoint();
    cout << q.getArea();
    return 0;
}
