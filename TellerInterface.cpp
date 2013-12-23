#include "TellerInterface.h"
#include <string>
using namespace std;

TellerInterface::TellerInterface(void)
{
	bankDB = BankDB::getDB();
}


TellerInterface::~TellerInterface(void)
{
}

void TellerInterface::CreateNewClient(string* Details)
{	
	//Client (id,name,birthdate,phonenumber,address) - all strings
	Client* NewClient = new Client(Details[0],Details[1],Details[2],Details[3],Details[4]);
	bankDB->insertClient(Details[0],NewClient);
}

void TellerInterface::RefillATM(ATMInterface* ATM)
{
	ATM->RefillATM();
}

void TellerInterface::AddNewAccount(enum AccountTypes AccountType, Client* client)
{



	Account* account;
	switch(AccountType)
	{
		case Student:
			account = new StudentAccount();
		break;

		case Private:
			account = new PrivateAccount();
		break;

		case Business:
			account = new BusinessAccount();
		break;
	}

}


void CloseAccount(Account* account)
{
	if(!account->IsAccountActive())
		throw exception(ACCOUNT_IS_NOT_ACTIVE);

	if( account->getBalance() != 0)
		throw exception(BALANCE_IS_NOT_ZERO);

	account->CloseAccount();
}