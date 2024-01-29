#include <iostream>
#include <vector>
using namespace std;
class Customer
{
private:
    string name;
    string ID;
    string address;

public:
    Customer(){};
    Customer(string name, string ID, string address)
    {
        this->address = address;
        this->ID = ID;
        this->name = name;
    };
    string getName() { return name; }
};
class Contract
{
private:
    Customer customer;
    int callingTime;
    int data;

public:
    Contract(Customer customer, int callingTime, int data)
    {
        this->customer = customer;
        this->callingTime = callingTime;
        this->data = data;
    };
    string getCustomerName()
    {
        return customer.getName();
    }
    double getData() { return data; }
    double GetCallingTime() { return callingTime; }
    virtual double getPhoneCharge() = 0;
    virtual double getInternetCharge() = 0;
    double getTotalCharge()
    {
        return (getPhoneCharge() + getInternetCharge()) * 1.1;
    }
};

class BasicContract : public Contract
{
public:
    BasicContract(Customer customer, int callingTime, int data) : Contract(customer, callingTime, data){};
    double getPhoneCharge() override
    {
        return GetCallingTime() * 1000;
    }
    double getInternetCharge() override
    {
        return getData() * 200;
    }
};
class FreeDataContract : public Contract
{
private:
    int capacityData;

public:
    FreeDataContract(Customer customer, int callingTime, int data, int capacityData) : Contract(customer, callingTime, data) { this->capacityData = capacityData; };
    double getInternetCharge() override
    {
        if (getData() <= capacityData)
            return 0;
        return (getData() - capacityData) * 200;
    }
    double getPhoneCharge() override
    {
        return GetCallingTime() * 1000;
    }
};
class FixedDataContract : public Contract
{

public:
    FixedDataContract(Customer customer, int callingTime, int data) : Contract(customer, callingTime, data){};
    double getInternetCharge() override
    {
        return 1000000;
    }
    double getPhoneCharge() override
    {
        return GetCallingTime() * 1000 * 0.9;
    }
};
class ContractManage
{
private:
    vector<Contract *> listContract;

public:
    ContractManage(){};
    ContractManage(vector<Contract *> listContract) { this->listContract = listContract; };
    void addContract(Contract *newContract)
    {
        listContract.push_back(newContract);
    }
    void display()
    {
        for (auto x : listContract)
        {
            cout << x->getCustomerName() << " " << x->getTotalCharge() << endl;
        }
    }
};

int main()
{
    Customer khanh("Khanh", "051204001884", "HCMUS");
    Customer khanh1("Khanh1", "051204001884", "HCMUS");
    BasicContract c1(khanh, 30, 1024);
    BasicContract c2(khanh1, 100, 4096);
    ContractManage m;
    m.addContract(&c1);
    m.addContract(&c2);
    m.display();
    return 0;
}