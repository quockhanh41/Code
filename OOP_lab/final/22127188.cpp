#include <iostream>
#include <vector>
using namespace std;
class Film
{
private:
    string ID;
    string name;
    string director;
    double time;
    double basicTicketPrice;

public:
    Film(){};
    Film(string ID, string name, string director, double time, double basicTicketPrice)
    {
        this->ID = ID;
        this->name = name;
        this->director = director;
        this->time = time;
        this->basicTicketPrice = basicTicketPrice;
    };
    double getBasicTicketPrice()
    {
        return basicTicketPrice;
    }
    string getName() { return name; }
};

class Customer
{
private:
    string ID;
    string name;
    string phoneNumber;

public:
    Customer(){};
    Customer(string ID, string name, string phoneNumber)
    {
        this->ID = ID;
        this->name = name;
        this->phoneNumber = phoneNumber;
    };
    string getName() { return name; }
};

class Ticket
{
private:
    long long ID;
    Customer customer;
    string seatID;
    string time;
    Film film;
    int type; // 1: night, 2: day, 3: weekend

public:
    Ticket(long long ID, Customer customer, string seatID, string time, Film film, int type)
    {
        this->ID = ID;
        this->customer = customer;
        this->seatID = seatID;
        this->time = time;
        this->film = film;
        this->type = type;
    };
    double getPrice()
    {
        if (type == 1)
            return getNightTicketPrice();
        else if (type == 2)
            return getDayTimeTicketPrice();
        return getWeekendTicketPrice();
    }
    double getSalePrice(double discount)
    {
        return getPrice() * (100 - discount) / 100;
    }
    long long getID() { return ID; }
    double getNightTicketPrice()
    {
        return film.getBasicTicketPrice() * 1.1;
    }
    double getDayTimeTicketPrice()
    {
        return getNightTicketPrice() * 0.7;
    }
    double getWeekendTicketPrice()
    {
        return film.getBasicTicketPrice() * 1.3;
    }
    void printInfo()
    {
        cout << "Ticket ID: " << ID << '\n';
        cout << "Customer: " << customer.getName() << '\n';

        cout << "Film: " << film.getName() << '\n';

        cout << "Seat ID: " << seatID << '\n';
        cout << "Time: " << time << '\n';
        cout << "Price: ";
        if (type == 1)
        {
            cout << getNightTicketPrice();
        }
        else if (type == 2)
        {
            cout << getDayTimeTicketPrice();
        }
        else
            cout << getWeekendTicketPrice();
        cout << '\n';
    }
};
static long long numberTicket = 0;
class TicketManager
{
private:
    vector<Ticket *> ticketList;

public:
    TicketManager(){};
    TicketManager(vector<Ticket *> ticketList)
    {
        this->ticketList = ticketList;
    };
    void addSoldTicket(Ticket *ticket)
    {
        ticketList.push_back(ticket);
    }
    Ticket *getTicket(Customer customer, Film film, string time, int type, double discount)
    {
        numberTicket++;
        Ticket *t = new Ticket(numberTicket, customer, "E7", time, film, type);
        addSoldTicket(t);
        return t;
    }
    Ticket *findTicketByID(long long ID)
    {
        for (auto x : ticketList)
        {
            if (x->getID() == ID)
                return x;
        }
        return nullptr;
    }
    double getTotalIncome()
    {
        double income = 0;
        for (auto x : ticketList)
        {
            income += x->getPrice();
        }
        return income;
    }
};

int main()
{
    Film phim_hai("123", "phim hai", "tran thanh", 2, 100);
    Film phim_ma("999", "phim ma", "nhat cuong", 1, 200);
    Customer khanh("188", "khanh", "0865436897");
    Customer thanh("233", "thanh", "0973177389");
    Customer thuy("477", "thuy", "0392935506");
    Ticket t(16548, khanh, "12", "15h 4/12022", phim_hai, 2);
    TicketManager m;

    Ticket *t1 = m.getTicket(khanh, phim_hai, "12h 4/1/2020", 2, 0);
    Ticket *t2 = m.getTicket(thuy, phim_ma, "19h 2/7/2020", 1, 0);
    Ticket *t3 = m.getTicket(thanh, phim_hai, "15h 4/1/2020", 3, 0);

    // (*m.findTicketByID(1)).printInfo();
    // (*m.findTicketByID(2)).printInfo();
    // (*m.findTicketByID(3)).printInfo();

    Customer SinhvienA("223", "kiet", "0651586131");
    Ticket *t4 = m.getTicket(SinhvienA, phim_hai, "15h 4/1/2020", 2, 30.0);
    long long ID_A = t4->getID();
    (*m.findTicketByID(ID_A)).printInfo();
    Customer KhachHangVIPB("156", "Andrew", "987441651");
    Ticket *t5 = m.getTicket(KhachHangVIPB, phim_ma, "15h 8/1/2020", 2, 15.0);
    long long ID_B = t5->getID();
    (*m.findTicketByID(ID_B)).printInfo();

    cout << "Tong doanh thu ban ve la: " << m.getTotalIncome();

    return 0;
}