#pragma once
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class BankAccount
{
private:
	string _name;
	double _balance;

	double _s = 0;

public:
	BankAccount();
	BankAccount(string name);
	BankAccount(string name, double balance);

	void deposit(const double n);
	virtual void withdrawal(const double n);

	string getName() const;
	double getBalance() const;
};

