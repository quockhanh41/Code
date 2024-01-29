#include "Product.h"
#include "Order.h"
#include "payment_strategy.h"
#include "Dragon.h"
#include "State.h"
#include <iostream>
using namespace std;
int main()
{
    // Bai 1 -----------------------------
    MomoPayment momo_payment;
    Order order(1, "khanh", "123456789", "quan1", &momo_payment);

    order.add_product(Product(1, "Product 1", 1000000, 2));
    order.add_product(Product(2, "Product 2", 500000, 1));

    order.process_order();

    // Bai 2-----------------------------

    Dragon a("Osiris", 10, 100, 50, 1000);
    a.setState(new RampageState);
    a.attack();
    a.setState(new NormalState);
    cout << endl;
    a.move();
    cout << endl;
    a.setState(new DefenseState);
    a.power();
    return 0;
}
