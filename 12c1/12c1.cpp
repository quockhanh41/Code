#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
int n;
struct Student
{
    int stt;
    string name;
    string position;
    string address;
    string phone;
    string email;
};

Student s[50];

int getDataa(Student s[], int &n)
{
    fstream f("12c1.csv", ios::in);
    if (!f)
        return 0;
    f.ignore(32767, '\n');
    string a = "";
    while (getline(f, a, '\n'))
    {
        int i = 0;
        string str[] = {"", "", "", "", "", ""};
        bool gate = 1;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == '"')
                gate = !gate;
            if (a[j] != ',')
                str[i] += a[j];
            else if (gate == 1)
                i++;
        }
        s[n].stt = stoi(str[0]);
        s[n].name = str[1];
        s[n].position = str[2];
        s[n].address = str[3];
        s[n].phone = str[4];
        s[n].email = str[5];
        ++n;
    }
    n--;
    f.close();
    return 1;
}

void printList(Student s[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Stt: " << s[i].stt << endl;
        cout << "Ho va ten: " << s[i].name << endl;
        cout << "Chuc vu: " << s[i].position << endl;
        cout << "Dia chi: " << s[i].address << endl;
        cout << "SDT: " << s[i].phone << endl;
        cout << "Email: " << s[i].email << endl
             << endl;
    }
}
void readBin()
{
    Student a;
    fstream f("12c1.bin", ios::in | ios::binary);
    for (int i = 1; i <= n; i++)
    {
        f.read((char *)&a, sizeof(a));
        cout << "Stt: " << a.stt << endl;
        cout << "Ho va ten: " << a.name << endl;
        cout << "Chuc vu: " << a.position << endl;
        cout << "Dia chi: " << a.address << endl;
        cout << "SDT: " << a.phone << endl;
        cout << "Email: " << a.email << endl;
    }
    f.close();
}
int main()
{

    n = 1;
    if (!getDataa(s, n))
    {
        cout << "Error: Unable to open file! ";
        return 0;
    }
    fstream fout("12c1.bin", ios::out | ios::binary);
    for (int i = 1; i <= n; i++)
    {
        int pos = 0;
        fout.write((char *)&s[i].stt, sizeof(s[i].stt));
        char strname[100] = "";
        for (char c : s[i].name)
            strname[pos++] = c;
        fout.write(strname, sizeof(strname));
        pos = 0;
        char strpos[100] = "";
        for (char c : s[i].position)
            strpos[pos++] = c;
        fout.write(strpos, sizeof(strpos));
        pos = 0;
        char strad[100] = "";
        for (char c : s[i].address)
            strad[pos++] = c;
        fout.write(strad, sizeof(strad));
        pos = 0;
        char strp[100] = "";
        for (char c : s[i].phone)
            strp[pos++] = c;
        fout.write(strp, sizeof(strp));
        pos = 0;
        char stre[100] = "";
        for (char c : s[i].email)
            stre[pos++] = c;
        fout.write(stre, sizeof(stre));
    }
    fout.close();
}