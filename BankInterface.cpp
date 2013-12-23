#include "BankInterface.h"


BankInterface::BankInterface(void){}


BankInterface::~BankInterface(void){}

void BankInterface::Withdraw(int Amount,Account* account)
{
	account->Withdrow(Amount);
}
void BankInterface::Deposit(int Amount,Account* account)
{
	account->Deposit(Amount);
}

int BankInterface::WatchBalance( Account* account)
{
	return account->getBalance();
}
void BankInterface::Transfer(Account* TransferFromAccountId ,Account* TransferToAccountId , int Amount)
{
	TransferFromAccountId->Withdrow(Amount);
	TransferToAccountId->Deposit(Amount);
}
