#include "ATMInterface.h"


ATMInterface::ATMInterface(void)
{
	RefillATM();
	BankDB* db = BankDB::getDB();
	//map<int,ATMAction*> ATMLog = db->ATMLog;

}

ATMInterface::~ATMInterface(void){}

void ATMInterface::RefillATM(void)
{
	Amount100 = 500;
	Amount50 = 500;
	Amount20 = 500;
}

void ATMInterface::DrowMoney(int Amount)
{
	if((Amount%20 != 0) &&  (Amount%50 != 0) &&  (Amount%100 != 70) &&  (Amount%100 != 90))
		throw exception(INVALID_AMOUNT);

	Amount100 = Amount100 - Amount/100;
	Amount -=  (Amount/100)*100;

	Amount50 = Amount50 - Amount/50;
	Amount -=  (Amount/50)*50;

	Amount20 = Amount20 - Amount/20;
	Amount -=  (Amount/20)*20;
}

int ATMInterface::getATMTotalAmount()
{
	return (Amount100 * 100) + (Amount50 * 50) + (Amount20 * 20);
}

void ATMInterface::Withdraw(int Amount,Account* AccountId)
{
	if(getATMTotalAmount() < Amount) // is There enought money in this ATM?
		throw exception(NO_MONEY_IN_ATM);
	//Actual Withdrow from the account
	__super::Withdraw(Amount,AccountId);

	// Decrese the bills Amount in the ATM
	DrowMoney(Amount);
	//Log this action
	this->ATMLogAction("1/1/10",Amount,true,AccountId,NULL); // TODO add the real date

}

void ATMInterface::Deposit (int Amount,Account*  AccountId)
{

	//Add deposit action to the action list and whit to teller approval
	this->ATMLogAction("1/1/10",Amount,false,NULL,AccountId); // TODO add the real date
}

int ATMInterface::WatchBalance(Account*  AccountId)
{
//	__super::getBalance();
	return 1;
}

void ATMInterface::Transfer(Account*  TransferFromAccountId , Account*  TransferToAccountId , int Amount)
{
	//Add deposit action to the action list and whit to teller approval
	this->ATMLogAction("1/1/10",Amount,false,TransferFromAccountId,TransferToAccountId ); // TODO add the real date
	
}

void ATMInterface::ATMLogAction(string date,int amount,bool aprooval,Account* TransferFromAccountId,Account* TransferToAccountId )
{
	ATMAction* actionToLog = new ATMAction(date,amount,aprooval,TransferFromAccountId,TransferToAccountId ); // TODO add the real date
	ATMLog.insert(std::pair<int,ATMAction*>(actionToLog->getActionId(),actionToLog));
}