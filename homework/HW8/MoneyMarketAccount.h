#pragma once
#include "BankAccount.h"

class MoneyMarketAccount : public BankAccount
{
private:
	unsigned _withdrawals;

public:
	MoneyMarketAccount();
	MoneyMarketAccount(string name);
	MoneyMarketAccount(string name, double balance);

	void withdrawal(const double n) override;
};

