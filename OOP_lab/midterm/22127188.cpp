#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Account
{
private:
    string CCCD;
    string fullname;
    double balance;

public:
    Account(){};
    Account(string CCCD, string fullname)
    {
        this->CCCD = CCCD;
        this->fullname = fullname;
        this->balance = 0;
    }
    Account(string CCCD, string fullname, double balance)
    {
        this->CCCD = CCCD;
        this->fullname = fullname;
        this->balance = balance;
    }
    void deposit(double money)
    {
        cout << fullname << " 's account deposit " << money << " completed!\n";
        balance += money;
    }
    void withdraw(double money)
    {
        if (balance - money >= 50000)
        {
            balance -= money;
            cout << fullname << " 's account withdraw " << money << " completed!\n";
        }
        else
            cout << "Error! " << fullname << "'s balance is less than " << money << '\n';
    }
    double getBalance() { return balance; }
    string getFullname() { return fullname; }
    bool operator>(const Account &other)
    {
        return balance > other.balance;
    };
    bool operator<(const Account &other)
    {
        return balance < other.balance;
    };
    bool operator==(const Account &other)
    {
        return balance == other.balance;
    };
    bool operator>=(const Account &other)
    {
        return balance >= other.balance;
    };
    bool operator<=(const Account &other)
    {
        return balance <= other.balance;
    };
    void display()
    {
        cout << "Chu tai khoan: " << fullname << '\n';
        cout << "CCCD: " << CCCD << '\n';
        cout << "So du: " << balance << '\n';
    }
};

bool cmp_acount_by_decrease_balance(Account *a, Account *b)
{
    return (*a).getBalance() > (*b).getBalance();
}
class Bank
{
private:
    string address;
    string name;
    vector<Account *> accountList;

public:
    Bank(string name, string address)
    {
        this->address = address;
        this->name = name;
    };
    void AddAccount(Account *account)
    {
        accountList.push_back(account);
    }
    void display()
    {
        sort(accountList.begin(), accountList.end(), cmp_acount_by_decrease_balance);
        for (Account *x : accountList)
            (*x).display();
    }
    double getTotalBalance()
    {
        double total = 0;
        for (auto x : accountList)
            total += (*x).getBalance();
        return total;
    }
    Account getRichestAccount()
    {
        Account res = *accountList[0];
        for (int i = 1; i < accountList.size(); i++)
            if ((*accountList[i]).getBalance() > res.getBalance())
                res = *accountList[i];
        return res;
    }
};
class SubAccount : public Account
{
private:
    Account *rootAccount;

public:
    SubAccount(string CCCD, string fullname, Account *rootAccount) : Account(CCCD, fullname)
    {
        this->rootAccount = rootAccount;
    }

    void deposit(double money)
    {
        (*rootAccount).deposit(money);
    }

    void withdraw(double money)
    {
        (*rootAccount).withdraw(money);
        if (money < 3000000)
            cout << "Error! " << Account::getFullname() << " or withdraw greater than 3000000\n";
    }
};

int main()
{
    Bank ACB("ACB", "TP Ho Chi Minh, Viet Nam");
    Account Huy("051201", "Huy");
    ACB.AddAccount(&Huy);
    Huy.deposit(1000000);
    Huy.withdraw(2000000);
    Huy.withdraw(500000);
    Account Khanh("051202", "Khanh");
    ACB.AddAccount(&Khanh);
    Khanh.deposit(1000000);
    Khanh.deposit(5000000);
    cout << '\n';

    cout << "Danh sach cac tai khoan cua ACB bank:\n";
    ACB.display();
    cout << '\n';

    cout << "Thong tin tai khoan giau nhat ACB bank:\n";
    ACB.getRichestAccount().display();
    cout << '\n';

    SubAccount Thu("051203", "Thu", &Huy);
    Thu.deposit(200000);
    Thu.withdraw(300000);
    cout << '\n';
    cout << "So du trong tai khoan cua Huy: " << Huy.getBalance();

    return 0;
}