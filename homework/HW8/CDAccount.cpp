#include "CDAccount.h"


CDAccount::CDAccount(string name, double interestrate) : BankAccount{ name }, _interestRate{ interestrate } {}
CDAccount::CDAccount(string name, double balance, double interestrate) : BankAccount { name, balance }, _interestRate{ interestrate } {}

void CDAccount::withdrawal(const double n)
{
	BankAccount::withdrawal(n + (0.25 * ((BankAccount::getBalance() * pow(2.71828, _interestRate)) - BankAccount::getBalance())));
}