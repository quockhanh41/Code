#include <iostream>
using namespace std;
class MayLoc
{
private:
    float m_tgian;

protected:
    virtual float congSuat();
    void setTgian(float t);

public:
    MayLoc();
    float tinhLuongNuoc();
};
MayLoc::MayLoc()
{
    this->m_tgian = 0;
}
void MayLoc::setTgian(float t)
{
    this->m_tgian = t;
}
float MayLoc::tinhLuongNuoc()
{
    return congSuat() * m_tgian;
}
float MayLoc::congSuat()
{
    return 0;
}
class MayLyTam : public MayLoc
{
private:
    float m_cs;

protected:
    float congSuat();

public:
    MayLyTam(float cs, float t);
};
MayLyTam::MayLyTam(float cs, float t)
{
    this->m_cs = cs;
    MayLoc::setTgian(t);
    // this->m_tgian = t; /*1*/
}
float MayLyTam::congSuat()
{
    return this->m_cs;
}
int main()
{
    MayLoc *pm = new MayLoc();
    cout << pm << endl;
    MayLyTam ml(81.9, 10);
    delete pm; /*4*/
    pm = &ml;  /*3*/

    cout << pm;
    cout << "Luong nuoc = "
         << pm->tinhLuongNuoc();
}