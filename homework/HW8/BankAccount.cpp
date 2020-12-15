#include "BankAccount.h"

BankAccount::BankAccount() : _name{ "John Appleseed" }, _balance{ 0 } {}
BankAccount::BankAccount(string name) : _name{ name }, _balance{ 0 } {}
BankAccount::BankAccount(string name, double balance) : _name { name }, _balance{ balance } {}

void BankAccount::deposit(const double n) 
{ 
	_balance += n; 
}

void BankAccount::withdrawal(const double n) 
{ 
	_s = _balance - n; 
	if (_s < 0)
	{
		cout << "Insufficient funds." << endl;
		return;
	}
	_balance = _s;
}

string BankAccount::getName() const { return _name; }
double BankAccount::getBalance() const { return _balance; }