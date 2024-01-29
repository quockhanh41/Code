#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class Room
{
private:
    double price;

public:
    Room(double price)
    {
        this->price = price;
    };
    double getPrice() { return price; }
};
class Room_A : public Room
{
public:
    Room_A() : Room(14000000){};
};
class Room_B : public Room
{
public:
    Room_B() : Room(900000){};
};
class Room_C : public Room
{
public:
    Room_C() : Room(600000){};
};
class Patient
{
private:
    int ID;
    string history;

public:
    void addHistory(string newHistory)
    {
        history += newHistory + "\n";
    }
    void showHistory() { cout << history; }
    Patient(int ID)
    {
        this->ID = ID;
        history = "";
    };
    int getID() { return ID; }
    virtual double getFee() = 0;
};
class InPatient : public Patient
{
private:
    Room *room;
    double feeDay;
    int startedDay;
    int finishedDay;

public:
    InPatient(int ID,
              int startedDay,
              int finishedDay, Room *room, double feeDay) : Patient(ID)
    {
        this->finishedDay = finishedDay;
        this->startedDay = startedDay;
        this->feeDay = feeDay;
        this->room = room;
    };
    int getStartedDay() { return startedDay; }
    int getFinishedDay() { return finishedDay; }

    void setStartedDay(int startedDay)
    {
        this->startedDay = startedDay;
    }
    void setFinishedDay(int finishedDay)
    {
        this->finishedDay = finishedDay;
    }
    double getFee() override
    {
        return (finishedDay - startedDay) * (feeDay + room->getPrice());
    }
};

class OutPatient : public Patient
{
private:
    double fee;

public:
    OutPatient(int ID, double fee) : Patient(ID)
    {
        this->fee = fee;
    };
    double getFee() override
    {
        return fee;
    }
};
Patient *findPatientByID(const vector<Patient *> &v, int ID)
{
    for (auto x : v)
    {
        if (x->getID() == ID)
            return x;
    }
    return nullptr;
}
void getDataFromFile(const string fileName, vector<Patient *> &listPatient)
{
    fstream f(fileName, ios ::in);
    if (!f.is_open())
    {
        cout << "Could not able to open file " << fileName;
        return;
    }
    string s;
    while (getline(f, s))
    {
        string data[6];
        int index = 0;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (i == s.size() - 1 && s[i] != ' ')
            {
                temp += s[i];
                data[index++] = temp;
            }
            else if (s[i] == ' ')
            {
                data[index++] = temp;
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        Patient *p = findPatientByID(listPatient, stoi(data[1]));
        if (!p)
            cout << "null";
        if (data[2] == "KB")
        {
            listPatient.push_back(new OutPatient(stoi(data[1]), stod(data[3])));
        }
        else if (data[2] == "NV")
        {
            if (data[4] == "A")
                listPatient.push_back(new InPatient(stoi(data[1]), stoi(data[0]), stoi(data[0]), new Room_A, stod(data[3])));
            else if (data[4] == "B")
                listPatient.push_back(new InPatient(stoi(data[1]), stoi(data[0]), stoi(data[0]), new Room_B, stod(data[3])));
            else if (data[4] == "C")
                listPatient.push_back(new InPatient(stoi(data[1]), stoi(data[0]), stoi(data[0]), new Room_C, stod(data[3])));
        }
        else if (data[2] == "XV")
        {
            Patient *patient = findPatientByID(listPatient, stoi(data[1]));
            ((InPatient *)patient)->setFinishedDay(stoi(data[0]));
        }
        else if (data[2] == "TKVP")
        {
            for (int i = 0; i < listPatient.size(); i++)
            {
                if (InPatient *inpatient = dynamic_cast<InPatient *>(listPatient[i]))
                {
                    if (inpatient->getFinishedDay() == inpatient->getStartedDay())
                        inpatient->setFinishedDay(stoi(data[0]));
                }
            }
        }

        // if (!p)
        //     cout << p->getID();
        // p->addHistory(s);
    }
}
double getTotalFee(vector<Patient *> listPatient)
{
    double fee = 0;
    for (auto x : listPatient)
        fee += x->getFee();
    return fee;
}
int main()
{
    vector<Patient *> v;
    getDataFromFile("Data.txt", v);
    for (auto x : v)
        cout << x->getID() << " " << x->getFee() << "\n";
    cout << getTotalFee(v);
    return 0;
}