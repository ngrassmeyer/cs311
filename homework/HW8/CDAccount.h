#pragma once

#include "BankAccount.h"

class CDAccount : public BankAccount
{
private:
	double _interestRate;

public:
	CDAccount() = delete;
	CDAccount(string name, double interestrate);
	CDAccount(string name, double balance, double interestrate);

	void withdrawal(const double n) override;
};

