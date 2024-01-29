#include "payment_strategy.h"


void CashPayment::pay(double amount) 
{
    std::cout << "Da thanh toan " << amount << " VND bang tien mat" << std::endl;
}

void ATMCardPayment::pay(double amount)
{
    std::cout << "Da thanh toan " << amount << " VND bang the ATM" << std::endl;
}

void MomoPayment::pay(double amount)
{
    std::cout << "Da thanh toan " << amount << " VND bang vi MOMO" << std::endl;
}

void ZaloPayPayment::pay(double amount)
{
    std::cout << "Da thanh toan " << amount << " VND bang ZaloPay" << std::endl;
}
