#include "Account.h"
#include "ExpMsg.h"
#include <exception>

Account::Account(float comission,int credit): Credit((credit)),
					LineCommission(comission),
					OpeningDate()
{
	
	static int s_Id = 1; // TODO Make bank account string in format XXXX ?
    Id = s_Id++;
	// Make Card id whith unic id number and randoum password
	creditCard =  new CreditCard(rand()%1000000 + 1000000*Id );
	Balance = 0;
	
	
}

void Account::setNewCreditCard(int Pass)
{
//	CreditCard.setPassword(Pass);
	//CreditCard.setId(Id);
rand();
}


void Account::setBalance(double NewBalance){
	
	Balance = NewBalance;
}
double Account::getBalance(){ return Balance;}

int Account::getAccountId(void)
{
	return Id;
}

void Account::Deposit(int AmuontDeposit)
{
	if(!IsAccountActive())
		throw exception(ACCOUNT_IS_NOT_ACTIVE);
	double NewBalance = getBalance() + AmuontDeposit - LineCommission;
	if(NewBalance < Credit)
		throw exception(ACCOUNT_HAVE_NO_MONEY);
	setBalance(NewBalance);
	
}
void Account::Withdrow(int Amuont)
{
	if(!IsAccountActive())
		throw exception(ACCOUNT_IS_NOT_ACTIVE);
	
	double NewBalance = getBalance() - Amuont - LineCommission;
	
	if(NewBalance < Credit)
		throw exception(ACCOUNT_HAVE_NO_MONEY);
	setBalance(NewBalance);
}



void Account::Transfer(Account* TransferToAccountId,int Amount)
{
	if(!TransferToAccountId->IsAccountActive())
		throw exception(ACCOUNT_TRANSFER_TO_IS_NOT_ACTIVE);

	this->Withdrow(Amount);
	TransferToAccountId->Deposit(Amount);
}


bool Account::IsAccountActive(void)
{
	return IsActive;
}

void Account::CloseAccount(void)
{	
	IsActive = false;
}

