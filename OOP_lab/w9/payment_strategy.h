#include <iostream>
#pragma once 
class PaymentStrategy
{
public:
    virtual void pay(double amount) = 0;
};

class CashPayment : public PaymentStrategy
{
public:
    void pay(double) override;
};
class ATMCardPayment : public PaymentStrategy
{
public:
    void pay(double) override;
};
class MomoPayment : public PaymentStrategy
{
public:
    void pay(double) override;
};
class ZaloPayPayment : public PaymentStrategy
{
public:
    void pay(double) override;
};