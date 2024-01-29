#include <iostream>
#include <vector>
using namespace std;
class MayXucTac
{
private:
    double congSuat;
    double thoiGian;
    double hoaChat;

public:
    MayXucTac(){};
    MayXucTac(double congSuat,
              double thoiGian,
              double hoaChat)
    {
        this->congSuat = congSuat;
        this->thoiGian = thoiGian;
        this->hoaChat = hoaChat;
    };
    double congSuatLoc()
    {
        if (thoiGian < 10)
            return hoaChat / 100 * congSuat;
        return hoaChat / 100 * congSuat / (thoiGian / 10);
    }
    double tinhLuongNuoc()
    {
        return congSuatLoc() * thoiGian;
    }
    double phiThue()
    {
        return 80000 * thoiGian;
    }
    double tinhChiPhi()
    {
        return phiThue() + hoaChat * 10000;
    }
    void nhap()
    {
        cout << "Cong suat: ";
        cin >> this->congSuat;
        cout << "Thoi gian: ";
        cin >> this->thoiGian;
        cout << "Hoa chat: ";
        cin >> this->hoaChat;
    }
    static string DON_GIA_HOA_CHAT;
};
string MayXucTac::DON_GIA_HOA_CHAT = "80";
int main()
{
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
    MayXucTac m;
    m.nhap(); // Nhập thông tin sử dụng của máy xúc tác này
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;

    return 0;
}