#include "MoneyMarketAccount.h"

MoneyMarketAccount::MoneyMarketAccount() : BankAccount{ }, _withdrawals{ 0 } {}
MoneyMarketAccount::MoneyMarketAccount(string name) : BankAccount{ name }, _withdrawals{ 0 } {}
MoneyMarketAccount::MoneyMarketAccount(string name, double balance) : BankAccount{ name, balance }, _withdrawals{ 0 } {}

void MoneyMarketAccount::withdrawal(const double n)
{
	if (_withdrawals > 1)
		BankAccount::withdrawal(n + 1.5);
	else
		BankAccount::withdrawal(n);

	_withdrawals++;
}