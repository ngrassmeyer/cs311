#include <iostream>
#include "MoneyMarketAccount.h"
#include "CDAccount.h"

int main()
{
    MoneyMarketAccount m1{ "Noah", 10 };

    m1.withdrawal(1.0);
    m1.withdrawal(1.0);
    m1.withdrawal(9);

    cout << "$" << m1.getBalance() << endl << endl;

    CDAccount c1{ "Noah", 10, 0.05 };

    c1.withdrawal(5);

    cout << "$" << c1.getBalance() << endl;

    c1.withdrawal(5);

    cout << endl << endl;

    BankAccount* b = new BankAccount{ "Noah" , 10 };

    b->deposit(60);

    b->withdrawal(80);

    b->withdrawal(40);

    b->withdrawal(20);

    cout << b->getBalance() << endl << endl;    

    b = new MoneyMarketAccount{ "Noah", 10 };
    
    b->deposit(60);

    b->withdrawal(80);

    b->withdrawal(40);
    
    b->withdrawal(20);

    cout << b->getBalance() << endl << endl;   

    b = new CDAccount{ "Noah", 10, 0.05 };
    
    b->deposit(60);

    b->withdrawal(80);

    b->withdrawal(40);

    b->withdrawal(20);

    cout << b->getBalance() << endl << endl;

}
